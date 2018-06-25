#!/usr/bin/env python3.5

"""
NRF5 reverse tool using IDA-python
"""
import sqlite3
import idaapi
import idc

def launch_print():
    """print message"""
    print("############################ nRF5-tool ############################ ")
    print("#####                                                         ##### ")
    print("#####         IDA python-Reversing nRF5x binaries             ##### ")
    print("#####                                                         ##### ")
    print("################################################################### ")
    print("\n")

class NRF5xReverse(object):
    """
    nRF5x reverse class initiates objects with the softdevice's signature
    renames all syscalls in IDA
    """
    def __init__(self, nRFv_path, nRF_db):
        """
        Database initialisation
        """
        self.nrf_db = nRF_db
        self.con = sqlite3.connect(self.nrf_db)
        self.cur = self.con.cursor()
        self.svc_addr = dict()
        self.svc_count = dict()
        self.structs = []
        self.types = {"int8_t":"__int8", "int16_t": "__int16", "int32_t": "__int32", "int64_t":"__int64", "int128_t":"__int128"}
        with open(nRFv_path, "r") as nrf_file:
            self.sign = nrf_file.read()

    def extract_syscalls(self):
        """
        Extracts SVC from ASM to self.svc_addr
        Condition met in ASM : SVC 0xnum
        Retrieves syscall number called (SVC 0xnum => 0xnum syscall) at svc_addr
        """
        for segea in Segments():
            for head in Heads(segea, SegEnd(segea)):
                if isCode(GetFlags(head)):
                    mnem = GetMnem(head)
                    if mnem == "SVC":
                        syscall = GetOpnd(head, 0)
                        self.svc_addr[head] = syscall

    def count_svcs(self):
        """
        Detects same svcs in different sub_addresses
        """
        for k, v in self.svc_addr.items():
            self.svc_count[v] = self.svc_count.get(v, 0) + 1
    def resolve_svcs(self):
        """
        Resolves svcs in binary
        """
        for addr, syscall in self.svc_addr.items():
            req = "select distinct(svc) from SVCALL where LOWER(syscall)=LOWER(?) and softdev_signature LIKE ?"
            self.cur.execute(req, (syscall, self.sign))
            svc = self.cur.fetchall()
            if len(svc) != 1:
                print("No SVC identified or SoftDevice version must be specified\n", syscall, self.sign)
            else:
                svcall = SVCALL(self.sign, self.cur, addr, syscall, self.svc_count[syscall])
                svcall.rename(self.types)

    def get_structs(self):
        """
        Extracts structures from nRF.db
        """
        self.structs = dict() 
        req = "select distinct(name) from Structures where softdev_signature LIKE ?"
        self.cur.execute(req, (self.sign, ))
        structs = self.cur.fetchall()
        print(structs)
        for struct in structs:
            req1 = "select distinct(arg_name) from StructArgs where struct_name=? and softdev_signature LIKE ?"
            self.cur.execute(req1, (struct[0], self.sign))
            struct_args = self.cur.fetchall()
            self.structs[struct[0]] = struct_args

    def add_struc(self):
        """
        Adds structures to IDA
        """
        print("## Structures ##")
        structs = dict()
        idx = idaapi.get_last_struc_idx()
        print(idx, self.structs)
        idaapi.add_struc(idx, str(next(iter(self.structs))))
        for structure, args in self.structs.items():
            idx = idaapi.get_next_struc_idx(idx)
            struct_id = idaapi.get_struc_by_idx(idx)
            struct_name = str(structure)
            idaapi.add_struc(idx, struct_name)
            self.types[struct_name] = struct_name

    def add_strucmem(self):
        """
        Adds structures'members
        """
        idx = idaapi.get_last_struc_idx()
        for structure, args in self.structs.items():
            struct_name = str(structure)
            sid = idc.GetStrucIdByName(struct_name)
            mem_cmt = ""
            for struct_arg in args:
                if "union" in struct_arg[0]:
                    print(struct_arg[0])
                    union = struct_arg[0].replace("union ", "")
                    union_name = union.split("(")[0]
                    union_members = union.split("(")[1].replace(")", "").rsplit(",")
                    uid = idaapi.get_next_struc_idx(idx)
                    idaapi.add_struc(uid, str(union_name), 1)
                    for union_member in union_members:
                        if len(union_member.split(" ")) > 1 :
                            print(union_member)
                            member_name = str(union_member.split(" ")[1])
                            member_type = str(union_member.split(" ")[0])
                            member_id = idc.GetStrucIdByName(member_type)
                            member_size = idc.GetStrucSize(member_id)
                            print(uid, union_name, member_type, member_name, member_size)
                            idc.AddStrucMember(uid, member_name, -1, idc.FF_DWRD, -1, member_size)
                member = struct_arg[0].split(" ")[1].split("(")[0]
                member_type = struct_arg[0].split(" ")[0]
                mem_cmt += struct_arg[0] + "|"
                idc.AddStrucMember(sid, str(member), -1, idc.FF_DWRD, -1, 8)
            struct_cmt = "STRUCTURE " + struct_name + " contains " + mem_cmt
            idaapi.set_struc_cmt(sid, str(struct_cmt), False)

