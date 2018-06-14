#ifndef BLE_GAP_H__
#define BLE_GAP_H__ 
#include "ble_types.h"
#include "ble_ranges.h"
#include "nrf_svc.h"
#ifdef __cplusplus
extern "C" {
#endif
enum BLE_GAP_SVCS
{
  SD_BLE_GAP_ADDR_SET = BLE_GAP_SVC_BASE,
  SD_BLE_GAP_ADDR_GET,
  SD_BLE_GAP_WHITELIST_SET,
  SD_BLE_GAP_DEVICE_IDENTITIES_SET,
  SD_BLE_GAP_PRIVACY_SET,
  SD_BLE_GAP_PRIVACY_GET,
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
  SD_BLE_GAP_LESC_DHKEY_REPLY,
  SD_BLE_GAP_KEYPRESS_NOTIFY,
  SD_BLE_GAP_LESC_OOB_DATA_GET,
  SD_BLE_GAP_LESC_OOB_DATA_SET,
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
  SD_BLE_GAP_PHY_REQUEST,
  SD_BLE_GAP_DATA_LENGTH_UPDATE,
};
enum BLE_GAP_EVTS
{
  BLE_GAP_EVT_CONNECTED = BLE_GAP_EVT_BASE,
  BLE_GAP_EVT_DISCONNECTED,
  BLE_GAP_EVT_CONN_PARAM_UPDATE,
  BLE_GAP_EVT_SEC_PARAMS_REQUEST,
  BLE_GAP_EVT_SEC_INFO_REQUEST,
  BLE_GAP_EVT_PASSKEY_DISPLAY,
  BLE_GAP_EVT_KEY_PRESSED,
  BLE_GAP_EVT_AUTH_KEY_REQUEST,
  BLE_GAP_EVT_LESC_DHKEY_REQUEST,
  BLE_GAP_EVT_AUTH_STATUS,
  BLE_GAP_EVT_CONN_SEC_UPDATE,
  BLE_GAP_EVT_TIMEOUT,
  BLE_GAP_EVT_RSSI_CHANGED,
  BLE_GAP_EVT_ADV_REPORT,
  BLE_GAP_EVT_SEC_REQUEST,
  BLE_GAP_EVT_CONN_PARAM_UPDATE_REQUEST,
  BLE_GAP_EVT_SCAN_REQ_REPORT,
  BLE_GAP_EVT_PHY_UPDATE,
  BLE_GAP_EVT_DATA_LENGTH_UPDATE_REQUEST,
  BLE_GAP_EVT_DATA_LENGTH_UPDATE,
};
enum BLE_GAP_OPTS
{
  BLE_GAP_OPT_CH_MAP = BLE_GAP_OPT_BASE,
  BLE_GAP_OPT_LOCAL_CONN_LATENCY,
  BLE_GAP_OPT_PASSKEY,
  BLE_GAP_OPT_SCAN_REQ_REPORT,
  BLE_GAP_OPT_COMPAT_MODE_1,
  BLE_GAP_OPT_COMPAT_MODE_2,
  BLE_GAP_OPT_AUTH_PAYLOAD_TIMEOUT,
  BLE_GAP_OPT_PREFERRED_PHYS_SET,
  BLE_GAP_OPT_SLAVE_LATENCY_DISABLE,
};
enum BLE_GAP_CFGS
{
  BLE_GAP_CFG_ROLE_COUNT = BLE_GAP_CFG_BASE,
  BLE_GAP_CFG_DEVICE_NAME,
};
#define BLE_ERROR_GAP_UUID_LIST_MISMATCH (NRF_GAP_ERR_BASE + 0x000)
#define BLE_ERROR_GAP_DISCOVERABLE_WITH_WHITELIST (NRF_GAP_ERR_BASE + 0x001)
#define BLE_ERROR_GAP_INVALID_BLE_ADDR (NRF_GAP_ERR_BASE + 0x002)
#define BLE_ERROR_GAP_WHITELIST_IN_USE (NRF_GAP_ERR_BASE + 0x003)
#define BLE_ERROR_GAP_DEVICE_IDENTITIES_IN_USE (NRF_GAP_ERR_BASE + 0x004)
#define BLE_ERROR_GAP_DEVICE_IDENTITIES_DUPLICATE (NRF_GAP_ERR_BASE + 0x005)
#define BLE_GAP_ROLE_INVALID 0x0
#define BLE_GAP_ROLE_PERIPH 0x1
#define BLE_GAP_ROLE_CENTRAL 0x2
#define BLE_GAP_TIMEOUT_SRC_ADVERTISING 0x00
#define BLE_GAP_TIMEOUT_SRC_SECURITY_REQUEST 0x01
#define BLE_GAP_TIMEOUT_SRC_SCAN 0x02
#define BLE_GAP_TIMEOUT_SRC_CONN 0x03
#define BLE_GAP_TIMEOUT_SRC_AUTH_PAYLOAD 0x04
#define BLE_GAP_ADDR_TYPE_PUBLIC 0x00
#define BLE_GAP_ADDR_TYPE_RANDOM_STATIC 0x01
#define BLE_GAP_ADDR_TYPE_RANDOM_PRIVATE_RESOLVABLE 0x02
#define BLE_GAP_ADDR_TYPE_RANDOM_PRIVATE_NON_RESOLVABLE 0x03
#define BLE_GAP_DEFAULT_PRIVATE_ADDR_CYCLE_INTERVAL_S (900)
#define BLE_GAP_MAX_PRIVATE_ADDR_CYCLE_INTERVAL_S (41400)
#define BLE_GAP_ADDR_LEN (6)
#define BLE_GAP_PRIVACY_MODE_OFF 0x00
#define BLE_GAP_PRIVACY_MODE_DEVICE_PRIVACY 0x01
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
#define BLE_GAP_AD_TYPE_LESC_CONFIRMATION_VALUE 0x22
#define BLE_GAP_AD_TYPE_LESC_RANDOM_VALUE 0x23
#define BLE_GAP_AD_TYPE_URI 0x24
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
#define BLE_GAP_ADV_MAX_SIZE (31)
#define BLE_GAP_ADV_TYPE_ADV_IND 0x00
#define BLE_GAP_ADV_TYPE_ADV_DIRECT_IND 0x01
#define BLE_GAP_ADV_TYPE_ADV_SCAN_IND 0x02
#define BLE_GAP_ADV_TYPE_ADV_NONCONN_IND 0x03
#define BLE_GAP_ADV_FP_ANY 0x00
#define BLE_GAP_ADV_FP_FILTER_SCANREQ 0x01
#define BLE_GAP_ADV_FP_FILTER_CONNREQ 0x02
#define BLE_GAP_ADV_FP_FILTER_BOTH 0x03
#define BLE_GAP_ADV_TIMEOUT_LIMITED_MAX (180)
#define BLE_GAP_ADV_TIMEOUT_GENERAL_UNLIMITED (0)
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
#define BLE_GAP_KP_NOT_TYPE_PASSKEY_START 0x00
#define BLE_GAP_KP_NOT_TYPE_PASSKEY_DIGIT_IN 0x01
#define BLE_GAP_KP_NOT_TYPE_PASSKEY_DIGIT_OUT 0x02
#define BLE_GAP_KP_NOT_TYPE_PASSKEY_CLEAR 0x03
#define BLE_GAP_KP_NOT_TYPE_PASSKEY_END 0x04
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
#define BLE_GAP_SEC_STATUS_DHKEY_FAILURE 0x8B
#define BLE_GAP_SEC_STATUS_NUM_COMP_FAILURE 0x8C
#define BLE_GAP_SEC_STATUS_BR_EDR_IN_PROG 0x8D
#define BLE_GAP_SEC_STATUS_X_TRANS_KEY_DISALLOWED 0x8E
#define BLE_GAP_SEC_STATUS_RFU_RANGE2_BEGIN 0x8F
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
#define BLE_GAP_DEVNAME_DEFAULT "nRF5x"
#define BLE_GAP_DEVNAME_DEFAULT_LEN 31
#define BLE_GAP_DEVNAME_MAX_LEN 248
#define BLE_GAP_RSSI_THRESHOLD_INVALID 0xFF
#define BLE_GAP_PHY_1MBPS 0x01
#define BLE_GAP_PHY_2MBPS 0x02
#define BLE_GAP_PHY_CODED 0x04
#define BLE_GAP_CONN_SEC_MODE_SET_NO_ACCESS(ptr) do {(ptr)->sm = 0; (ptr)->lv = 0;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_OPEN(ptr) do {(ptr)->sm = 1; (ptr)->lv = 1;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_ENC_NO_MITM(ptr) do {(ptr)->sm = 1; (ptr)->lv = 2;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_ENC_WITH_MITM(ptr) do {(ptr)->sm = 1; (ptr)->lv = 3;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_LESC_ENC_WITH_MITM(ptr) do {(ptr)->sm = 1; (ptr)->lv = 4;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_SIGNED_NO_MITM(ptr) do {(ptr)->sm = 2; (ptr)->lv = 1;} while(0)
#define BLE_GAP_CONN_SEC_MODE_SET_SIGNED_WITH_MITM(ptr) do {(ptr)->sm = 2; (ptr)->lv = 2;} while(0)
#define BLE_GAP_SEC_RAND_LEN 8
#define BLE_GAP_SEC_KEY_LEN 16
#define BLE_GAP_LESC_P256_PK_LEN 64
#define BLE_GAP_LESC_DHKEY_LEN 32
#define BLE_GAP_PASSKEY_LEN 6
#define BLE_GAP_WHITELIST_ADDR_MAX_COUNT (8)
#define BLE_GAP_DEVICE_IDENTITIES_MAX_COUNT (8)
#define BLE_GAP_CONN_COUNT_DEFAULT (1)
#define BLE_GAP_EVENT_LENGTH_MIN (2)
#define BLE_GAP_EVENT_LENGTH_DEFAULT (3)
#define BLE_GAP_ROLE_COUNT_PERIPH_DEFAULT (1)
#define BLE_GAP_ROLE_COUNT_CENTRAL_DEFAULT (3)
#define BLE_GAP_ROLE_COUNT_CENTRAL_SEC_DEFAULT (1)
#define BLE_GAP_ROLE_COUNT_COMBINED_MAX (20)
#define BLE_GAP_DATA_LENGTH_AUTO 0
#define BLE_GAP_SEC_MODE 0x00
typedef struct
{
  uint8_t addr_id_peer : 1;
  uint8_t addr_type : 7;
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
  uint8_t ch_37_off : 1;
  uint8_t ch_38_off : 1;
  uint8_t ch_39_off : 1;
} ble_gap_adv_ch_mask_t;
typedef struct
{
  uint8_t type;
  ble_gap_addr_t const *p_peer_addr;
  uint8_t fp;
  uint16_t interval;
  uint16_t timeout;
  ble_gap_adv_ch_mask_t channel_mask;
} ble_gap_adv_params_t;
typedef struct
{
  uint8_t active : 1;
  uint8_t use_whitelist : 1;
  uint8_t adv_dir_report : 1;
  uint16_t interval;
  uint16_t window;
  uint16_t timeout;
} ble_gap_scan_params_t;
typedef struct
{
  uint8_t privacy_mode;
  uint8_t private_addr_type;
  uint16_t private_addr_cycle_s;
  ble_gap_irk_t *p_device_irk;
} ble_gap_privacy_params_t;
typedef struct
{
  uint8_t tx_phys;
  uint8_t rx_phys;
} ble_gap_phys_t;
typedef struct
{
  uint8_t enc : 1;
  uint8_t id : 1;
  uint8_t sign : 1;
  uint8_t link : 1;
} ble_gap_sec_kdist_t;
typedef struct
{
  uint8_t bond : 1;
  uint8_t mitm : 1;
  uint8_t lesc : 1;
  uint8_t keypress : 1;
  uint8_t io_caps : 3;
  uint8_t oob : 1;
  uint8_t min_key_size;
  uint8_t max_key_size;
  ble_gap_sec_kdist_t kdist_own;
  ble_gap_sec_kdist_t kdist_peer;
} ble_gap_sec_params_t;
typedef struct
{
  uint8_t ltk[BLE_GAP_SEC_KEY_LEN];
  uint8_t lesc : 1;
  uint8_t auth : 1;
  uint8_t ltk_len : 6;
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
  uint8_t pk[BLE_GAP_LESC_P256_PK_LEN];
} ble_gap_lesc_p256_pk_t;
typedef struct
{
  uint8_t key[BLE_GAP_LESC_DHKEY_LEN];
} ble_gap_lesc_dhkey_t;
typedef struct
{
  ble_gap_addr_t addr;
  uint8_t r[BLE_GAP_SEC_KEY_LEN];
  uint8_t c[BLE_GAP_SEC_KEY_LEN];
} ble_gap_lesc_oob_data_t;
typedef struct
{
  ble_gap_addr_t peer_addr;
  uint8_t role;
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
  uint8_t status;
  uint8_t tx_phy;
  uint8_t rx_phy;
} ble_gap_evt_phy_update_t;
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
  uint8_t match_request : 1;
} ble_gap_evt_passkey_display_t;
typedef struct
{
  uint8_t kp_not;
} ble_gap_evt_key_pressed_t;
typedef struct
{
  uint8_t key_type;
} ble_gap_evt_auth_key_request_t;
typedef struct
{
  ble_gap_lesc_p256_pk_t *p_pk_peer;
  uint8_t oobd_req :1;
} ble_gap_evt_lesc_dhkey_request_t;
typedef struct
{
  uint8_t lv1 : 1;
  uint8_t lv2 : 1;
  uint8_t lv3 : 1;
  uint8_t lv4 : 1;
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
  ble_gap_lesc_p256_pk_t *p_pk;
} ble_gap_sec_keys_t;
typedef struct
{
  ble_gap_sec_keys_t keys_own;
  ble_gap_sec_keys_t keys_peer;
} ble_gap_sec_keyset_t;
typedef struct
{
  uint16_t max_tx_octets;
  uint16_t max_rx_octets;
  uint16_t max_tx_time_us;
  uint16_t max_rx_time_us;
} ble_gap_data_length_params_t;
typedef struct
{
  uint16_t tx_payload_limited_octets;
  uint16_t rx_payload_limited_octets;
  uint16_t tx_rx_time_limited_us;
} ble_gap_data_length_limitation_t;
typedef struct
{
  uint8_t auth_status;
  uint8_t error_src : 2;
  uint8_t bonded : 1;
  ble_gap_sec_levels_t sm1_levels;
  ble_gap_sec_levels_t sm2_levels;
  ble_gap_sec_kdist_t kdist_own;
  ble_gap_sec_kdist_t kdist_peer;
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
  ble_gap_addr_t direct_addr;
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
  uint8_t lesc : 1;
  uint8_t keypress : 1;
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
  ble_gap_data_length_params_t peer_params;
} ble_gap_evt_data_length_update_request_t;
typedef struct
{
  ble_gap_data_length_params_t effective_params;
} ble_gap_evt_data_length_update_t;
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
    ble_gap_evt_key_pressed_t key_pressed;
    ble_gap_evt_auth_key_request_t auth_key_request;
    ble_gap_evt_lesc_dhkey_request_t lesc_dhkey_request;
    ble_gap_evt_auth_status_t auth_status;
    ble_gap_evt_conn_sec_update_t conn_sec_update;
    ble_gap_evt_timeout_t timeout;
    ble_gap_evt_rssi_changed_t rssi_changed;
    ble_gap_evt_adv_report_t adv_report;
    ble_gap_evt_sec_request_t sec_request;
    ble_gap_evt_conn_param_update_request_t conn_param_update_request;
    ble_gap_evt_scan_req_report_t scan_req_report;
    ble_gap_evt_phy_update_t phy_update;
    ble_gap_evt_data_length_update_request_t data_length_update_request;
    ble_gap_evt_data_length_update_t data_length_update;
  } params;
} ble_gap_evt_t;
typedef struct
{
  uint8_t conn_count;
  uint16_t event_length;
} ble_gap_conn_cfg_t;
typedef struct
{
  uint8_t periph_role_count;
  uint8_t central_role_count;
  uint8_t central_sec_count;
} ble_gap_cfg_role_count_t;
typedef struct
{
  ble_gap_conn_sec_mode_t write_perm;
  uint8_t vloc:2;
  uint8_t *p_value;
  uint16_t current_len;
  uint16_t max_len;
} ble_gap_cfg_device_name_t;
typedef union
{
  ble_gap_cfg_role_count_t role_count_cfg;
  ble_gap_cfg_device_name_t device_name_cfg;
} ble_gap_cfg_t;
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
  uint16_t conn_handle;
  uint8_t disable : 1;
} ble_gap_opt_slave_latency_disable_t;
typedef struct
{
  uint8_t const * p_passkey;
} ble_gap_opt_passkey_t;
typedef struct
{
  uint8_t enable : 1;
} ble_gap_opt_scan_req_report_t;
typedef struct
{
   uint8_t enable : 1;
} ble_gap_opt_compat_mode_1_t;
typedef struct
{
   uint8_t enable : 1;
} ble_gap_opt_compat_mode_2_t;
typedef struct
{
  uint16_t conn_handle;
  uint16_t auth_payload_timeout;
} ble_gap_opt_auth_payload_timeout_t;
typedef struct
{
  uint8_t tx_phys;
  uint8_t rx_phys;
} ble_gap_opt_preferred_phys_t;
typedef union
{
  ble_gap_opt_ch_map_t ch_map;
  ble_gap_opt_local_conn_latency_t local_conn_latency;
  ble_gap_opt_passkey_t passkey;
  ble_gap_opt_scan_req_report_t scan_req_report;
  ble_gap_opt_compat_mode_1_t compat_mode_1;
  ble_gap_opt_compat_mode_2_t compat_mode_2;
  ble_gap_opt_auth_payload_timeout_t auth_payload_timeout;
  ble_gap_opt_preferred_phys_t preferred_phys;
  ble_gap_opt_slave_latency_disable_t slave_latency_disable;
} ble_gap_opt_t;
SVCALL(SD_BLE_GAP_ADDR_SET, uint32_t, sd_ble_gap_addr_set(ble_gap_addr_t const *p_addr));
SVCALL(SD_BLE_GAP_ADDR_GET, uint32_t, sd_ble_gap_addr_get(ble_gap_addr_t *p_addr));
SVCALL(SD_BLE_GAP_WHITELIST_SET, uint32_t, sd_ble_gap_whitelist_set(ble_gap_addr_t const * const * pp_wl_addrs, uint8_t len));
SVCALL(SD_BLE_GAP_DEVICE_IDENTITIES_SET, uint32_t, sd_ble_gap_device_identities_set(ble_gap_id_key_t const * const * pp_id_keys, ble_gap_irk_t const * const * pp_local_irks, uint8_t len));
SVCALL(SD_BLE_GAP_PRIVACY_SET, uint32_t, sd_ble_gap_privacy_set(ble_gap_privacy_params_t const *p_privacy_params));
SVCALL(SD_BLE_GAP_PRIVACY_GET, uint32_t, sd_ble_gap_privacy_get(ble_gap_privacy_params_t *p_privacy_params));
SVCALL(SD_BLE_GAP_ADV_DATA_SET, uint32_t, sd_ble_gap_adv_data_set(uint8_t const *p_data, uint8_t dlen, uint8_t const *p_sr_data, uint8_t srdlen));
SVCALL(SD_BLE_GAP_ADV_START, uint32_t, sd_ble_gap_adv_start(ble_gap_adv_params_t const *p_adv_params, uint8_t conn_cfg_tag));
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
SVCALL(SD_BLE_GAP_LESC_DHKEY_REPLY, uint32_t, sd_ble_gap_lesc_dhkey_reply(uint16_t conn_handle, ble_gap_lesc_dhkey_t const *p_dhkey));
SVCALL(SD_BLE_GAP_KEYPRESS_NOTIFY, uint32_t, sd_ble_gap_keypress_notify(uint16_t conn_handle, uint8_t kp_not));
SVCALL(SD_BLE_GAP_LESC_OOB_DATA_GET, uint32_t, sd_ble_gap_lesc_oob_data_get(uint16_t conn_handle, ble_gap_lesc_p256_pk_t const *p_pk_own, ble_gap_lesc_oob_data_t *p_oobd_own));
SVCALL(SD_BLE_GAP_LESC_OOB_DATA_SET, uint32_t, sd_ble_gap_lesc_oob_data_set(uint16_t conn_handle, ble_gap_lesc_oob_data_t const *p_oobd_own, ble_gap_lesc_oob_data_t const *p_oobd_peer));
SVCALL(SD_BLE_GAP_ENCRYPT, uint32_t, sd_ble_gap_encrypt(uint16_t conn_handle, ble_gap_master_id_t const *p_master_id, ble_gap_enc_info_t const *p_enc_info));
SVCALL(SD_BLE_GAP_SEC_INFO_REPLY, uint32_t, sd_ble_gap_sec_info_reply(uint16_t conn_handle, ble_gap_enc_info_t const *p_enc_info, ble_gap_irk_t const *p_id_info, ble_gap_sign_info_t const *p_sign_info));
SVCALL(SD_BLE_GAP_CONN_SEC_GET, uint32_t, sd_ble_gap_conn_sec_get(uint16_t conn_handle, ble_gap_conn_sec_t *p_conn_sec));
SVCALL(SD_BLE_GAP_RSSI_START, uint32_t, sd_ble_gap_rssi_start(uint16_t conn_handle, uint8_t threshold_dbm, uint8_t skip_count));
SVCALL(SD_BLE_GAP_RSSI_STOP, uint32_t, sd_ble_gap_rssi_stop(uint16_t conn_handle));
SVCALL(SD_BLE_GAP_RSSI_GET, uint32_t, sd_ble_gap_rssi_get(uint16_t conn_handle, int8_t *p_rssi));
SVCALL(SD_BLE_GAP_SCAN_START, uint32_t, sd_ble_gap_scan_start(ble_gap_scan_params_t const *p_scan_params));
SVCALL(SD_BLE_GAP_SCAN_STOP, uint32_t, sd_ble_gap_scan_stop(void));
SVCALL(SD_BLE_GAP_CONNECT, uint32_t, sd_ble_gap_connect(ble_gap_addr_t const *p_peer_addr, ble_gap_scan_params_t const *p_scan_params, ble_gap_conn_params_t const *p_conn_params, uint8_t conn_cfg_tag));
SVCALL(SD_BLE_GAP_CONNECT_CANCEL, uint32_t, sd_ble_gap_connect_cancel(void));
SVCALL(SD_BLE_GAP_PHY_REQUEST, uint32_t, sd_ble_gap_phy_request(uint16_t conn_handle, ble_gap_phys_t const *p_gap_phys));
SVCALL(SD_BLE_GAP_DATA_LENGTH_UPDATE, uint32_t, sd_ble_gap_data_length_update(uint16_t conn_handle, ble_gap_data_length_params_t const *p_dl_params, ble_gap_data_length_limitation_t *p_dl_limitation));
#ifdef __cplusplus
}
#endif
#endif
