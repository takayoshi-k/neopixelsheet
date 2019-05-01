#include <stdlib.h>
#include "DebugTimer.h"

namespace SpresenseNeoPixel
{

static suseconds_t diff_time[DEBUG_TIME_SZ];

static struct timeval last_tval;

void init_time()
{
  gettimeofday(&last_tval, NULL);
}

void set_time_diff(int num)
{
  struct timeval val;
  if (num < DEBUG_TIME_SZ){
    gettimeofday(&val, NULL);
    diff_time[num] = val.tv_usec - last_tval.tv_usec;
    last_tval = val;
  }
}

suseconds_t get_difftime(int num)
{
  return diff_time[num];
}

}
