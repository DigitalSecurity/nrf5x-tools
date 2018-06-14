#ifndef NRF_SVC__
#define NRF_SVC__ 
#include "stdint.h"
#ifdef __cplusplus
extern "C" {
#endif
#ifdef SVCALL_AS_NORMAL_FUNCTION
#define SVCALL(number,return_type,signature) return_type signature
#else
#ifndef SVCALL
#if defined (__CC_ARM)
#define SVCALL(number,return_type,signature) return_type __svc(number) signature
#elif defined (__GNUC__)
#ifdef __cplusplus
#define GCC_CAST_CPP (uint16_t)
#else
#define GCC_CAST_CPP 
#endif
#define SVCALL(number,return_type,signature) \
  _Pragma("GCC diagnostic push") \
  _Pragma("GCC diagnostic ignored \"-Wreturn-type\"") \
  __attribute__((naked)) \
  __attribute__((unused)) \
  static return_type signature \
  { \
    __asm( \
        "svc %0\n" \
        "bx r14" : : "I" (GCC_CAST_CPP number) : "r0" \
    ); \
  } \
  _Pragma("GCC diagnostic pop")
#elif defined (__ICCARM__)
#define PRAGMA(x) _Pragma(#x)
#define SVCALL(number,return_type,signature) \
PRAGMA(swi_number = (number)) \
 __swi return_type signature;
#else
#define SVCALL(number,return_type,signature) return_type signature
#endif
#endif
#endif
#ifdef __cplusplus
}
#endif
#endif
