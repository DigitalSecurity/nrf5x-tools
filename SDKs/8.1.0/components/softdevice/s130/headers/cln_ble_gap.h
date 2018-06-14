#ifndef BLE_GAP_H__
#define BLE_GAP_H__ 
#include "ble_types.h"
#include "ble_ranges.h"
#include "nrf_svc.h"
enum BLE_GAP_SVCS
{
  SD_BLE_GAP_ADDRESS_SET = BLE_GAP_SVC_BASE,
  SD_BLE_GAP_ADDRESS_GET,
  SD_BLE_GAP_ADV_DATA_SET,
  SD_BLE_GAP_ADV_START,
  SD_BLE_GAP_ADV_STOP,
  SD_BLE_GAP_CONN_PARAM_UPDATE,
  SD_BLE_GAP_DISCONNECT,
  SD_BLE_GAP_TX_POWER_SET,
  SD_BLE_GAP_APPEARANCE_SET,
  SD_BLE_GAP_APPEARANCE_GET,
  SD_BLE_GAP_PPCP_SET,
  SD_BLE_GAP_PPCP_GET,
  SD_BLE_GAP_DEVICE_NAME_SET,
  SD_BLE_GAP_DEVICE_NAME_GET,
  SD_BLE_GAP_AUTHENTICATE,
  SD_BLE_GAP_SEC_PARAMS_REPLY,
  SD_BLE_GAP_AUTH_KEY_REPLY,
  SD_BLE_GAP_ENCRYPT,
  SD_BLE_GAP_SEC_INFO_REPLY,
  SD_BLE_GAP_CONN_SEC_GET,
  SD_BLE_GAP_RSSI_START,
  SD_BLE_GAP_RSSI_STOP,
  SD_BLE_GAP_SCAN_START,
  SD_BLE_GAP_SCAN_STOP,
  SD_BLE_GAP_CONNECT,
  SD_BLE_GAP_CONNECT_CANCEL,
  SD_BLE_GAP_RSSI_GET,
};
enum BLE_GAP_EVTS
{
  BLE_GAP_EVT_CONNECTED = BLE_GAP_EVT_BASE,
  BLE_GAP_EVT_DISCONNECTED,
  BLE_GAP_EVT_CONN_PARAM_UPDATE,
  BLE_GAP_EVT_SEC_PARAMS_REQUEST,
  BLE_GAP_EVT_SEC_INFO_REQUEST,
  BLE_GAP_EVT_PASSKEY_DISPLAY,
  BLE_GAP_EVT_AUTH_KEY_REQUEST,
  BLE_GAP_EVT_AUTH_STATUS,
  BLE_GAP_EVT_CONN_SEC_UPDATE,
  BLE_GAP_EVT_TIMEOUT,
  BLE_GAP_EVT_RSSI_CHANGED,
  BLE_GAP_EVT_ADV_REPORT,
  BLE_GAP_EVT_SEC_REQUEST,
  BLE_GAP_EVT_CONN_PARAM_UPDATE_REQUEST,
  BLE_GAP_EVT_SCAN_REQ_REPORT,
};
enum BLE_GAP_OPTS
{
  BLE_GAP_OPT_CH_MAP = BLE_GAP_OPT_BASE,
  BLE_GAP_OPT_LOCAL_CONN_LATENCY,
  BLE_GAP_OPT_PASSKEY,
  BLE_GAP_OPT_PRIVACY,
  BLE_GAP_OPT_SCAN_REQ_REPORT,
  BLE_GAP_OPT_COMPAT_MODE
};
#define BLE_ERROR_GAP_UUID_LIST_MISMATCH (NRF_GAP_ERR_BASE + 0x000)
#define BLE_ERROR_GAP_DISCOVERABLE_WITH_WHITELIST (NRF_GAP_ERR_BASE + 0x001)
#define BLE_ERROR_GAP_INVALID_BLE_ADDR (NRF_GAP_ERR_BASE + 0x002)
#define BLE_ERROR_GAP_WHITELIST_IN_USE (NRF_GAP_ERR_BASE + 0x003)
#define BLE_GAP_ROLE_INVALID 0x0
#define BLE_GAP_ROLE_PERIPH 0x1
#define BLE_GAP_ROLE_CENTRAL 0x2
#define BLE_GAP_TIMEOUT_SRC_ADVERTISING 0x00
#define BLE_GAP_TIMEOUT_SRC_SECURITY_REQUEST 0x01
#define BLE_GAP_TIMEOUT_SRC_SCAN 0x02
#define BLE_GAP_TIMEOUT_SRC_CONN 0x03
#define BLE_GAP_ADDR_TYPE_PUBLIC 0x00
#define BLE_GAP_ADDR_TYPE_RANDOM_STATIC 0x01
#define BLE_GAP_ADDR_TYPE_RANDOM_PRIVATE_RESOLVABLE 0x02
#define BLE_GAP_ADDR_TYPE_RANDOM_PRIVATE_NON_RESOLVABLE 0x03
#define BLE_GAP_ADDR_CYCLE_MODE_NONE 0x00
#define BLE_GAP_ADDR_CYCLE_MODE_AUTO 0x01
#define BLE_GAP_DEFAULT_PRIVATE_ADDR_CYCLE_INTERVAL_S (60 * 15)
#define BLE_GAP_ADDR_LEN 6
#define BLE_GAP_AD_TYPE_FLAGS 0x01
#define BLE_GAP_AD_TYPE_16BIT_SERVICE_UUID_MORE_AVAILABLE 0x02
#define BLE_GAP_AD_TYPE_16BIT_SERVICE_UUID_COMPLETE 0x03
#define BLE_GAP_AD_TYPE_32BIT_SERVICE_UUID_MORE_AVAILABLE 0x04
#define BLE_GAP_AD_TYPE_32BIT_SERVICE_UUID_COMPLETE 0x05
#define BLE_GAP_AD_TYPE_128BIT_SERVICE_UUID_MORE_AVAILABLE 0x06
#define BLE_GAP_AD_TYPE_128BIT_SERVICE_UUID_COMPLETE 0x07
#define BLE_GAP_AD_TYPE_SHORT_LOCAL_NAME 0x08
#define BLE_GAP_AD_TYPE_COMPLETE_LOCAL_NAME 0x09
#define BLE_GAP_AD_TYPE_TX_POWER_LEVEL 0x0A
#define BLE_GAP_AD_TYPE_CLASS_OF_DEVICE 0x0D
#define BLE_GAP_AD_TYPE_SIMPLE_PAIRING_HASH_C 0x0E
#define BLE_GAP_AD_TYPE_SIMPLE_PAIRING_RANDOMIZER_R 0x0F
#define BLE_GAP_AD_TYPE_SECURITY_MANAGER_TK_VALUE 0x10
#define BLE_GAP_AD_TYPE_SECURITY_MANAGER_OOB_FLAGS 0x11
#define BLE_GAP_AD_TYPE_SLAVE_CONNECTION_INTERVAL_RANGE 0x12
#define BLE_GAP_AD_TYPE_SOLICITED_SERVICE_UUIDS_16BIT 0x14
#define BLE_GAP_AD_TYPE_SOLICITED_SERVICE_UUIDS_128BIT 0x15
#define BLE_GAP_AD_TYPE_SERVICE_DATA 0x16
#define BLE_GAP_AD_TYPE_PUBLIC_TARGET_ADDRESS 0x17
#define BLE_GAP_AD_TYPE_RANDOM_TARGET_ADDRESS 0x18
#define BLE_GAP_AD_TYPE_APPEARANCE 0x19
#define BLE_GAP_AD_TYPE_ADVERTISING_INTERVAL 0x1A
#define BLE_GAP_AD_TYPE_LE_BLUETOOTH_DEVICE_ADDRESS 0x1B
#define BLE_GAP_AD_TYPE_LE_ROLE 0x1C
#define BLE_GAP_AD_TYPE_SIMPLE_PAIRING_HASH_C256 0x1D
#define BLE_GAP_AD_TYPE_SIMPLE_PAIRING_RANDOMIZER_R256 0x1E
#define BLE_GAP_AD_TYPE_SERVICE_DATA_32BIT_UUID 0x20
#define BLE_GAP_AD_TYPE_SERVICE_DATA_128BIT_UUID 0x21
#define BLE_GAP_AD_TYPE_3D_INFORMATION_DATA 0x3D
#define BLE_GAP_AD_TYPE_MANUFACTURER_SPECIFIC_DATA 0xFF
#define BLE_GAP_ADV_FLAG_LE_LIMITED_DISC_MODE (0x01)
#define BLE_GAP_ADV_FLAG_LE_GENERAL_DISC_MODE (0x02)
#define BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED (0x04)
#define BLE_GAP_ADV_FLAG_LE_BR_EDR_CONTROLLER (0x08)
#define BLE_GAP_ADV_FLAG_LE_BR_EDR_HOST (0x10)
#define BLE_GAP_ADV_FLAGS_LE_ONLY_LIMITED_DISC_MODE (BLE_GAP_ADV_FLAG_LE_LIMITED_DISC_MODE | BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED)
#define BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE (BLE_GAP_ADV_FLAG_LE_GENERAL_DISC_MODE | BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED)
#define BLE_GAP_ADV_INTERVAL_MIN 0x0020
#define BLE_GAP_ADV_NONCON_INTERVAL_MIN 0x00A0
#define BLE_GAP_ADV_INTERVAL_MAX 0x4000
#define BLE_GAP_SCAN_INTERVAL_MIN 0x0004
#define BLE_GAP_SCAN_INTERVAL_MAX 0x4000
#define BLE_GAP_SCAN_WINDOW_MIN 0x0004
#define BLE_GAP_SCAN_WINDOW_MAX 0x4000
#define BLE_GAP_SCAN_TIMEOUT_MIN 0x0001
#define BLE_GAP_SCAN_TIMEOUT_MAX 0xFFFF
#define BLE_GAP_ADV_MAX_SIZE 31
#define BLE_GAP_ADV_TYPE_ADV_IND 0x00
#define BLE_GAP_ADV_TYPE_ADV_DIRECT_IND 0x01
#define BLE_GAP_ADV_TYPE_ADV_SCAN_IND 0x02
#define BLE_GAP_ADV_TYPE_ADV_NONCONN_IND 0x03
#define BLE_GAP_ADV_FP_ANY 0x00
#define BLE_GAP_ADV_FP_FILTER_SCANREQ 0x01
#define BLE_GAP_ADV_FP_FILTER_CONNREQ 0x02
#define BLE_GAP_ADV_FP_FILTER_BOTH 0x03
#define BLE_GAP_ADV_TIMEOUT_LIMITED_MAX 180
#define BLE_GAP_ADV_TIMEOUT_GENERAL_UNLIMITED 0
#define BLE_GAP_DISC_MODE_NOT_DISCOVERABLE 0x00
#define BLE_GAP_DISC_MODE_LIMITED 0x01
#define BLE_GAP_DISC_MODE_GENERAL 0x02
#define BLE_GAP_IO_CAPS_DISPLAY_ONLY 0x00
#define BLE_GAP_IO_CAPS_DISPLAY_YESNO 0x01
#define BLE_GAP_IO_CAPS_KEYBOARD_ONLY 0x02
#define BLE_GAP_IO_CAPS_NONE 0x03
#define BLE_GAP_IO_CAPS_KEYBOARD_DISPLAY 0x04
#define BLE_GAP_AUTH_KEY_TYPE_NONE 0x00
#define BLE_GAP_AUTH_KEY_TYPE_PASSKEY 0x01
#define BLE_GAP_AUTH_KEY_TYPE_OOB 0x02
#define BLE_GAP_SEC_STATUS_SUCCESS 0x00
#define BLE_GAP_SEC_STATUS_TIMEOUT 0x01
#define BLE_GAP_SEC_STATUS_PDU_INVALID 0x02
#define BLE_GAP_SEC_STATUS_RFU_RANGE1_BEGIN 0x03
#define BLE_GAP_SEC_STATUS_RFU_RANGE1_END 0x80
#define BLE_GAP_SEC_STATUS_PASSKEY_ENTRY_FAILED 0x81
#define BLE_GAP_SEC_STATUS_OOB_NOT_AVAILABLE 0x82
#define BLE_GAP_SEC_STATUS_AUTH_REQ 0x83
#define BLE_GAP_SEC_STATUS_CONFIRM_VALUE 0x84
#define BLE_GAP_SEC_STATUS_PAIRING_NOT_SUPP 0x85
#define BLE_GAP_SEC_STATUS_ENC_KEY_SIZE 0x86
#define BLE_GAP_SEC_STATUS_SMP_CMD_UNSUPPORTED 0x87
#define BLE_GAP_SEC_STATUS_UNSPECIFIED 0x88
#define BLE_GAP_SEC_STATUS_REPEATED_ATTEMPTS 0x89
#define BLE_GAP_SEC_STATUS_INVALID_PARAMS 0x8A
#define BLE_GAP_SEC_STATUS_RFU_RANGE2_BEGIN 0x8B
#define BLE_GAP_SEC_STATUS_RFU_RANGE2_END 0xFF
#define BLE_GAP_SEC_STATUS_SOURCE_LOCAL 0x00
#define BLE_GAP_SEC_STATUS_SOURCE_REMOTE 0x01
#define BLE_GAP_CP_MIN_CONN_INTVL_NONE 0xFFFF
#define BLE_GAP_CP_MIN_CONN_INTVL_MIN 0x0006
#define BLE_GAP_CP_MIN_CONN_INTVL_MAX 0x0C80
#define BLE_GAP_CP_MAX_CONN_INTVL_NONE 0xFFFF
#define BLE_GAP_CP_MAX_CONN_INTVL_MIN 0x0006
#define BLE_GAP_CP_MAX_CONN_INTVL_MAX 0x0C80
#define BLE_GAP_CP_SLAVE_LATENCY_MAX 0x01F3
#define BLE_GAP_CP_CONN_SUP_TIMEOUT_NONE 0xFFFF
#define BLE_GAP_CP_CONN_SUP_TIMEOUT_MIN 0x000A
#define BLE_GAP_CP_CONN_SUP_TIMEOUT_MAX 0x0C80
#define BLE_GAP_DEVNAME_MAX_LEN 31
#define BLE_GAP_RSSI_THRESHOLD_INVALID 0xFF
#define BLE_GAP_CONN_SEC_MODE_SET_NO_ACCESS(ptr) do {(ptr)->sm = 0; (ptr)->lv = 0;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_OPEN(ptr) do {(ptr)->sm = 1; (ptr)->lv = 1;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_ENC_NO_MITM(ptr) do {(ptr)->sm = 1; (ptr)->lv = 2;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_ENC_WITH_MITM(ptr) do {(ptr)->sm = 1; (ptr)->lv = 3;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_SIGNED_NO_MITM(ptr) do {(ptr)->sm = 2; (ptr)->lv = 1;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_SIGNED_WITH_MITM(ptr) do {(ptr)->sm = 2; (ptr)->lv = 2;} while(0)
#define BLE_GAP_SEC_RAND_LEN 8
#define BLE_GAP_SEC_KEY_LEN 16
#define BLE_GAP_PASSKEY_LEN 6
#define BLE_GAP_WHITELIST_ADDR_MAX_COUNT (8)
#define BLE_GAP_WHITELIST_IRK_MAX_COUNT (8)
#define BLE_GAP_SEC_MODE 0x00
typedef struct
{
  uint8_t addr_type;
  uint8_t addr[BLE_GAP_ADDR_LEN];
} ble_gap_addr_t;
typedef struct
{
  uint16_t min_conn_interval;
  uint16_t max_conn_interval;
  uint16_t slave_latency;
  uint16_t conn_sup_timeout;
} ble_gap_conn_params_t;
typedef struct
{
  uint8_t sm : 4;
  uint8_t lv : 4;
} ble_gap_conn_sec_mode_t;
typedef struct
{
  ble_gap_conn_sec_mode_t sec_mode;
  uint8_t encr_key_size;
} ble_gap_conn_sec_t;
typedef struct
{
  uint8_t irk[BLE_GAP_SEC_KEY_LEN];
} ble_gap_irk_t;
typedef struct
{
  ble_gap_addr_t **pp_addrs;
  uint8_t addr_count;
  ble_gap_irk_t **pp_irks;
  uint8_t irk_count;
} ble_gap_whitelist_t;
typedef struct
{
  uint8_t ch_37_off : 1;
  uint8_t ch_38_off : 1;
  uint8_t ch_39_off : 1;
} ble_gap_adv_ch_mask_t;
typedef struct
{
  uint8_t type;
  ble_gap_addr_t *p_peer_addr;
  uint8_t fp;
  ble_gap_whitelist_t *p_whitelist;
  uint16_t interval;
  uint16_t timeout;
  ble_gap_adv_ch_mask_t channel_mask;
} ble_gap_adv_params_t;
typedef struct
{
  uint8_t active : 1;
  uint8_t selective : 1;
  ble_gap_whitelist_t * p_whitelist;
  uint16_t interval;
  uint16_t window;
  uint16_t timeout;
} ble_gap_scan_params_t;
typedef struct
{
  uint8_t enc : 1;
  uint8_t id : 1;
  uint8_t sign : 1;
} ble_gap_sec_kdist_t;
typedef struct
{
  uint8_t bond : 1;
  uint8_t mitm : 1;
  uint8_t io_caps : 3;
  uint8_t oob : 1;
  uint8_t min_key_size;
  uint8_t max_key_size;
  ble_gap_sec_kdist_t kdist_periph;
  ble_gap_sec_kdist_t kdist_central;
} ble_gap_sec_params_t;
typedef struct
{
  uint8_t ltk[BLE_GAP_SEC_KEY_LEN];
  uint8_t auth : 1;
  uint8_t ltk_len : 7;
} ble_gap_enc_info_t;
typedef struct
{
  uint16_t ediv;
  uint8_t rand[BLE_GAP_SEC_RAND_LEN];
} ble_gap_master_id_t;
typedef struct
{
  uint8_t csrk[BLE_GAP_SEC_KEY_LEN];
} ble_gap_sign_info_t;
typedef struct
{
  ble_gap_addr_t peer_addr;
  ble_gap_addr_t own_addr;
  uint8_t role;
  uint8_t irk_match :1;
  uint8_t irk_match_idx :7;
  ble_gap_conn_params_t conn_params;
} ble_gap_evt_connected_t;
typedef struct
{
  uint8_t reason;
} ble_gap_evt_disconnected_t;
typedef struct
{
  ble_gap_conn_params_t conn_params;
} ble_gap_evt_conn_param_update_t;
typedef struct
{
  ble_gap_sec_params_t peer_params;
} ble_gap_evt_sec_params_request_t;
typedef struct
{
  ble_gap_addr_t peer_addr;
  ble_gap_master_id_t master_id;
  uint8_t enc_info : 1;
  uint8_t id_info : 1;
  uint8_t sign_info : 1;
} ble_gap_evt_sec_info_request_t;
typedef struct
{
  uint8_t passkey[BLE_GAP_PASSKEY_LEN];
} ble_gap_evt_passkey_display_t;
typedef struct
{
  uint8_t key_type;
} ble_gap_evt_auth_key_request_t;
typedef struct
{
  uint8_t lv1 : 1;
  uint8_t lv2 : 1;
  uint8_t lv3 : 1;
} ble_gap_sec_levels_t;
typedef struct
{
  ble_gap_enc_info_t enc_info;
  ble_gap_master_id_t master_id;
} ble_gap_enc_key_t;
typedef struct
{
  ble_gap_irk_t id_info;
  ble_gap_addr_t id_addr_info;
} ble_gap_id_key_t;
typedef struct
{
  ble_gap_enc_key_t *p_enc_key;
  ble_gap_id_key_t *p_id_key;
  ble_gap_sign_info_t *p_sign_key;
} ble_gap_sec_keys_t;
typedef struct
{
  ble_gap_sec_keys_t keys_periph;
  ble_gap_sec_keys_t keys_central;
} ble_gap_sec_keyset_t;
typedef struct
{
  uint8_t auth_status;
  uint8_t error_src : 2;
  uint8_t bonded : 1;
  ble_gap_sec_levels_t sm1_levels;
  ble_gap_sec_levels_t sm2_levels;
  ble_gap_sec_kdist_t kdist_periph;
  ble_gap_sec_kdist_t kdist_central;
} ble_gap_evt_auth_status_t;
typedef struct
{
  ble_gap_conn_sec_t conn_sec;
} ble_gap_evt_conn_sec_update_t;
typedef struct
{
  uint8_t src;
} ble_gap_evt_timeout_t;
typedef struct
{
  int8_t rssi;
} ble_gap_evt_rssi_changed_t;
typedef struct
{
  ble_gap_addr_t peer_addr;
  int8_t rssi;
  uint8_t scan_rsp : 1;
  uint8_t type : 2;
  uint8_t dlen : 5;
  uint8_t data[BLE_GAP_ADV_MAX_SIZE];
} ble_gap_evt_adv_report_t;
typedef struct
{
  uint8_t bond : 1;
  uint8_t mitm : 1;
} ble_gap_evt_sec_request_t;
typedef struct
{
  ble_gap_conn_params_t conn_params;
} ble_gap_evt_conn_param_update_request_t;
typedef struct
{
  int8_t rssi;
  ble_gap_addr_t peer_addr;
} ble_gap_evt_scan_req_report_t;
typedef struct
{
  uint16_t conn_handle;
  union
  {
    ble_gap_evt_connected_t connected;
    ble_gap_evt_disconnected_t disconnected;
    ble_gap_evt_conn_param_update_t conn_param_update;
    ble_gap_evt_sec_params_request_t sec_params_request;
    ble_gap_evt_sec_info_request_t sec_info_request;
    ble_gap_evt_passkey_display_t passkey_display;
    ble_gap_evt_auth_key_request_t auth_key_request;
    ble_gap_evt_auth_status_t auth_status;
    ble_gap_evt_conn_sec_update_t conn_sec_update;
    ble_gap_evt_timeout_t timeout;
    ble_gap_evt_rssi_changed_t rssi_changed;
    ble_gap_evt_adv_report_t adv_report;
    ble_gap_evt_sec_request_t sec_request;
    ble_gap_evt_conn_param_update_request_t conn_param_update_request;
    ble_gap_evt_scan_req_report_t scan_req_report;
  } params;
} ble_gap_evt_t;
typedef struct
{
  uint16_t conn_handle;
  uint8_t ch_map[5];
} ble_gap_opt_ch_map_t;
typedef struct
{
  uint16_t conn_handle;
  uint16_t requested_latency;
  uint16_t * p_actual_latency;
} ble_gap_opt_local_conn_latency_t;
typedef struct
{
  uint8_t * p_passkey;
} ble_gap_opt_passkey_t;
typedef struct
{
  ble_gap_irk_t * p_irk;
  uint16_t interval_s;
} ble_gap_opt_privacy_t;
typedef struct
{
   uint8_t enable : 1;
} ble_gap_opt_scan_req_report_t;
typedef struct
{
   uint8_t mode_1_enable : 1;
} ble_gap_opt_compat_mode_t;
typedef union
{
  ble_gap_opt_ch_map_t ch_map;
  ble_gap_opt_local_conn_latency_t local_conn_latency;
  ble_gap_opt_passkey_t passkey;
  ble_gap_opt_privacy_t privacy;
  ble_gap_opt_scan_req_report_t scan_req_report;
  ble_gap_opt_compat_mode_t compat_mode;
} ble_gap_opt_t;
SVCALL(SD_BLE_GAP_ADDRESS_SET, uint32_t, sd_ble_gap_address_set(uint8_t addr_cycle_mode, const ble_gap_addr_t *p_addr));
SVCALL(SD_BLE_GAP_ADDRESS_GET, uint32_t, sd_ble_gap_address_get(ble_gap_addr_t *p_addr));
SVCALL(SD_BLE_GAP_ADV_DATA_SET, uint32_t, sd_ble_gap_adv_data_set(uint8_t const *p_data, uint8_t dlen, uint8_t const *p_sr_data, uint8_t srdlen));
SVCALL(SD_BLE_GAP_ADV_START, uint32_t, sd_ble_gap_adv_start(ble_gap_adv_params_t const *p_adv_params));
SVCALL(SD_BLE_GAP_ADV_STOP, uint32_t, sd_ble_gap_adv_stop(void));
SVCALL(SD_BLE_GAP_CONN_PARAM_UPDATE, uint32_t, sd_ble_gap_conn_param_update(uint16_t conn_handle, ble_gap_conn_params_t const *p_conn_params));
SVCALL(SD_BLE_GAP_DISCONNECT, uint32_t, sd_ble_gap_disconnect(uint16_t conn_handle, uint8_t hci_status_code));
SVCALL(SD_BLE_GAP_TX_POWER_SET, uint32_t, sd_ble_gap_tx_power_set(int8_t tx_power));
SVCALL(SD_BLE_GAP_APPEARANCE_SET, uint32_t, sd_ble_gap_appearance_set(uint16_t appearance));
SVCALL(SD_BLE_GAP_APPEARANCE_GET, uint32_t, sd_ble_gap_appearance_get(uint16_t *p_appearance));
SVCALL(SD_BLE_GAP_PPCP_SET, uint32_t, sd_ble_gap_ppcp_set(ble_gap_conn_params_t const *p_conn_params));
SVCALL(SD_BLE_GAP_PPCP_GET, uint32_t, sd_ble_gap_ppcp_get(ble_gap_conn_params_t *p_conn_params));
SVCALL(SD_BLE_GAP_DEVICE_NAME_SET, uint32_t, sd_ble_gap_device_name_set(ble_gap_conn_sec_mode_t const *p_write_perm, uint8_t const *p_dev_name, uint16_t len));
SVCALL(SD_BLE_GAP_DEVICE_NAME_GET, uint32_t, sd_ble_gap_device_name_get(uint8_t *p_dev_name, uint16_t *p_len));
SVCALL(SD_BLE_GAP_AUTHENTICATE, uint32_t, sd_ble_gap_authenticate(uint16_t conn_handle, ble_gap_sec_params_t const *p_sec_params));
SVCALL(SD_BLE_GAP_SEC_PARAMS_REPLY, uint32_t, sd_ble_gap_sec_params_reply(uint16_t conn_handle, uint8_t sec_status, ble_gap_sec_params_t const *p_sec_params, ble_gap_sec_keyset_t const *p_sec_keyset));
SVCALL(SD_BLE_GAP_AUTH_KEY_REPLY, uint32_t, sd_ble_gap_auth_key_reply(uint16_t conn_handle, uint8_t key_type, uint8_t const *p_key));
SVCALL(SD_BLE_GAP_ENCRYPT, uint32_t, sd_ble_gap_encrypt(uint16_t conn_handle, ble_gap_master_id_t const *p_master_id, ble_gap_enc_info_t const *p_enc_info));
SVCALL(SD_BLE_GAP_SEC_INFO_REPLY, uint32_t, sd_ble_gap_sec_info_reply(uint16_t conn_handle, ble_gap_enc_info_t const *p_enc_info, ble_gap_irk_t const *p_id_info, ble_gap_sign_info_t const *p_sign_info));
SVCALL(SD_BLE_GAP_CONN_SEC_GET, uint32_t, sd_ble_gap_conn_sec_get(uint16_t conn_handle, ble_gap_conn_sec_t *p_conn_sec));
SVCALL(SD_BLE_GAP_RSSI_START, uint32_t, sd_ble_gap_rssi_start(uint16_t conn_handle, uint8_t threshold_dbm, uint8_t skip_count));
SVCALL(SD_BLE_GAP_RSSI_STOP, uint32_t, sd_ble_gap_rssi_stop(uint16_t conn_handle));
SVCALL(SD_BLE_GAP_RSSI_GET, uint32_t, sd_ble_gap_rssi_get(uint16_t conn_handle, int8_t *p_rssi));
SVCALL(SD_BLE_GAP_SCAN_START, uint32_t, sd_ble_gap_scan_start(ble_gap_scan_params_t const *p_scan_params));
SVCALL(SD_BLE_GAP_SCAN_STOP, uint32_t, sd_ble_gap_scan_stop(void));
SVCALL(SD_BLE_GAP_CONNECT, uint32_t, sd_ble_gap_connect(ble_gap_addr_t const *p_peer_addr, ble_gap_scan_params_t const *p_scan_params, ble_gap_conn_params_t const *p_conn_params));
SVCALL(SD_BLE_GAP_CONNECT_CANCEL, uint32_t, sd_ble_gap_connect_cancel(void));
#endif
