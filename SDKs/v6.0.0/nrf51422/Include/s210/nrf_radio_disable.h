/* Copyright (c) 2013 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is confidential property of Nordic Semiconductor. The use,
 * copying, transfer or disclosure of such information is prohibited except by express written
 * agreement with Nordic Semiconductor.
 *
 */
 
/**
  @defgroup nrf_radio_disable_api NRF Radio Disable API
  @{
  
  @brief APIs for the NRF Radio Disable implementation.
  
*/

#ifndef NRF_RADIO_DISABLE_H__
#define NRF_RADIO_DISABLE_H__

#include "nrf_soc.h"

#define NRF_RADIO_LENGTH_MIN_US   (100)               /**< The shortest allowed radio disabled time, in microseconds. */
#define NRF_RADIO_LENGTH_MAX_US   (100000)            /**< The longest allowed radio disabled time, in microseconds. */

#define NRF_RADIO_DISTANCE_MAX_US (128000000UL - 1UL) /**< The longest allowed distance between the start of two consecutive radio disable requests, in microseconds. */

#define NRF_RADIO_START_JITTER_US (2)                 /**< The maximum jitter in NRF_RADIO_CALLBACK_SIGNAL_TYPE_START relative to the requested start time. */

/**@brief Redefinitions of the SVC numbers used by the NRF Radio Disable implementation. */
#define SD_RADIO_SESSION_OPEN     (SD_RESERVED1)
#define SD_RADIO_SESSION_CLOSE    (SD_RESERVED2)
#define SD_RADIO_REQUEST          (SD_RESERVED3)

#define NRF_EVT_RADIO_BLOCKED                        (NRF_EVT_RESERVED1) /**< Event indicating that a radio disabling was blocked. */
#define NRF_EVT_RADIO_CANCELED                       (NRF_EVT_RESERVED2) /**< Event indicating that a radio disabling was canceled by SoftDevice. */
#define NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN (NRF_EVT_RESERVED3) /**< Event indicating that a radio signal callback handler return was invalid. */
#define NRF_EVT_RADIO_SESSION_IDLE                   (NRF_EVT_RESERVED4) /**< Event indicating that a radio session is idle. */
#define NRF_EVT_RADIO_SESSION_CLOSED                 (NRF_EVT_RESERVED5) /**< Event indicating that a radio session is closed. */

/** @brief The Radio signal callback types. */
enum NRF_RADIO_CALLBACK_SIGNAL_TYPE
{
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_START,     /**< This signal indicates the start of the radio disabled period. */
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_RESERVED1, /**< Reserved for future use. */  
  NRF_RADIO_CALLBACK_SIGNAL_TYPE_RESERVED2, /**< Reserved for future use. */
};

/** @brief The actions requested by the signal callback.
 *
 *  This code gives the SOC instructions about what action to take when the signal callback has
 *  returned.
 */
enum NRF_RADIO_SIGNAL_CALLBACK_ACTION
{
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_NONE,            /**< Return without action. */
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_END,             /**< End the current radio disabled period. */
  NRF_RADIO_SIGNAL_CALLBACK_ACTION_RESERVED1        /**< Reserved for future use. */
};

/** @brief Radio Disable feature priorities. */
enum NRF_RADIO_PRIORITY
{
  NRF_RADIO_PRIORITY_NORMAL,   /**< Normal priority. */
  NRF_RADIO_PRIORITY_LOW,      /**< Low priority. */
};

/** @brief Radio disable request parameters. */
typedef struct
{
   uint8_t   nrf_radio_request_reserved1 : 1;   /**< Reserved for future use. Shall be false. */
   uint8_t   priority : 7;                      /**< The radio disable period priority. */
   uint32_t  distance_us;                       /**< Distance from the previous radio disable period. Shall be in the range [0..NRF_RADIO_DISTANCE_MAX_US] microseconds, but must always be zero for the first request of a session. */
   uint32_t  length_us;                         /**< The radio disable period length (in the range [100..100,000] microseconds). */
} nrf_radio_request_t;

/** @brief The signal callback return parameters. */
typedef struct
{
  uint8_t              return_code;                                        /**< The return code. */
  nrf_radio_request_t  * nrf_radio_signal_callback_return_param_reserved1; /**< Reserved for future use. Shall be NULL. */
} nrf_radio_signal_callback_return_param_t;

