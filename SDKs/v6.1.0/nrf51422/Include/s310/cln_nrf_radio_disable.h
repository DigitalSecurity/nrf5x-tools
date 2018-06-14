#ifndef NRF_RADIO_DISABLE_H__
#define NRF_RADIO_DISABLE_H__ 
#include "nrf_soc.h"
#define NRF_RADIO_LENGTH_MIN_US (100)
#define NRF_RADIO_LENGTH_MAX_US (100000)
#define NRF_RADIO_DISTANCE_MAX_US (128000000UL - 1UL)
#define NRF_RADIO_START_JITTER_US (2)
#define SD_RADIO_SESSION_OPEN (SD_RESERVED1)
#define SD_RADIO_SESSION_CLOSE (SD_RESERVED2)
#define SD_RADIO_REQUEST (SD_RESERVED3)
#define NRF_EVT_RADIO_BLOCKED (NRF_EVT_RESERVED1)
#define NRF_EVT_RADIO_CANCELED (NRF_EVT_RESERVED2)
#define NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN (NRF_EVT_RESERVED3)
#define NRF_EVT_RADIO_SESSION_IDLE (NRF_EVT_RESERVED4)
#define NRF_EVT_RADIO_SESSION_CLOSED (NRF_EVT_RESERVED5)
enum NRF_RADIO_CALLBACK_SIGNAL_TYPE
{
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_START,
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_RESERVED1,
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_RESERVED2,
};
enum NRF_RADIO_SIGNAL_CALLBACK_ACTION
{
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_NONE,
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_END,
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_RESERVED1
};
enum NRF_RADIO_PRIORITY
{
  NRF_RADIO_PRIORITY_NORMAL,
  NRF_RADIO_PRIORITY_LOW,
};
typedef struct
{
   uint8_t nrf_radio_request_reserved1 : 1;
   uint8_t priority : 7;
   uint32_t distance_us;
   uint32_t length_us;
} nrf_radio_request_t;
typedef struct
{
  uint8_t return_code;
  nrf_radio_request_t * nrf_radio_signal_callback_return_param_reserved1;
} nrf_radio_signal_callback_return_param_t;
typedef nrf_radio_signal_callback_return_param_t * (*nrf_radio_signal_callback_t) (uint8_t signal_type);
 SVCALL(SD_RADIO_SESSION_OPEN, uint32_t, sd_radio_session_open
 (
   nrf_radio_signal_callback_t p_radio_signal_callback));
 SVCALL(SD_RADIO_SESSION_CLOSE, uint32_t, sd_radio_session_close(void));
 SVCALL(SD_RADIO_REQUEST, uint32_t, sd_radio_request
 (
   nrf_radio_request_t * p_request ));
#endif
