#ifndef BLE_GATTC_H__
#define BLE_GATTC_H__ 
#include "ble_gatt.h"
#include "ble_types.h"
#include "ble_ranges.h"
#include "nrf_svc.h"
enum BLE_GATTC_SVCS
{
  SD_BLE_GATTC_PRIMARY_SERVICES_DISCOVER = BLE_GATTC_SVC_BASE,
  SD_BLE_GATTC_RELATIONSHIPS_DISCOVER,
  SD_BLE_GATTC_CHARACTERISTICS_DISCOVER,
  SD_BLE_GATTC_DESCRIPTORS_DISCOVER,
  SD_BLE_GATTC_CHAR_VALUE_BY_UUID_READ,
  SD_BLE_GATTC_READ,
  SD_BLE_GATTC_CHAR_VALUES_READ,
  SD_BLE_GATTC_WRITE,
  SD_BLE_GATTC_HV_CONFIRM
};
enum BLE_GATTC_EVTS
{
  BLE_GATTC_EVT_PRIM_SRVC_DISC_RSP = BLE_GATTC_EVT_BASE,
  BLE_GATTC_EVT_REL_DISC_RSP,
  BLE_GATTC_EVT_CHAR_DISC_RSP,
  BLE_GATTC_EVT_DESC_DISC_RSP,
  BLE_GATTC_EVT_CHAR_VAL_BY_UUID_READ_RSP,
  BLE_GATTC_EVT_READ_RSP,
  BLE_GATTC_EVT_CHAR_VALS_READ_RSP,
  BLE_GATTC_EVT_WRITE_RSP,
  BLE_GATTC_EVT_HVX,
  BLE_GATTC_EVT_TIMEOUT
};
#define BLE_ERROR_GATTC_PROC_NOT_PERMITTED (NRF_GATTC_ERR_BASE + 0x000)
#define BLE_GATTC_HANDLE_END 0xFFFF
typedef struct
{
  uint16_t start_handle;
  uint16_t end_handle;
} ble_gattc_handle_range_t;
typedef struct
{
  ble_uuid_t uuid;
  ble_gattc_handle_range_t handle_range;
} ble_gattc_service_t;
typedef struct
{
  uint16_t handle;
  ble_gattc_service_t included_srvc;
} ble_gattc_include_t;
typedef struct
{
  ble_uuid_t uuid;
  ble_gatt_char_props_t char_props;
  uint8_t char_ext_props : 1;
  uint16_t handle_decl;
  uint16_t handle_value;
} ble_gattc_char_t;
typedef struct
{
  uint16_t handle;
  ble_uuid_t uuid;
} ble_gattc_desc_t;
typedef struct
{
  uint8_t write_op;
  uint8_t flags;
  uint16_t handle;
  uint16_t offset;
  uint16_t len;
  uint8_t *p_value;
} ble_gattc_write_params_t;
typedef struct
{
  uint16_t count;
  ble_gattc_service_t services[1];
} ble_gattc_evt_prim_srvc_disc_rsp_t;
typedef struct
{
  uint16_t count;
  ble_gattc_include_t includes[1];
} ble_gattc_evt_rel_disc_rsp_t;
typedef struct
{
  uint16_t count;
  ble_gattc_char_t chars[1];
} ble_gattc_evt_char_disc_rsp_t;
typedef struct
{
  uint16_t count;
  ble_gattc_desc_t descs[1];
} ble_gattc_evt_desc_disc_rsp_t;
typedef struct
{
  uint16_t handle;
  uint8_t *p_value;
} ble_gattc_handle_value_t;
typedef struct
{
  uint16_t count;
  uint16_t value_len;
  ble_gattc_handle_value_t handle_value[1];
} ble_gattc_evt_char_val_by_uuid_read_rsp_t;
typedef struct
{
  uint16_t handle;
  uint16_t offset;
  uint16_t len;
  uint8_t data[1];
} ble_gattc_evt_read_rsp_t;
typedef struct
{
  uint16_t len;
  uint8_t values[1];
} ble_gattc_evt_char_vals_read_rsp_t;
typedef struct
{
  uint16_t handle;
  uint8_t write_op;
  uint16_t offset;
  uint16_t len;
  uint8_t data[1];
} ble_gattc_evt_write_rsp_t;
typedef struct
{
  uint16_t handle;
  uint8_t type;
  uint16_t len;
  uint8_t data[1];
} ble_gattc_evt_hvx_t;
typedef struct
{
  uint8_t src;
} ble_gattc_evt_timeout_t;
typedef struct
{
  uint16_t conn_handle;
  uint16_t gatt_status;
  uint16_t error_handle;
  union
  {
    ble_gattc_evt_prim_srvc_disc_rsp_t prim_srvc_disc_rsp;
    ble_gattc_evt_rel_disc_rsp_t rel_disc_rsp;
    ble_gattc_evt_char_disc_rsp_t char_disc_rsp;
    ble_gattc_evt_desc_disc_rsp_t desc_disc_rsp;
    ble_gattc_evt_char_val_by_uuid_read_rsp_t char_val_by_uuid_read_rsp;
    ble_gattc_evt_read_rsp_t read_rsp;
    ble_gattc_evt_char_vals_read_rsp_t char_vals_read_rsp;
    ble_gattc_evt_write_rsp_t write_rsp;
    ble_gattc_evt_hvx_t hvx;
    ble_gattc_evt_timeout_t timeout;
  } params;
} ble_gattc_evt_t;
SVCALL(SD_BLE_GATTC_PRIMARY_SERVICES_DISCOVER, uint32_t, sd_ble_gattc_primary_services_discover(uint16_t conn_handle, uint16_t start_handle, ble_uuid_t const *p_srvc_uuid));
SVCALL(SD_BLE_GATTC_RELATIONSHIPS_DISCOVER, uint32_t, sd_ble_gattc_relationships_discover(uint16_t conn_handle, ble_gattc_handle_range_t const *p_handle_range));
SVCALL(SD_BLE_GATTC_CHARACTERISTICS_DISCOVER, uint32_t, sd_ble_gattc_characteristics_discover(uint16_t conn_handle, ble_gattc_handle_range_t const *p_handle_range));
SVCALL(SD_BLE_GATTC_DESCRIPTORS_DISCOVER, uint32_t, sd_ble_gattc_descriptors_discover(uint16_t conn_handle, ble_gattc_handle_range_t const *p_handle_range));
SVCALL(SD_BLE_GATTC_CHAR_VALUE_BY_UUID_READ, uint32_t, sd_ble_gattc_char_value_by_uuid_read(uint16_t conn_handle, ble_uuid_t const *p_uuid, ble_gattc_handle_range_t const *p_handle_range));
SVCALL(SD_BLE_GATTC_READ, uint32_t, sd_ble_gattc_read(uint16_t conn_handle, uint16_t handle, uint16_t offset));
SVCALL(SD_BLE_GATTC_CHAR_VALUES_READ, uint32_t, sd_ble_gattc_char_values_read(uint16_t conn_handle, uint16_t const *p_handles, uint16_t handle_count));
SVCALL(SD_BLE_GATTC_WRITE, uint32_t, sd_ble_gattc_write(uint16_t conn_handle, ble_gattc_write_params_t const *p_write_params));
SVCALL(SD_BLE_GATTC_HV_CONFIRM, uint32_t, sd_ble_gattc_hv_confirm(uint16_t conn_handle, uint16_t handle));
#endif
