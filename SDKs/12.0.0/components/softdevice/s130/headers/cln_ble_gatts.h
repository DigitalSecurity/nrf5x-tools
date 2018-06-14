#ifndef BLE_GATTS_H__
#define BLE_GATTS_H__ 
#include "ble_types.h"
#include "ble_ranges.h"
#include "ble_l2cap.h"
#include "ble_gap.h"
#include "ble_gatt.h"
#include "nrf_svc.h"
#ifdef __cplusplus
extern "C" {
#endif
enum BLE_GATTS_SVCS
{
  SD_BLE_GATTS_SERVICE_ADD = BLE_GATTS_SVC_BASE,
  SD_BLE_GATTS_INCLUDE_ADD,
  SD_BLE_GATTS_CHARACTERISTIC_ADD,
  SD_BLE_GATTS_DESCRIPTOR_ADD,
  SD_BLE_GATTS_VALUE_SET,
  SD_BLE_GATTS_VALUE_GET,
  SD_BLE_GATTS_HVX,
  SD_BLE_GATTS_SERVICE_CHANGED,
  SD_BLE_GATTS_RW_AUTHORIZE_REPLY,
  SD_BLE_GATTS_SYS_ATTR_SET,
  SD_BLE_GATTS_SYS_ATTR_GET,
  SD_BLE_GATTS_INITIAL_USER_HANDLE_GET,
  SD_BLE_GATTS_ATTR_GET
};
enum BLE_GATTS_EVTS
{
  BLE_GATTS_EVT_WRITE = BLE_GATTS_EVT_BASE,
  BLE_GATTS_EVT_RW_AUTHORIZE_REQUEST,
  BLE_GATTS_EVT_SYS_ATTR_MISSING,
  BLE_GATTS_EVT_HVC,
  BLE_GATTS_EVT_SC_CONFIRM,
  BLE_GATTS_EVT_TIMEOUT
};
#define BLE_ERROR_GATTS_INVALID_ATTR_TYPE (NRF_GATTS_ERR_BASE + 0x000)
#define BLE_ERROR_GATTS_SYS_ATTR_MISSING (NRF_GATTS_ERR_BASE + 0x001)
#define BLE_GATTS_FIX_ATTR_LEN_MAX (510)
#define BLE_GATTS_VAR_ATTR_LEN_MAX (512)
#define BLE_GATTS_SRVC_TYPE_INVALID 0x00
#define BLE_GATTS_SRVC_TYPE_PRIMARY 0x01
#define BLE_GATTS_SRVC_TYPE_SECONDARY 0x02
#define BLE_GATTS_ATTR_TYPE_INVALID 0x00
#define BLE_GATTS_ATTR_TYPE_PRIM_SRVC_DECL 0x01
#define BLE_GATTS_ATTR_TYPE_SEC_SRVC_DECL 0x02
#define BLE_GATTS_ATTR_TYPE_INC_DECL 0x03
#define BLE_GATTS_ATTR_TYPE_CHAR_DECL 0x04
#define BLE_GATTS_ATTR_TYPE_CHAR_VAL 0x05
#define BLE_GATTS_ATTR_TYPE_DESC 0x06
#define BLE_GATTS_ATTR_TYPE_OTHER 0x07
#define BLE_GATTS_OP_INVALID 0x00
#define BLE_GATTS_OP_WRITE_REQ 0x01
#define BLE_GATTS_OP_WRITE_CMD 0x02
#define BLE_GATTS_OP_SIGN_WRITE_CMD 0x03
#define BLE_GATTS_OP_PREP_WRITE_REQ 0x04
#define BLE_GATTS_OP_EXEC_WRITE_REQ_CANCEL 0x05
#define BLE_GATTS_OP_EXEC_WRITE_REQ_NOW 0x06
#define BLE_GATTS_VLOC_INVALID 0x00
#define BLE_GATTS_VLOC_STACK 0x01
#define BLE_GATTS_VLOC_USER 0x02
#define BLE_GATTS_AUTHORIZE_TYPE_INVALID 0x00
#define BLE_GATTS_AUTHORIZE_TYPE_READ 0x01
#define BLE_GATTS_AUTHORIZE_TYPE_WRITE 0x02
#define BLE_GATTS_SYS_ATTR_FLAG_SYS_SRVCS (1 << 0)
#define BLE_GATTS_SYS_ATTR_FLAG_USR_SRVCS (1 << 1)
#define BLE_GATTS_ATTR_TAB_SIZE_MIN 216
#define BLE_GATTS_ATTR_TAB_SIZE_DEFAULT 0x0000
typedef struct
{
  uint8_t service_changed:1;
  uint32_t attr_tab_size;
} ble_gatts_enable_params_t;
typedef struct
{
  ble_gap_conn_sec_mode_t read_perm;
  ble_gap_conn_sec_mode_t write_perm;
  uint8_t vlen :1;
  uint8_t vloc :2;
  uint8_t rd_auth :1;
  uint8_t wr_auth :1;
} ble_gatts_attr_md_t;
typedef struct
{
  ble_uuid_t *p_uuid;
  ble_gatts_attr_md_t *p_attr_md;
  uint16_t init_len;
  uint16_t init_offs;
  uint16_t max_len;
  uint8_t* p_value;
} ble_gatts_attr_t;
typedef struct
{
  uint16_t len;
  uint16_t offset;
  uint8_t *p_value;
} ble_gatts_value_t;
typedef struct
{
  uint8_t format;
  int8_t exponent;
  uint16_t unit;
  uint8_t name_space;
  uint16_t desc;
} ble_gatts_char_pf_t;
typedef struct
{
  ble_gatt_char_props_t char_props;
  ble_gatt_char_ext_props_t char_ext_props;
  uint8_t *p_char_user_desc;
  uint16_t char_user_desc_max_size;
  uint16_t char_user_desc_size;
  ble_gatts_char_pf_t* p_char_pf;
  ble_gatts_attr_md_t* p_user_desc_md;
  ble_gatts_attr_md_t* p_cccd_md;
  ble_gatts_attr_md_t* p_sccd_md;
} ble_gatts_char_md_t;
typedef struct
{
  uint16_t value_handle;
  uint16_t user_desc_handle;
  uint16_t cccd_handle;
  uint16_t sccd_handle;
} ble_gatts_char_handles_t;
typedef struct
{
  uint16_t handle;
  uint8_t type;
  uint16_t offset;
  uint16_t *p_len;
  uint8_t *p_data;
} ble_gatts_hvx_params_t;
typedef struct
{
  uint16_t gatt_status;
  uint8_t update : 1;
  uint16_t offset;
  uint16_t len;
  const uint8_t *p_data;
} ble_gatts_authorize_params_t;
typedef struct
{
  uint8_t type;
  union {
    ble_gatts_authorize_params_t read;
    ble_gatts_authorize_params_t write;
  } params;
} ble_gatts_rw_authorize_reply_params_t;
typedef struct
{
  uint16_t handle;
  ble_uuid_t uuid;
  uint8_t op;
  uint8_t auth_required;
  uint16_t offset;
  uint16_t len;
  uint8_t data[1];
} ble_gatts_evt_write_t;
typedef struct
{
  uint16_t handle;
  ble_uuid_t uuid;
  uint16_t offset;
} ble_gatts_evt_read_t;
typedef struct
{
  uint8_t type;
  union {
    ble_gatts_evt_read_t read;
    ble_gatts_evt_write_t write;
  } request;
} ble_gatts_evt_rw_authorize_request_t;
typedef struct
{
  uint8_t hint;
} ble_gatts_evt_sys_attr_missing_t;
typedef struct
{
  uint16_t handle;
} ble_gatts_evt_hvc_t;
typedef struct
{
  uint8_t src;
} ble_gatts_evt_timeout_t;
typedef struct
{
  uint16_t conn_handle;
  union
  {
    ble_gatts_evt_write_t write;
    ble_gatts_evt_rw_authorize_request_t authorize_request;
    ble_gatts_evt_sys_attr_missing_t sys_attr_missing;
    ble_gatts_evt_hvc_t hvc;
    ble_gatts_evt_timeout_t timeout;
  } params;
} ble_gatts_evt_t;
SVCALL(SD_BLE_GATTS_SERVICE_ADD, uint32_t, sd_ble_gatts_service_add(uint8_t type, ble_uuid_t const *p_uuid, uint16_t *p_handle));
SVCALL(SD_BLE_GATTS_INCLUDE_ADD, uint32_t, sd_ble_gatts_include_add(uint16_t service_handle, uint16_t inc_srvc_handle, uint16_t *p_include_handle));
SVCALL(SD_BLE_GATTS_CHARACTERISTIC_ADD, uint32_t, sd_ble_gatts_characteristic_add(uint16_t service_handle, ble_gatts_char_md_t const *p_char_md, ble_gatts_attr_t const *p_attr_char_value, ble_gatts_char_handles_t *p_handles));
SVCALL(SD_BLE_GATTS_DESCRIPTOR_ADD, uint32_t, sd_ble_gatts_descriptor_add(uint16_t char_handle, ble_gatts_attr_t const *p_attr, uint16_t *p_handle));
SVCALL(SD_BLE_GATTS_VALUE_SET, uint32_t, sd_ble_gatts_value_set(uint16_t conn_handle, uint16_t handle, ble_gatts_value_t *p_value));
SVCALL(SD_BLE_GATTS_VALUE_GET, uint32_t, sd_ble_gatts_value_get(uint16_t conn_handle, uint16_t handle, ble_gatts_value_t *p_value));
SVCALL(SD_BLE_GATTS_HVX, uint32_t, sd_ble_gatts_hvx(uint16_t conn_handle, ble_gatts_hvx_params_t const *p_hvx_params));
SVCALL(SD_BLE_GATTS_SERVICE_CHANGED, uint32_t, sd_ble_gatts_service_changed(uint16_t conn_handle, uint16_t start_handle, uint16_t end_handle));
SVCALL(SD_BLE_GATTS_RW_AUTHORIZE_REPLY, uint32_t, sd_ble_gatts_rw_authorize_reply(uint16_t conn_handle, ble_gatts_rw_authorize_reply_params_t const *p_rw_authorize_reply_params));
SVCALL(SD_BLE_GATTS_SYS_ATTR_SET, uint32_t, sd_ble_gatts_sys_attr_set(uint16_t conn_handle, uint8_t const *p_sys_attr_data, uint16_t len, uint32_t flags));
SVCALL(SD_BLE_GATTS_SYS_ATTR_GET, uint32_t, sd_ble_gatts_sys_attr_get(uint16_t conn_handle, uint8_t *p_sys_attr_data, uint16_t *p_len, uint32_t flags));
SVCALL(SD_BLE_GATTS_INITIAL_USER_HANDLE_GET, uint32_t, sd_ble_gatts_initial_user_handle_get(uint16_t *p_handle));
SVCALL(SD_BLE_GATTS_ATTR_GET, uint32_t, sd_ble_gatts_attr_get(uint16_t handle, ble_uuid_t * p_uuid, ble_gatts_attr_md_t * p_md));
#ifdef __cplusplus
}
#endif
#endif
