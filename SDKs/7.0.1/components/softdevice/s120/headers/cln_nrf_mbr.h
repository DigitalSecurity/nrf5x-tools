#ifndef NRF_MBR_H__
#define NRF_MBR_H__ 
#include "nrf_svc.h"
#include <stdint.h>
#define MBR_SVC_BASE 0x18
enum NRF_MBR_SVCS
{
  SD_MBR_COMMAND = MBR_SVC_BASE,
};
enum NRF_MBR_COMMANDS
{
  SD_MBR_COMMAND_COPY_BL,
  SD_MBR_COMMAND_COPY_SD,
  SD_MBR_COMMAND_INIT_SD,
  SD_MBR_COMMAND_COMPARE,
};
typedef struct
{
  uint32_t *src;
  uint32_t *dst;
  uint32_t len;
}sd_mbr_command_copy_sd_t;
typedef struct
{
  uint32_t *ptr1;
  uint32_t *ptr2;
  uint32_t len;
}sd_mbr_command_compare_t;
typedef struct
{
  uint32_t *bl_src;
  uint32_t bl_len;
}sd_mbr_command_copy_bl_t;
typedef struct
{
  uint32_t command;
  union
  {
    sd_mbr_command_copy_sd_t copy_sd;
    sd_mbr_command_copy_bl_t copy_bl;
    sd_mbr_command_compare_t compare;
  } params;
}sd_mbr_command_t;
SVCALL(SD_MBR_COMMAND, uint32_t, sd_mbr_command(sd_mbr_command_t* param));
#endif
