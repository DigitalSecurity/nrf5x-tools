#ifndef ANT_INTERFACE_H__
#define ANT_INTERFACE_H__ 
#include <stdint.h>
#include <stdbool.h>
#include "nrf_svc.h"
#define STK_SVC_BASE_2 0xC0
enum {
  SVC_ANT_STACK_INIT = STK_SVC_BASE_2,
  SVC_ANT_EVENT_GET,
  SVC_ANT_CHANNEL_ASSIGN,
  SVC_ANT_CHANNEL_UNASSIGN,
  SVC_ANT_CHANNEL_OPEN,
  SVC_ANT_CHANNEL_CLOSE,
  SVC_ANT_RX_SCAN_MODE_START,
  SVC_ANT_TX_BROADCAST_MESSAGE,
  SVC_ANT_TX_ACKNOWLEDGED_MESSAGE,
  SVC_ANT_BURST_HANDLER_REQUEST,
  SVC_ANT_PENDING_TRANSMIT_CLEAR,
  SVC_ANT_TRANSFER_STOP,
  SVC_ANT_NETWORK_KEY_SET,
  SVC_ANT_CHANNEL_RADIO_FREQ_SET,
  SVC_ANT_CHANNEL_RADIO_FREQ_GET,
  SVC_ANT_CHANNEL_RADIO_TX_POWER_SET,
  SVC_ANT_PROX_SEARCH_SET,
  SVC_ANT_CHANNEL_PERIOD_SET,
  SVC_ANT_CHANNEL_PERIOD_GET,
  SVC_ANT_CHANNEL_ID_SET,
  SVC_ANT_CHANNEL_ID_GET,
  SVC_ANT_SEARCH_WAVEFORM_SET,
  SVC_ANT_CHANNEL_RX_SEARCH_TIMEOUT_SET,
  SVC_ANT_SEARCH_CHANNEL_PRIORITY_SET,
  SVC_ANT_ACTIVE_SEARCH_SHARING_CYCLES_SET,
  SVC_ANT_ACTIVE_SEARCH_SHARING_CYCLES_GET,
  SVC_ANT_CHANNEL_LOW_PRIO_RX_SEARCH_TIMEOUT_SET,
  SVC_ANT_ADV_BURST_CONFIG_SET,
  SVC_ANT_ADV_BURST_CONFIG_GET,
  SVC_ANT_LIB_CONFIG_SET,
  SVC_ANT_LIB_CONFIG_CLEAR,
  SVC_ANT_LIB_CONFIG_GET,
  SVC_ANT_ID_LIST_ADD,
  SVC_ANT_ID_LIST_CONFIG,
  SVC_ANT_AUTO_FREQ_HOP_TABLE_SET,
  SVC_ANT_EVENT_FILTERING_SET,
  SVC_ANT_EVENT_FILTERING_GET,
  SVC_ANT_ACTIVE,
  SVC_ANT_CHANNEL_IN_PROGRESS,
  SVC_ANT_CHANNEL_STATUS_GET,
  SVC_ANT_PENDING_TRANSMIT,
  SVC_ANT_INIT_CW_TEST_MODE,
  SVC_ANT_CW_TEST_MODE,
  SVC_ANT_VERSION,
  SVC_ANT_CAPABILITIES,
  SVC_ANT_BURST_HANDLER_WAIT_FLAG_ENABLE,
  SVC_ANT_BURST_HANDLER_WAIT_FLAG_DISABLE,
  SVC_ANT_SDU_MASK_SET,
  SVC_ANT_SDU_MASK_GET,
  SVC_ANT_SDU_MASK_CONFIG,
  SVC_ANT_CRYPTO_CHANNEL_ENABLE,
  SVC_ANT_CRYPTO_KEY_SET,
  SVC_ANT_CRYPTO_INFO_SET,
  SVC_ANT_CRYPTO_INFO_GET,
  SVC_ANT_RFACTIVE_NOTIFICATION_CONFIG_SET,
  SVC_ANT_RFACTIVE_NOTIFICATION_CONFIG_GET,
  SVC_ANT_COEX_CONFIG_SET,
  SVC_ANT_COEX_CONFIG_GET,
  SVC_ANT_RESERVED0,
  SVC_ANT_RESERVED1,
  SVC_ANT_RESERVED2,
  SVC_ANT_EXTENDED0,
  SVC_ANT_EXTENDED1,
  SVC_ANT_EXTENDED2,
};
SVCALL(SVC_ANT_STACK_INIT, uint32_t, sd_ant_stack_reset (void));
SVCALL(SVC_ANT_EVENT_GET, uint32_t, sd_ant_event_get (uint8_t *pucChannel, uint8_t *pucEvent, uint8_t *aucANTMesg));
SVCALL(SVC_ANT_CHANNEL_ASSIGN, uint32_t, sd_ant_channel_assign (uint8_t ucChannel, uint8_t ucChannelType, uint8_t ucNetwork, uint8_t ucExtAssign));
SVCALL(SVC_ANT_CHANNEL_UNASSIGN, uint32_t, sd_ant_channel_unassign (uint8_t ucChannel));
SVCALL(SVC_ANT_CHANNEL_OPEN, uint32_t, sd_ant_channel_open(uint8_t ucChannel));
SVCALL(SVC_ANT_CHANNEL_CLOSE, uint32_t, sd_ant_channel_close (uint8_t ucChannel));
SVCALL(SVC_ANT_RX_SCAN_MODE_START, uint32_t, sd_ant_rx_scan_mode_start (uint8_t ucSyncChannelPacketsOnly));
SVCALL(SVC_ANT_TX_BROADCAST_MESSAGE, uint32_t, sd_ant_broadcast_message_tx (uint8_t ucChannel, uint8_t ucSize, uint8_t *aucMesg));
SVCALL(SVC_ANT_TX_ACKNOWLEDGED_MESSAGE, uint32_t, sd_ant_acknowledge_message_tx (uint8_t ucChannel, uint8_t ucSize, uint8_t *aucMesg));
SVCALL(SVC_ANT_BURST_HANDLER_REQUEST, uint32_t, sd_ant_burst_handler_request(uint8_t ucChannel, uint16_t usSize, uint8_t *aucData, uint8_t ucBurstSegment));
SVCALL(SVC_ANT_PENDING_TRANSMIT_CLEAR, uint32_t, sd_ant_pending_transmit_clear (uint8_t ucChannel, uint8_t *pucSuccess));
SVCALL(SVC_ANT_TRANSFER_STOP, uint32_t, sd_ant_transfer_stop (void));
SVCALL(SVC_ANT_NETWORK_KEY_SET, uint32_t, sd_ant_network_address_set (uint8_t ucNetwork, uint8_t *aucNetworkKey));
SVCALL(SVC_ANT_CHANNEL_RADIO_FREQ_SET, uint32_t, sd_ant_channel_radio_freq_set (uint8_t ucChannel, uint8_t ucFreq));
SVCALL(SVC_ANT_CHANNEL_RADIO_FREQ_GET, uint32_t, sd_ant_channel_radio_freq_get (uint8_t ucChannel, uint8_t *pucRfreq));
SVCALL(SVC_ANT_CHANNEL_RADIO_TX_POWER_SET, uint32_t, sd_ant_channel_radio_tx_power_set (uint8_t ucChannel, uint8_t ucTxPower, uint8_t ucCustomTxPower));
SVCALL(SVC_ANT_PROX_SEARCH_SET, uint32_t, sd_ant_prox_search_set (uint8_t ucChannel, uint8_t ucProxThreshold, uint8_t ucCustomProxThreshold));
SVCALL(SVC_ANT_CHANNEL_PERIOD_SET, uint32_t, sd_ant_channel_period_set (uint8_t ucChannel, uint16_t usPeriod));
SVCALL(SVC_ANT_CHANNEL_PERIOD_GET, uint32_t, sd_ant_channel_period_get (uint8_t ucChannel, uint16_t *pusPeriod));
SVCALL(SVC_ANT_CHANNEL_ID_SET, uint32_t, sd_ant_channel_id_set (uint8_t ucChannel, uint16_t usDeviceNumber, uint8_t ucDeviceType, uint8_t ucTransmitType));
SVCALL(SVC_ANT_CHANNEL_ID_GET, uint32_t, sd_ant_channel_id_get (uint8_t ucChannel, uint16_t *pusDeviceNumber, uint8_t *pucDeviceType, uint8_t *pucTransmitType));
SVCALL(SVC_ANT_SEARCH_WAVEFORM_SET, uint32_t, sd_ant_search_waveform_set (uint8_t ucChannel, uint16_t usWaveform));
SVCALL(SVC_ANT_CHANNEL_RX_SEARCH_TIMEOUT_SET, uint32_t, sd_ant_channel_rx_search_timeout_set (uint8_t ucChannel, uint8_t ucTimeout));
SVCALL(SVC_ANT_SEARCH_CHANNEL_PRIORITY_SET, uint32_t, sd_ant_search_channel_priority_set (uint8_t ucChannel, uint8_t ucSearchPriority));
SVCALL(SVC_ANT_ACTIVE_SEARCH_SHARING_CYCLES_SET, uint32_t, sd_ant_active_search_sharing_cycles_set (uint8_t ucChannel, uint8_t ucCycles));
SVCALL(SVC_ANT_ACTIVE_SEARCH_SHARING_CYCLES_GET, uint32_t, sd_ant_active_search_sharing_cycles_get (uint8_t ucChannel, uint8_t *pucCycles));
SVCALL(SVC_ANT_CHANNEL_LOW_PRIO_RX_SEARCH_TIMEOUT_SET, uint32_t, sd_ant_channel_low_priority_rx_search_timeout_set (uint8_t ucChannel, uint8_t ucTimeout));
SVCALL(SVC_ANT_ADV_BURST_CONFIG_SET, uint32_t, sd_ant_adv_burst_config_set (uint8_t *aucConfig, uint8_t ucSize));
SVCALL(SVC_ANT_ADV_BURST_CONFIG_GET, uint32_t, sd_ant_adv_burst_config_get (uint8_t ucRequestType, uint8_t *aucConfig));
SVCALL(SVC_ANT_LIB_CONFIG_SET, uint32_t, sd_ant_lib_config_set (uint8_t ucANTLibConfig));
SVCALL(SVC_ANT_LIB_CONFIG_CLEAR, uint32_t, sd_ant_lib_config_clear (uint8_t ucANTLibConfig));
SVCALL(SVC_ANT_LIB_CONFIG_GET, uint32_t, sd_ant_lib_config_get (uint8_t *pucANTLibConfig));
SVCALL(SVC_ANT_ID_LIST_ADD, uint32_t, sd_ant_id_list_add (uint8_t ucChannel, uint8_t *aucDevId, uint8_t ucListIndex));
SVCALL(SVC_ANT_ID_LIST_CONFIG, uint32_t, sd_ant_id_list_config (uint8_t ucChannel, uint8_t ucIDListSize, uint8_t ucIncExcFlag));
SVCALL(SVC_ANT_AUTO_FREQ_HOP_TABLE_SET, uint32_t, sd_ant_auto_freq_hop_table_set (uint8_t ucChannel, uint8_t ucFreq0, uint8_t ucFreq1, uint8_t ucFreq2));
SVCALL(SVC_ANT_EVENT_FILTERING_SET, uint32_t, sd_ant_event_filtering_set (uint16_t usFilter));
SVCALL(SVC_ANT_EVENT_FILTERING_GET, uint32_t, sd_ant_event_filtering_get (uint16_t *pusFilter));
SVCALL(SVC_ANT_ACTIVE, uint32_t, sd_ant_active (uint8_t *pbAntActive));
SVCALL(SVC_ANT_CHANNEL_IN_PROGRESS, uint32_t, sd_ant_channel_in_progress (uint8_t *pbChannelInProgress));
SVCALL(SVC_ANT_CHANNEL_STATUS_GET, uint32_t, sd_ant_channel_status_get (uint8_t ucChannel, uint8_t *pucStatus));
SVCALL(SVC_ANT_PENDING_TRANSMIT, uint32_t, sd_ant_pending_transmit (uint8_t ucChannel, uint8_t *pucPending));
SVCALL(SVC_ANT_INIT_CW_TEST_MODE, uint32_t, sd_ant_cw_test_mode_init (void));
SVCALL(SVC_ANT_CW_TEST_MODE, uint32_t, sd_ant_cw_test_mode (uint8_t ucRadioFreq, uint8_t ucTxPower, uint8_t ucCustomTxPower, uint8_t ucMode));
SVCALL(SVC_ANT_VERSION, uint32_t, sd_ant_version_get (uint8_t* aucVersion));
SVCALL(SVC_ANT_CAPABILITIES, uint32_t, sd_ant_capabilities_get (uint8_t* aucCapabilities));
SVCALL(SVC_ANT_BURST_HANDLER_WAIT_FLAG_ENABLE, uint32_t, sd_ant_burst_handler_wait_flag_enable (uint8_t* pucWaitFlag));
SVCALL(SVC_ANT_BURST_HANDLER_WAIT_FLAG_DISABLE, uint32_t, sd_ant_burst_handler_wait_flag_disable (void));
SVCALL(SVC_ANT_SDU_MASK_SET, uint32_t, sd_ant_sdu_mask_set (uint8_t ucMask, uint8_t *aucMask));
SVCALL(SVC_ANT_SDU_MASK_GET, uint32_t, sd_ant_sdu_mask_get (uint8_t ucMask, uint8_t *aucMask));
SVCALL(SVC_ANT_SDU_MASK_CONFIG, uint32_t, sd_ant_sdu_mask_config (uint8_t ucChannel, uint8_t ucMaskConfig));
SVCALL(SVC_ANT_CRYPTO_CHANNEL_ENABLE, uint32_t, sd_ant_crypto_channel_enable (uint8_t ucChannel, uint8_t ucEnable, uint8_t ucKeyNum, uint8_t ucDecimationRate));
SVCALL(SVC_ANT_CRYPTO_KEY_SET, uint32_t, sd_ant_crypto_key_set (uint8_t ucKeyNum, uint8_t *aucKey));
SVCALL(SVC_ANT_CRYPTO_INFO_SET, uint32_t, sd_ant_crypto_info_set (uint8_t ucType, uint8_t *aucInfo));
SVCALL(SVC_ANT_CRYPTO_INFO_GET, uint32_t, sd_ant_crypto_info_get (uint8_t ucType, uint8_t *aucInfo));
SVCALL(SVC_ANT_RFACTIVE_NOTIFICATION_CONFIG_SET, uint32_t, sd_ant_rfactive_notification_config_set (uint8_t ucMode, uint16_t usTimeThreshold));
SVCALL(SVC_ANT_RFACTIVE_NOTIFICATION_CONFIG_GET, uint32_t, sd_ant_rfactive_notification_config_get (uint8_t *pucMode, uint16_t *pusTimeThreshold));
SVCALL(SVC_ANT_COEX_CONFIG_SET, uint32_t, sd_ant_coex_config_set (uint8_t ucChannel, uint8_t *aucCoexConfig, uint8_t *aucAdvCoexConfig));
SVCALL(SVC_ANT_COEX_CONFIG_GET, uint32_t, sd_ant_coex_config_get (uint8_t ucChannel, uint8_t *aucCoexConfig, uint8_t *aucAdvCoexConfig));
SVCALL(SVC_ANT_EXTENDED0, uint32_t, sd_ant_extended0 (uint8_t ucExtID, void *pvArg0, void *pvArg1, void *pvArg2));
#define SD_ANT_EXT0_ID_WAKEON_RF_ACTIVITY_CONFIG_SET 0x00
#define SD_ANT_EXT0_ID_WAKEON_RF_ACTIVITY_CONFIG_GET 0x01
#define SD_ANT_EXT0_ID_ENHANCED_CHANNEL_SPACING_SET 0x02
#endif
