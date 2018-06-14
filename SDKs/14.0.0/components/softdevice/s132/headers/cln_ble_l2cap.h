#ifndef BLE_L2CAP_H__
#define BLE_L2CAP_H__ 
#include "ble_types.h"
#include "ble_ranges.h"
#include "ble_err.h"
#include "nrf_svc.h"
#ifdef __cplusplus
extern "C" {
#endif
enum BLE_L2CAP_SVCS
{
  SD_BLE_L2CAP_CH_SETUP = BLE_L2CAP_SVC_BASE,
  SD_BLE_L2CAP_CH_RELEASE,
  SD_BLE_L2CAP_CH_RX,
  SD_BLE_L2CAP_CH_TX,
  SD_BLE_L2CAP_CH_FLOW_CONTROL,
};
enum BLE_L2CAP_EVTS
{
  BLE_L2CAP_EVT_CH_SETUP_REQUEST = BLE_L2CAP_EVT_BASE,
  BLE_L2CAP_EVT_CH_SETUP_REFUSED,
  BLE_L2CAP_EVT_CH_SETUP,
  BLE_L2CAP_EVT_CH_RELEASED,
  BLE_L2CAP_EVT_CH_SDU_BUF_RELEASED,
  BLE_L2CAP_EVT_CH_CREDIT,
  BLE_L2CAP_EVT_CH_RX,
  BLE_L2CAP_EVT_CH_TX,
};
#define BLE_L2CAP_CH_COUNT_MAX (64)
#define BLE_L2CAP_MTU_MIN (23)
#define BLE_L2CAP_MPS_MIN (23)
#define BLE_L2CAP_CID_INVALID (0x0000)
#define BLE_L2CAP_CREDITS_DEFAULT (1)
#define BLE_L2CAP_CH_SETUP_REFUSED_SRC_LOCAL (0x01)
#define BLE_L2CAP_CH_SETUP_REFUSED_SRC_REMOTE (0x02)
#define BLE_L2CAP_CH_STATUS_CODE_SUCCESS (0x0000)
#define BLE_L2CAP_CH_STATUS_CODE_LE_PSM_NOT_SUPPORTED (0x0002)
#define BLE_L2CAP_CH_STATUS_CODE_NO_RESOURCES (0x0004)
#define BLE_L2CAP_CH_STATUS_CODE_INSUFF_AUTHENTICATION (0x0005)
#define BLE_L2CAP_CH_STATUS_CODE_INSUFF_AUTHORIZATION (0x0006)
#define BLE_L2CAP_CH_STATUS_CODE_INSUFF_ENC_KEY_SIZE (0x0007)
#define BLE_L2CAP_CH_STATUS_CODE_INSUFF_ENC (0x0008)
#define BLE_L2CAP_CH_STATUS_CODE_INVALID_SCID (0x0009)
#define BLE_L2CAP_CH_STATUS_CODE_SCID_ALLOCATED (0x000A)
#define BLE_L2CAP_CH_STATUS_CODE_UNACCEPTABLE_PARAMS (0x000B)
#define BLE_L2CAP_CH_STATUS_CODE_NOT_UNDERSTOOD (0x8000)
#define BLE_L2CAP_CH_STATUS_CODE_TIMEOUT (0xC000)
typedef struct
{
  uint16_t rx_mps;
  uint16_t tx_mps;
  uint8_t rx_queue_size;
  uint8_t tx_queue_size;
  uint8_t ch_count;
} ble_l2cap_conn_cfg_t;
typedef struct
{
  uint16_t rx_mtu;
  uint16_t rx_mps;
  ble_data_t sdu_buf;
} ble_l2cap_ch_rx_params_t;
typedef struct
{
  ble_l2cap_ch_rx_params_t rx_params;
  uint16_t le_psm;
  uint16_t status;
} ble_l2cap_ch_setup_params_t;
typedef struct
{
  uint16_t tx_mtu;
  uint16_t peer_mps;
  uint16_t tx_mps;
  uint16_t credits;
} ble_l2cap_ch_tx_params_t;
typedef struct
{
  ble_l2cap_ch_tx_params_t tx_params;
  uint16_t le_psm;
} ble_l2cap_evt_ch_setup_request_t;
typedef struct
{
  uint8_t source;
  uint16_t status;
} ble_l2cap_evt_ch_setup_refused_t;
typedef struct
{
  ble_l2cap_ch_tx_params_t tx_params;
} ble_l2cap_evt_ch_setup_t;
typedef struct
{
  ble_data_t sdu_buf;
} ble_l2cap_evt_ch_sdu_buf_released_t;
typedef struct
{
  uint16_t credits;
} ble_l2cap_evt_ch_credit_t;
typedef struct
{
  uint16_t sdu_len;
  ble_data_t sdu_buf;
} ble_l2cap_evt_ch_rx_t;
typedef struct
{
  ble_data_t sdu_buf;
} ble_l2cap_evt_ch_tx_t;
typedef struct
{
  uint16_t conn_handle;
  uint16_t local_cid;
  union
  {
    ble_l2cap_evt_ch_setup_request_t ch_setup_request;
    ble_l2cap_evt_ch_setup_refused_t ch_setup_refused;
    ble_l2cap_evt_ch_setup_t ch_setup;
    ble_l2cap_evt_ch_sdu_buf_released_t ch_sdu_buf_released;
    ble_l2cap_evt_ch_credit_t credit;
    ble_l2cap_evt_ch_rx_t rx;
    ble_l2cap_evt_ch_tx_t tx;
  } params;
} ble_l2cap_evt_t;
SVCALL(SD_BLE_L2CAP_CH_SETUP, uint32_t, sd_ble_l2cap_ch_setup(uint16_t conn_handle, uint16_t *p_local_cid, ble_l2cap_ch_setup_params_t const *p_params));
SVCALL(SD_BLE_L2CAP_CH_RELEASE, uint32_t, sd_ble_l2cap_ch_release(uint16_t conn_handle, uint16_t local_cid));
SVCALL(SD_BLE_L2CAP_CH_RX, uint32_t, sd_ble_l2cap_ch_rx(uint16_t conn_handle, uint16_t local_cid, ble_data_t const *p_sdu_buf));
SVCALL(SD_BLE_L2CAP_CH_TX, uint32_t, sd_ble_l2cap_ch_tx(uint16_t conn_handle, uint16_t local_cid, ble_data_t const *p_sdu_buf));
SVCALL(SD_BLE_L2CAP_CH_FLOW_CONTROL, uint32_t, sd_ble_l2cap_ch_flow_control(uint16_t conn_handle, uint16_t local_cid, uint16_t credits, uint16_t *p_credits));
#ifdef __cplusplus
}
#endif
#endif
