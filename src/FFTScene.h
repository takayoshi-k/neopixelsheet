#ifndef __SPR_NEOPIXEL_FFTSCENE_H__
#define __SPR_NEOPIXEL_FFTSCENE_H__

#include "Scene.h"

#define DEBUG_TIME
#ifdef DEBUG_TIME
#include <sys/time.h>
#endif

namespace SpresenseNeoPixel
{

#ifdef DEBUG_TIME
#define DEBUG_TIME_SZ (16)
extern suseconds_t diff_time[DEBUG_TIME_SZ];
#endif

class FFTScene : public Scene<uint32_t> {
    private:
        static const int DEFAULT_AVARAGE_STEP = 8;

        int    avarage_step;
        float *fft_result;

        uint32_t pixcol[8];

    public:
        FFTScene() : Scene(), avarage_step(DEFAULT_AVARAGE_STEP), fft_result(NULL) {
            pixcol[0] = pixcol[1] = 0x00000202; // GRB = 00_80_80 = purple
            pixcol[2] = pixcol[3] = 0x00000003; // GRB = 00_00_80 = blue
            pixcol[4] = pixcol[5] = 0x00030300; // GRB = 80_80_00 = yellow
            pixcol[6]             = 0x00010300; // GRB = 80_80_00
            pixcol[7]             = 0x00000600; // GRB = 80_00_00
        };
        ~FFTScene() {};

        void setAvarageStep(int step) { avarage_step = step; };
        void updateFFT(float *result) { fft_result = result; };
        float simpleAvarage(float *fft_vals, int sz);

        void draw();
};

}

#endif  // __SPR_NEOPIXEL_FFTSCENE_H__

