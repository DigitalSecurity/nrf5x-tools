#ifndef BLE_H__
#define BLE_H__ 
#include "ble_ranges.h"
#include "ble_types.h"
#include "ble_gap.h"
#include "ble_l2cap.h"
#include "ble_gatt.h"
#include "ble_gattc.h"
#include "ble_gatts.h"
enum BLE_COMMON_SVCS
{
  SD_BLE_ENABLE = BLE_SVC_BASE,
  SD_BLE_EVT_GET,
  SD_BLE_TX_BUFFER_COUNT_GET,
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
  BLE_EVT_USER_MEM_RELEASE
};
enum BLE_COMMON_OPTS
{
  BLE_COMMON_OPT_RADIO_CPU_MUTEX = BLE_OPT_BASE
};
#define BLE_EVTS_PTR_ALIGNMENT 4
#define BLE_USER_MEM_TYPE_INVALID 0x00
#define BLE_USER_MEM_TYPE_GATTS_QUEUED_WRITES 0x01
#define BLE_UUID_VS_MAX_COUNT 10
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
  uint16_t conn_handle;
  union
  {
    ble_evt_tx_complete_t tx_complete;
    ble_evt_user_mem_request_t user_mem_request;
    ble_evt_user_mem_release_t user_mem_release;
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
  uint8_t enable : 1;
} ble_common_opt_radio_cpu_mutex_t;
typedef union
{
  ble_common_opt_radio_cpu_mutex_t radio_cpu_mutex;
} ble_common_opt_t;
typedef union
{
  ble_common_opt_t common_opt;
  ble_gap_opt_t gap_opt;
} ble_opt_t;
typedef struct
{
  ble_gap_enable_params_t gap_enable_params;
  ble_gatts_enable_params_t gatts_enable_params;
} ble_enable_params_t;
SVCALL(SD_BLE_ENABLE, uint32_t, sd_ble_enable(ble_enable_params_t * p_ble_enable_params));
SVCALL(SD_BLE_EVT_GET, uint32_t, sd_ble_evt_get(uint8_t *p_dest, uint16_t *p_len));
SVCALL(SD_BLE_TX_BUFFER_COUNT_GET, uint32_t, sd_ble_tx_buffer_count_get(uint8_t *p_count));
SVCALL(SD_BLE_UUID_VS_ADD, uint32_t, sd_ble_uuid_vs_add(ble_uuid128_t const *p_vs_uuid, uint8_t *p_uuid_type));
SVCALL(SD_BLE_UUID_DECODE, uint32_t, sd_ble_uuid_decode(uint8_t uuid_le_len, uint8_t const *p_uuid_le, ble_uuid_t *p_uuid));
SVCALL(SD_BLE_UUID_ENCODE, uint32_t, sd_ble_uuid_encode(ble_uuid_t const *p_uuid, uint8_t *p_uuid_le_len, uint8_t *p_uuid_le));
SVCALL(SD_BLE_VERSION_GET, uint32_t, sd_ble_version_get(ble_version_t *p_version));
SVCALL(SD_BLE_USER_MEM_REPLY, uint32_t, sd_ble_user_mem_reply(uint16_t conn_handle, ble_user_mem_block_t const *p_block));
SVCALL(SD_BLE_OPT_SET, uint32_t, sd_ble_opt_set(uint32_t opt_id, ble_opt_t const *p_opt));
SVCALL(SD_BLE_OPT_GET, uint32_t, sd_ble_opt_get(uint32_t opt_id, ble_opt_t *p_opt));
#endif
