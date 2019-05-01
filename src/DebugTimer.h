#ifndef __SPR_NEOPIXEL_DEBUG_TIMER_H__
#define __SPR_NEOPIXEL_DEBUG_TIMER_H__

#include <sys/time.h>

#define DEBUG_TIME_SZ (16)

namespace SpresenseNeoPixel
{
void set_time_diff(int num);
void init_time();
suseconds_t get_difftime(int num);
}


#endif  // __SPR_NEOPIXEL_DEBUG_TIMER_H__

