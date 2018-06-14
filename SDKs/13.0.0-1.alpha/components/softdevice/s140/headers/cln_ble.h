#ifndef BLE_H__
#define BLE_H__ 
#include "ble_ranges.h"
#include "ble_types.h"
#include "ble_gap.h"
#include "ble_l2cap.h"
#include "ble_gatt.h"
#include "ble_gattc.h"
#include "ble_gatts.h"
#ifdef __cplusplus
extern "C" {
#endif
enum BLE_COMMON_SVCS
{
  SD_BLE_ENABLE = BLE_SVC_BASE,
  SD_BLE_EVT_GET,
  SD_BLE_TX_PACKET_COUNT_GET,
  SD_BLE_UUID_VS_ADD,
  SD_BLE_UUID_DECODE,
  SD_BLE_UUID_ENCODE,
  SD_BLE_VERSION_GET,
  SD_BLE_USER_MEM_REPLY,
  SD_BLE_OPT_SET,
  SD_BLE_OPT_GET,
};
enum BLE_COMMON_EVTS
{
  BLE_EVT_TX_COMPLETE = BLE_EVT_BASE,
  BLE_EVT_USER_MEM_REQUEST,
  BLE_EVT_USER_MEM_RELEASE,
  BLE_EVT_DATA_LENGTH_CHANGED
};
enum BLE_CONN_BWS
{
  BLE_CONN_BW_INVALID = 0,
  BLE_CONN_BW_LOW,
  BLE_CONN_BW_MID,
  BLE_CONN_BW_HIGH
};
enum BLE_COMMON_OPTS
{
  BLE_COMMON_OPT_CONN_BW = BLE_OPT_BASE,
  BLE_COMMON_OPT_PA_LNA,
  BLE_COMMON_OPT_CONN_EVT_EXT,
};
#define BLE_EVT_PTR_ALIGNMENT 4
#define BLE_MAX(a,b) ((a) < (b) ? (b) : (a))
#define BLE_EVT_LEN_MAX(ATT_MTU) (BLE_MAX( \
  sizeof(ble_evt_t), \
  BLE_MAX( \
    offsetof(ble_evt_t, evt.gattc_evt.params.rel_disc_rsp.includes) + ((ATT_MTU) - 2) / 6 * sizeof(ble_gattc_include_t), \
    offsetof(ble_evt_t, evt.gattc_evt.params.attr_info_disc_rsp.info.attr_info16) + ((ATT_MTU) - 2) / 4 * sizeof(ble_gattc_attr_info16_t) \
  ) \
))
#define BLE_USER_MEM_TYPE_INVALID 0x00
#define BLE_USER_MEM_TYPE_GATTS_QUEUED_WRITES 0x01
#define BLE_UUID_VS_COUNT_MIN 1
#define BLE_UUID_VS_COUNT_DEFAULT 0
typedef struct
{
  uint8_t *p_mem;
  uint16_t len;
} ble_user_mem_block_t;
typedef struct
{
  uint8_t count;
} ble_evt_tx_complete_t;
typedef struct
{
  uint8_t type;
} ble_evt_user_mem_request_t;
typedef struct
{
  uint8_t type;
  ble_user_mem_block_t mem_block;
} ble_evt_user_mem_release_t;
typedef struct
{
  uint16_t max_tx_octets;
  uint16_t max_tx_time;
  uint16_t max_rx_octets;
  uint16_t max_rx_time;
} ble_evt_data_length_changed_t;
typedef struct
{
  uint16_t conn_handle;
  union
  {
    ble_evt_tx_complete_t tx_complete;
    ble_evt_user_mem_request_t user_mem_request;
    ble_evt_user_mem_release_t user_mem_release;
    ble_evt_data_length_changed_t data_length_changed;
  } params;
} ble_common_evt_t;
typedef struct
{
  uint16_t evt_id;
  uint16_t evt_len;
} ble_evt_hdr_t;
typedef struct
{
  ble_evt_hdr_t header;
  union
  {
    ble_common_evt_t common_evt;
    ble_gap_evt_t gap_evt;
    ble_l2cap_evt_t l2cap_evt;
    ble_gattc_evt_t gattc_evt;
    ble_gatts_evt_t gatts_evt;
  } evt;
} ble_evt_t;
typedef struct
{
  uint8_t version_number;
  uint16_t company_id;
  uint16_t subversion_number;
} ble_version_t;
typedef struct
{
     uint8_t enable :1;
     uint8_t active_high :1;
     uint8_t gpio_pin :6;
} ble_pa_lna_cfg_t;
typedef struct
{
   ble_pa_lna_cfg_t pa_cfg;
   ble_pa_lna_cfg_t lna_cfg;
   uint8_t ppi_ch_id_set;
   uint8_t ppi_ch_id_clr;
   uint8_t gpiote_ch_id;
} ble_common_opt_pa_lna_t;
typedef struct
{
  uint8_t conn_bw_tx;
  uint8_t conn_bw_rx;
} ble_conn_bw_t;
typedef struct
{
  uint8_t role;
  ble_conn_bw_t conn_bw;
} ble_common_opt_conn_bw_t;
typedef struct
{
   uint8_t enable : 1;
} ble_common_opt_conn_evt_ext_t;
typedef union
{
  ble_common_opt_conn_bw_t conn_bw;
  ble_common_opt_pa_lna_t pa_lna;
  ble_common_opt_conn_evt_ext_t conn_evt_ext;
} ble_common_opt_t;
typedef union
{
  ble_common_opt_t common_opt;
  ble_gap_opt_t gap_opt;
} ble_opt_t;
typedef struct {
  uint8_t high_count;
  uint8_t mid_count;
  uint8_t low_count;
} ble_conn_bw_count_t;
typedef struct {
  ble_conn_bw_count_t tx_counts;
  ble_conn_bw_count_t rx_counts;
} ble_conn_bw_counts_t;
typedef struct
{
  uint16_t vs_uuid_count;
  ble_conn_bw_counts_t *p_conn_bw_counts;
} ble_common_enable_params_t;
typedef struct
{
  ble_common_enable_params_t common_enable_params;
  ble_gap_enable_params_t gap_enable_params;
  ble_gatt_enable_params_t gatt_enable_params;
  ble_gatts_enable_params_t gatts_enable_params;
} ble_enable_params_t;
SVCALL(SD_BLE_ENABLE, uint32_t, sd_ble_enable(ble_enable_params_t * p_ble_enable_params, uint32_t * p_app_ram_base));
SVCALL(SD_BLE_EVT_GET, uint32_t, sd_ble_evt_get(uint8_t *p_dest, uint16_t *p_len));
SVCALL(SD_BLE_TX_PACKET_COUNT_GET, uint32_t, sd_ble_tx_packet_count_get(uint16_t conn_handle, uint8_t *p_count));
SVCALL(SD_BLE_UUID_VS_ADD, uint32_t, sd_ble_uuid_vs_add(ble_uuid128_t const *p_vs_uuid, uint8_t *p_uuid_type));
SVCALL(SD_BLE_UUID_DECODE, uint32_t, sd_ble_uuid_decode(uint8_t uuid_le_len, uint8_t const *p_uuid_le, ble_uuid_t *p_uuid));
SVCALL(SD_BLE_UUID_ENCODE, uint32_t, sd_ble_uuid_encode(ble_uuid_t const *p_uuid, uint8_t *p_uuid_le_len, uint8_t *p_uuid_le));
SVCALL(SD_BLE_VERSION_GET, uint32_t, sd_ble_version_get(ble_version_t *p_version));
SVCALL(SD_BLE_USER_MEM_REPLY, uint32_t, sd_ble_user_mem_reply(uint16_t conn_handle, ble_user_mem_block_t const *p_block));
SVCALL(SD_BLE_OPT_SET, uint32_t, sd_ble_opt_set(uint32_t opt_id, ble_opt_t const *p_opt));
SVCALL(SD_BLE_OPT_GET, uint32_t, sd_ble_opt_get(uint32_t opt_id, ble_opt_t *p_opt));
#ifdef __cplusplus
}
#endif
#endif