class SVCALL():
    """
    SVCALL class initiates svc object associated to an address in IDA
    sets function names and prototypes
    """
    def __init__(self, softdev_sign, cur, addr, syscall, syscall_cnt):
        self.cur = cur
        self.addr = addr
        self.syscall = syscall
        self.syscall_cnt = syscall_cnt
        req = "select distinct(svc), function, ret_type, arguments from SVCALL where LOWER(syscall)=LOWER(?) and softdev_signature LIKE ?"
        self.cur.execute(req, (syscall, softdev_sign))
        #checking if syscall has same number of arguments for different softdevices given the approximative signature
        res1 = self.cur.fetchall()
        if len(res1) != 1:
            self.args_len = len(res1[0][3].rsplit(",")) 
            for i in range(len(res1)):
                args_1 = res1[i][3]
                if len(args_1.rsplit(",")) != self.args_len:
                    print('number of arguments is different for softdevices, SYSCALL:', self.syscall)
                    print(args_1, len(args_1.rsplit(",")))
                    print(res1[0][3], self.args_len)
        req = "select distinct(svc), function, ret_type, arguments from SVCALL where LOWER(syscall)=LOWER(?) and softdev_signature LIKE ?"
        self.cur.execute(req, (syscall, softdev_sign))
        res = self.cur.fetchone()
        self.svc = res[0]
        self.function = str(res[1])
        self.ret_type = res[2]
        self.args = res[3]
    def set_funcname(self):
        if self.syscall_cnt > 1:
            comment = "contains " + str(self.function) + "'function code. Same declaration at "
            comment += str(self.syscall_cnt) + " different addresses"
            self.function += "_" + str(hex(self.addr)).replace("0x", "") + "_" + str(self.syscall_cnt)
        else:
            self.function = str(self.function)
            comment = str(self.function)
        MakeComm(self.addr, comment)
        MakeNameEx(self.addr, self.function, SN_NOWARN)
    def rename(self, types):
        """
        Sets prototypes and names to functions in IDA
        """
        try:
            if "uint" in self.args:
                self.args = self.args.replace("uint", "unsigned int")
            args_an = self.args.rsplit(" ")
            for item in args_an:
                if "_t" in item or "IRQn_Type" in item:
                    if item in types:
                        #print("known type", item)
                        self.args = self.args.replace(item, types[item])
                    elif "IRQn_Type" in item:
                        #int is a temporary value before getting structures from parsing SDKs
                        unknown_type = "IRQn_Type"
                        self.args = self.args.replace(unknown_type, "int __struct_ptr")
                        print("IRQN", self.addr, self.function, self.args)
            self.args = "(" + self.args + ");"
            self.set_funcname()
            newtype = "unsigned __int32 "+ str(self.function) + str(self.args)
            SetType(self.addr, str(newtype))
        except IOError:
            pass

    def apply_struct(self, sid):
        """
        Applies structures on arguments
        """
        size = idc.GetStrucSize(sid)
        idc.MaleUnknown(self.addr, size, idc.DOUNK_DELNAMES)
        idaapi.doStruct(self.addr, size, sid)

def main():
    """
    main
    """
    launch_print()
    nrf_sign = "./nRF_ver"
    nrf_db = "./nRF.db"
    nrf = NRF5xReverse(nrf_sign, nrf_db)
    nrf.get_structs()
    nrf.add_struc()
    nrf.add_strucmem()
    nrf.extract_syscalls()
    nrf.count_svcs()
    nrf.resolve_svcs()
    nrf.con.close()

if __name__ == "__main__":
    main()
