#include "FFTScene.h"

namespace SpresenseNeoPixel
{
#ifdef DEBUG_TIME
suseconds_t diff_time[DEBUG_TIME_SZ];
static struct timeval last_tval;
static void init_time()
{
  gettimeofday(&last_tval, NULL);
}
static void set_time_diff(int num)
{
  struct timeval val;
  gettimeofday(&val, NULL);
  diff_time[num] = val.tv_usec - last_tval.tv_usec;
  last_tval = val;
}
#endif

float FFTScene::simpleAvarage(float *fft_vals, int sz)
{
    float ttl = 0;

    for(int i=0; i<sz; i++){
        ttl += *fft_vals++;
    }
    ttl /= sz;

    return ttl;
}

void FFTScene::draw()
{
    float fft_avgval;
    int avg_sz;
    int start_pos = 0;
    int pix_val;

    int pix_quantam = 4;
    
    uint32_t col;

#ifdef DEBUG_TIME
    init_time();
#endif

    if( fft_result && render_target ){
        for(int x=0; x<(int)render_target->getWidth(); x++) {
            avg_sz = avarage_step;
            start_pos = x * avarage_step - (avarage_step / 2);
            if (start_pos < 0) {
                avg_sz += start_pos;
                start_pos = 0;
            }
            fft_avgval = simpleAvarage(&fft_result[start_pos], avg_sz);
            // pix_val = (int)(fft_avgval * 10); // Bias
            pix_val = (int)fft_avgval;
            pix_val = (pix_val + pix_quantam - 1) / pix_quantam;

            for(int y=0; y<(int)render_target->getHeight(); y++) {
                col = ( pix_val > y ) ? pixcol[y] : 0x00000000;
                render_target->setPixel(x, y, &col);
            }

        }
    }

#ifdef DEBUG_TIME
    set_time_diff(0);
#endif

    render_target->scanout();

#ifdef DEBUG_TIME
    set_time_diff(1);
#endif
}

}

