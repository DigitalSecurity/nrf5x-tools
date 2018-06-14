/* Copyright (c) 2015 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

#ifndef NRF_SD_DEF_H__
#define NRF_SD_DEF_H__

#include <stdint.h>

#define NRF_PPI_RESTRICTED              0                        /**< 1 if PPI peripheral is restricted, 0 otherwise. */
#define NRF_PPI_ALL_APP_CHANNELS_MASK   ((uint32_t)0x00003FFFuL) /**< All PPI channels available to the application. */
#define NRF_PPI_PROG_APP_CHANNELS_MASK  ((uint32_t)0x00003FFFuL) /**< Programmable PPI channels available to the application. */
#define NRF_PPI_ALL_APP_GROUPS_MASK     ((uint32_t)0x00000003uL) /**< All PPI groups available to the application. */

#endif /* NRF_SD_DEF_H__ */
