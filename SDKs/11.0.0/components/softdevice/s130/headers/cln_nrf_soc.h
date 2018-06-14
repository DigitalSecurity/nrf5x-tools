#ifndef NRF_SOC_H__
#define NRF_SOC_H__ 
#include <stdint.h>
#include <stdbool.h>
#include "nrf_svc.h"
#include "nrf.h"
#include "nrf_error_soc.h"
#ifdef __cplusplus
extern "C" {
#endif
#define SOC_SVC_BASE (0x20)
#define SOC_SVC_BASE_NOT_AVAILABLE (0x2B)
#define NRF_RADIO_NOTIFICATION_INACTIVE_GUARANTEED_TIME_US (62)
#define NRF_RADIO_MINIMUM_TIMESLOT_LENGTH_EXTENSION_TIME_US (200)
#define SOC_ECB_KEY_LENGTH (16)
#define SOC_ECB_CLEARTEXT_LENGTH (16)
#define SOC_ECB_CIPHERTEXT_LENGTH (SOC_ECB_CLEARTEXT_LENGTH)
#ifdef NRF51
#define SD_EVT_IRQn (SWI2_IRQn)
#define SD_EVT_IRQHandler (SWI2_IRQHandler)
#define RADIO_NOTIFICATION_IRQn (SWI1_IRQn)
#define RADIO_NOTIFICATION_IRQHandler (SWI1_IRQHandler)
#endif
#ifdef NRF52
#define SD_EVT_IRQn (SWI2_EGU2_IRQn)
#define SD_EVT_IRQHandler (SWI2_EGU2_IRQHandler)
#define RADIO_NOTIFICATION_IRQn (SWI1_EGU1_IRQn)
#define RADIO_NOTIFICATION_IRQHandler (SWI1_EGU1_IRQHandler)
#endif
#define NRF_RADIO_LENGTH_MIN_US (100)
#define NRF_RADIO_LENGTH_MAX_US (100000)
#define NRF_RADIO_DISTANCE_MAX_US (128000000UL - 1UL)
#define NRF_RADIO_EARLIEST_TIMEOUT_MAX_US (128000000UL - 1UL)
#define NRF_RADIO_START_JITTER_US (2)
enum NRF_SOC_SVCS
{
  SD_PPI_CHANNEL_ENABLE_GET = SOC_SVC_BASE,
  SD_PPI_CHANNEL_ENABLE_SET,
  SD_PPI_CHANNEL_ENABLE_CLR,
  SD_PPI_CHANNEL_ASSIGN,
  SD_PPI_GROUP_TASK_ENABLE,
  SD_PPI_GROUP_TASK_DISABLE,
  SD_PPI_GROUP_ASSIGN,
  SD_PPI_GROUP_GET,
  SD_FLASH_PAGE_ERASE,
  SD_FLASH_WRITE,
  SD_FLASH_PROTECT,
  SD_MUTEX_NEW = SOC_SVC_BASE_NOT_AVAILABLE,
  SD_MUTEX_ACQUIRE,
  SD_MUTEX_RELEASE,
  SD_RFU_1,
  SD_RFU_2,
  SD_RFU_3,
  SD_RFU_4,
  SD_RFU_5,
  SD_RFU_6,
  SD_RFU_7,
  SD_RFU_8,
  SD_RFU_9,
  SD_RFU_10,
  SD_RAND_APPLICATION_POOL_CAPACITY_GET,
  SD_RAND_APPLICATION_BYTES_AVAILABLE_GET,
  SD_RAND_APPLICATION_VECTOR_GET,
  SD_POWER_MODE_SET,
  SD_POWER_SYSTEM_OFF,
  SD_POWER_RESET_REASON_GET,
  SD_POWER_RESET_REASON_CLR,
  SD_POWER_POF_ENABLE,
  SD_POWER_POF_THRESHOLD_SET,
  SD_POWER_RAMON_SET,
  SD_POWER_RAMON_CLR,
  SD_POWER_RAMON_GET,
  SD_POWER_GPREGRET_SET,
  SD_POWER_GPREGRET_CLR,
  SD_POWER_GPREGRET_GET,
  SD_POWER_DCDC_MODE_SET,
  SD_APP_EVT_WAIT,
  SD_CLOCK_HFCLK_REQUEST,
  SD_CLOCK_HFCLK_RELEASE,
  SD_CLOCK_HFCLK_IS_RUNNING,
  SD_RADIO_NOTIFICATION_CFG_SET,
  SD_ECB_BLOCK_ENCRYPT,
  SD_ECB_BLOCKS_ENCRYPT,
  SD_RADIO_SESSION_OPEN,
  SD_RADIO_SESSION_CLOSE,
  SD_RADIO_REQUEST,
  SD_EVT_GET,
  SD_TEMP_GET,
  SVC_SOC_LAST
};
enum NRF_MUTEX_VALUES
{
  NRF_MUTEX_FREE,
  NRF_MUTEX_TAKEN
};
enum NRF_POWER_MODES
{
  NRF_POWER_MODE_CONSTLAT,
  NRF_POWER_MODE_LOWPWR
};
enum NRF_POWER_THRESHOLDS
{
  NRF_POWER_THRESHOLD_V21,
  NRF_POWER_THRESHOLD_V23,
  NRF_POWER_THRESHOLD_V25,
  NRF_POWER_THRESHOLD_V27
};
enum NRF_POWER_DCDC_MODES
{
  NRF_POWER_DCDC_DISABLE,
  NRF_POWER_DCDC_ENABLE
};
enum NRF_RADIO_NOTIFICATION_DISTANCES
{
  NRF_RADIO_NOTIFICATION_DISTANCE_NONE = 0,
  NRF_RADIO_NOTIFICATION_DISTANCE_800US,
  NRF_RADIO_NOTIFICATION_DISTANCE_1740US,
  NRF_RADIO_NOTIFICATION_DISTANCE_2680US,
  NRF_RADIO_NOTIFICATION_DISTANCE_3620US,
  NRF_RADIO_NOTIFICATION_DISTANCE_4560US,
  NRF_RADIO_NOTIFICATION_DISTANCE_5500US
};
enum NRF_RADIO_NOTIFICATION_TYPES
{
  NRF_RADIO_NOTIFICATION_TYPE_NONE = 0,
  NRF_RADIO_NOTIFICATION_TYPE_INT_ON_ACTIVE,
  NRF_RADIO_NOTIFICATION_TYPE_INT_ON_INACTIVE,
  NRF_RADIO_NOTIFICATION_TYPE_INT_ON_BOTH,
};
enum NRF_RADIO_CALLBACK_SIGNAL_TYPE
{
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_START,
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_TIMER0,
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_RADIO,
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_EXTEND_FAILED,
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_EXTEND_SUCCEEDED
};
enum NRF_RADIO_SIGNAL_CALLBACK_ACTION
{
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_NONE,
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_EXTEND,
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_END,
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_REQUEST_AND_END
};
enum NRF_RADIO_HFCLK_CFG
{
  NRF_RADIO_HFCLK_CFG_XTAL_GUARANTEED,
  NRF_RADIO_HFCLK_CFG_NO_GUARANTEE
};
enum NRF_RADIO_PRIORITY
{
  NRF_RADIO_PRIORITY_HIGH,
  NRF_RADIO_PRIORITY_NORMAL,
};
enum NRF_RADIO_REQUEST_TYPE
{
  NRF_RADIO_REQ_TYPE_EARLIEST,
  NRF_RADIO_REQ_TYPE_NORMAL
};
enum NRF_SOC_EVTS
{
  NRF_EVT_HFCLKSTARTED,
  NRF_EVT_POWER_FAILURE_WARNING,
  NRF_EVT_FLASH_OPERATION_SUCCESS,
  NRF_EVT_FLASH_OPERATION_ERROR,
  NRF_EVT_RADIO_BLOCKED,
  NRF_EVT_RADIO_CANCELED,
  NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN,
  NRF_EVT_RADIO_SESSION_IDLE,
  NRF_EVT_RADIO_SESSION_CLOSED,
  NRF_EVT_NUMBER_OF_EVTS
};
typedef volatile uint8_t nrf_mutex_t;
typedef struct
{
  uint8_t hfclk;
  uint8_t priority;
  uint32_t length_us;
  uint32_t timeout_us;
} nrf_radio_request_earliest_t;
typedef struct
{
  uint8_t hfclk;
  uint8_t priority;
  uint32_t distance_us;
  uint32_t length_us;
} nrf_radio_request_normal_t;
typedef struct
{
  uint8_t request_type;
  union
  {
    nrf_radio_request_earliest_t earliest;
    nrf_radio_request_normal_t normal;
  } params;
} nrf_radio_request_t;
typedef struct
{
  uint8_t callback_action;
  union
  {
    struct
    {
      nrf_radio_request_t * p_next;
    } request;
    struct
    {
      uint32_t length_us;
    } extend;
  } params;
} nrf_radio_signal_callback_return_param_t;
typedef nrf_radio_signal_callback_return_param_t * (*nrf_radio_signal_callback_t) (uint8_t signal_type);
typedef uint8_t soc_ecb_key_t[SOC_ECB_KEY_LENGTH];
typedef uint8_t soc_ecb_cleartext_t[SOC_ECB_CLEARTEXT_LENGTH];
typedef uint8_t soc_ecb_ciphertext_t[SOC_ECB_CIPHERTEXT_LENGTH];
typedef struct
{
  soc_ecb_key_t key;
  soc_ecb_cleartext_t cleartext;
  soc_ecb_ciphertext_t ciphertext;
} nrf_ecb_hal_data_t;
typedef struct
{
  soc_ecb_key_t* p_key;
  soc_ecb_cleartext_t* p_cleartext;
  soc_ecb_ciphertext_t* p_ciphertext;
} nrf_ecb_hal_data_block_t;
SVCALL(SD_MUTEX_NEW, uint32_t, sd_mutex_new(nrf_mutex_t * p_mutex));
SVCALL(SD_MUTEX_ACQUIRE, uint32_t, sd_mutex_acquire(nrf_mutex_t * p_mutex));
SVCALL(SD_MUTEX_RELEASE, uint32_t, sd_mutex_release(nrf_mutex_t * p_mutex));
SVCALL(SD_RAND_APPLICATION_POOL_CAPACITY_GET, uint32_t, sd_rand_application_pool_capacity_get(uint8_t * p_pool_capacity));
SVCALL(SD_RAND_APPLICATION_BYTES_AVAILABLE_GET, uint32_t, sd_rand_application_bytes_available_get(uint8_t * p_bytes_available));
SVCALL(SD_RAND_APPLICATION_VECTOR_GET, uint32_t, sd_rand_application_vector_get(uint8_t * p_buff, uint8_t length));
SVCALL(SD_POWER_RESET_REASON_GET, uint32_t, sd_power_reset_reason_get(uint32_t * p_reset_reason));
SVCALL(SD_POWER_RESET_REASON_CLR, uint32_t, sd_power_reset_reason_clr(uint32_t reset_reason_clr_msk));
SVCALL(SD_POWER_MODE_SET, uint32_t, sd_power_mode_set(uint8_t power_mode));
SVCALL(SD_POWER_SYSTEM_OFF, uint32_t, sd_power_system_off(void));
SVCALL(SD_POWER_POF_ENABLE, uint32_t, sd_power_pof_enable(uint8_t pof_enable));
SVCALL(SD_POWER_POF_THRESHOLD_SET, uint32_t, sd_power_pof_threshold_set(uint8_t threshold));
SVCALL(SD_POWER_RAMON_SET, uint32_t, sd_power_ramon_set(uint32_t ramon));
SVCALL(SD_POWER_RAMON_CLR, uint32_t, sd_power_ramon_clr(uint32_t ramon));
SVCALL(SD_POWER_RAMON_GET, uint32_t, sd_power_ramon_get(uint32_t * p_ramon));
SVCALL(SD_POWER_GPREGRET_SET, uint32_t, sd_power_gpregret_set(uint32_t gpregret_msk));
SVCALL(SD_POWER_GPREGRET_CLR, uint32_t, sd_power_gpregret_clr(uint32_t gpregret_msk));
SVCALL(SD_POWER_GPREGRET_GET, uint32_t, sd_power_gpregret_get(uint32_t *p_gpregret));
SVCALL(SD_POWER_DCDC_MODE_SET, uint32_t, sd_power_dcdc_mode_set(uint8_t dcdc_mode));
SVCALL(SD_CLOCK_HFCLK_REQUEST, uint32_t, sd_clock_hfclk_request(void));
SVCALL(SD_CLOCK_HFCLK_RELEASE, uint32_t, sd_clock_hfclk_release(void));
SVCALL(SD_CLOCK_HFCLK_IS_RUNNING, uint32_t, sd_clock_hfclk_is_running(uint32_t * p_is_running));
SVCALL(SD_APP_EVT_WAIT, uint32_t, sd_app_evt_wait(void));
SVCALL(SD_PPI_CHANNEL_ENABLE_GET, uint32_t, sd_ppi_channel_enable_get(uint32_t * p_channel_enable));
SVCALL(SD_PPI_CHANNEL_ENABLE_SET, uint32_t, sd_ppi_channel_enable_set(uint32_t channel_enable_set_msk));
SVCALL(SD_PPI_CHANNEL_ENABLE_CLR, uint32_t, sd_ppi_channel_enable_clr(uint32_t channel_enable_clr_msk));
SVCALL(SD_PPI_CHANNEL_ASSIGN, uint32_t, sd_ppi_channel_assign(uint8_t channel_num, const volatile void * evt_endpoint, const volatile void * task_endpoint));
SVCALL(SD_PPI_GROUP_TASK_ENABLE, uint32_t, sd_ppi_group_task_enable(uint8_t group_num));
SVCALL(SD_PPI_GROUP_TASK_DISABLE, uint32_t, sd_ppi_group_task_disable(uint8_t group_num));
SVCALL(SD_PPI_GROUP_ASSIGN, uint32_t, sd_ppi_group_assign(uint8_t group_num, uint32_t channel_msk));
SVCALL(SD_PPI_GROUP_GET, uint32_t, sd_ppi_group_get(uint8_t group_num, uint32_t * p_channel_msk));
SVCALL(SD_RADIO_NOTIFICATION_CFG_SET, uint32_t, sd_radio_notification_cfg_set(uint8_t type, uint8_t distance));
SVCALL(SD_ECB_BLOCK_ENCRYPT, uint32_t, sd_ecb_block_encrypt(nrf_ecb_hal_data_t * p_ecb_data));
SVCALL(SD_ECB_BLOCKS_ENCRYPT, uint32_t, sd_ecb_blocks_encrypt(uint8_t block_count, nrf_ecb_hal_data_block_t * p_data_blocks));
SVCALL(SD_EVT_GET, uint32_t, sd_evt_get(uint32_t * p_evt_id));
SVCALL(SD_TEMP_GET, uint32_t, sd_temp_get(int32_t * p_temp));
SVCALL(SD_FLASH_WRITE, uint32_t, sd_flash_write(uint32_t * const p_dst, uint32_t const * const p_src, uint32_t size));
SVCALL(SD_FLASH_PAGE_ERASE, uint32_t, sd_flash_page_erase(uint32_t page_number));
SVCALL(SD_FLASH_PROTECT, uint32_t, sd_flash_protect(uint32_t block_cfg0, uint32_t block_cfg1, uint32_t block_cfg2, uint32_t block_cfg3));
 SVCALL(SD_RADIO_SESSION_OPEN, uint32_t, sd_radio_session_open(nrf_radio_signal_callback_t p_radio_signal_callback));
 SVCALL(SD_RADIO_SESSION_CLOSE, uint32_t, sd_radio_session_close(void));
 SVCALL(SD_RADIO_REQUEST, uint32_t, sd_radio_request(nrf_radio_request_t * p_request ));
#ifdef __cplusplus
}
#endif
#endif
