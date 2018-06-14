#ifndef SOFTDEVICE_ASSERT_H_
#define SOFTDEVICE_ASSERT_H_ 
#include <stdint.h>
void assert_softdevice_callback(uint16_t line_num, const uint8_t *file_name);
                                                                                             \
#define ASSERT(expr) \
if (expr) \
{ \
} \
else \
{ \
  assert_softdevice_callback((uint16_t)__LINE__, (uint8_t *)__FILE__); \
                                                                              \
}
#endif