/** @brief The radio signal callback type.
 *
 *  @note In case of invalid return parameters, the  NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN event will be sent.
 */
typedef nrf_radio_signal_callback_return_param_t * (*nrf_radio_signal_callback_t) (uint8_t signal_type);

/**@brief Opens a session for radio disable requests.
 *
 * @note Only one session can be open at a time.
 * @note p_radio_signal_callback(NRF_RADIO_CALLBACK_SIGNAL_TYPE_START) will be called when the radio disable period
 *       starts.
 * @note p_radio_signal_callback() will be called at ARM interrupt priority level 0. This
 *       implies that none of the sd_* API calls can be used from p_radio_signal_callback().
 *
 * @param[in] p_radio_signal_callback The signal callback.
 *
 * @retval ::NRF_ERROR_INVALID_ADDR p_radio_signal_callback is an invalid function pointer.
 * @retval ::NRF_ERROR_BUSY If session cannot be opened.
 * @retval ::NRF_ERROR_INTERNAL If a new session could not be opened due to an internal error.
 * @retval ::NRF_SUCCESS Otherwise.
 */
 SVCALL(SD_RADIO_SESSION_OPEN, uint32_t, sd_radio_session_open
 (
   nrf_radio_signal_callback_t p_radio_signal_callback));

/**@brief Closes a session for radio disable requests.
 *
 * @note Any current radio disable period will be finished before the session is closed.
 * @note If a radio disable period is scheduled when the session is closed, it will be canceled.
 * @note The application cannot consider the session closed until the NRF_EVT_RADIO_SESSION_CLOSED
 *       event is received.
 *
 * @retval ::NRF_ERROR_FORBIDDEN If session not opened.
 * @retval ::NRF_ERROR_BUSY If session is currently being closed.
 * @retval ::NRF_SUCCESS Otherwise.
 */
 SVCALL(SD_RADIO_SESSION_CLOSE, uint32_t, sd_radio_session_close(void));

 /**@brief Requests a radio disable period.
 *
 * @note The timing of the radio disable period is specified by p_request->distance_us. For the first
 *       request in a session, p_request->distance_us is required to be 0 by convention, and
 *       the disable period is scheduled at the first possible opportunity. All following radio disable periods are
 *       requested with a distance of p_request->distance_us measured from the start of the
 *       previous radio disable period.
 * @note A too small p_request->distance_us will lead to a NRF_EVT_RADIO_BLOCKED event.
 * @note Radio disable periods scheduled too close will lead to a NRF_EVT_RADIO_BLOCKED event.
 * @note If an opportunity for the first radio disable period is not found before 100ms after the call to this
 *       function, it is not scheduled, and instead a NRF_EVT_RADIO_BLOCKED event is sent.
 *       The application may then try to schedule the first radio disable period again.
 * @note Successful requests will result in nrf_radio_signal_callback_t(NRF_RADIO_CALLBACK_SIGNAL_TYPE_START).
 *       Unsuccessful requests will result in a NRF_EVT_RADIO_BLOCKED event, see @ref NRF_SOC_EVTS.
 * @note The jitter in the start time of the radio disable period is +/- NRF_RADIO_START_JITTER_US us.
 * @note The nrf_radio_signal_callback_t(NRF_RADIO_CALLBACK_SIGNAL_TYPE_START) call has a latency relative to the
 *       specified radio disable period start, but this does not affect the actual start time of the disable period.
 * @note The SoftDevice will not access the NRF_RADIO peripheral during the radio disable period.
 *
 * @param[in] p_request Pointer to the request parameters.
 *
 * @retval ::NRF_ERROR_FORBIDDEN If session not opened or the session is not IDLE.
 * @retval ::NRF_ERROR_INVALID_ADDR If the p_request pointer is invalid.
 * @retval ::NRF_ERROR_INVALID_PARAM If the parameters of p_request are not valid.
 * @retval ::NRF_SUCCESS Otherwise.
 */
 SVCALL(SD_RADIO_REQUEST, uint32_t, sd_radio_request
 (
   nrf_radio_request_t * p_request ));

/** @} */

#endif // NRF_RADIO_DISABLE_H__

/**
  @}
 */
