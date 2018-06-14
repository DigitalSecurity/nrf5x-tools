#ifndef BLE_L2CAP_H__
#define BLE_L2CAP_H__ 
#include "ble_types.h"
#include "ble_ranges.h"
#include "ble_err.h"
#include "nrf_svc.h"
enum BLE_L2CAP_SVCS
{
  SD_BLE_L2CAP_CID_REGISTER = BLE_L2CAP_SVC_BASE,
  SD_BLE_L2CAP_CID_UNREGISTER,
  SD_BLE_L2CAP_TX
};
#define BLE_ERROR_L2CAP_CID_IN_USE (NRF_L2CAP_ERR_BASE + 0x000)
#define BLE_L2CAP_MTU_DEF (23)
#define BLE_L2CAP_CID_INVALID (0x0000)
#define BLE_L2CAP_CID_DYN_BASE (0x0040)
#define BLE_L2CAP_CID_DYN_MAX (8)
typedef struct
{
  uint16_t len;
  uint16_t cid;
} ble_l2cap_header_t;
enum BLE_L2CAP_EVTS
{
  BLE_L2CAP_EVT_RX = BLE_L2CAP_EVT_BASE
};
typedef struct
{
  ble_l2cap_header_t header;
  uint8_t data[1];
} ble_l2cap_evt_rx_t;
typedef struct
{
  uint16_t conn_handle;
  union
  {
    ble_l2cap_evt_rx_t rx;
  } params;
} ble_l2cap_evt_t;
SVCALL(SD_BLE_L2CAP_CID_REGISTER, uint32_t, sd_ble_l2cap_cid_register(uint16_t cid));
SVCALL(SD_BLE_L2CAP_CID_UNREGISTER, uint32_t, sd_ble_l2cap_cid_unregister(uint16_t cid));
SVCALL(SD_BLE_L2CAP_TX, uint32_t, sd_ble_l2cap_tx(uint16_t conn_handle, ble_l2cap_header_t const * const p_header, uint8_t const * const p_data));
#endif
