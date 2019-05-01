#ifndef __SPR_NEOPIXEL_FFTSCENE_H__
#define __SPR_NEOPIXEL_FFTSCENE_H__

#include "Scene.h"

namespace SpresenseNeoPixel
{

class FFTScene : public Scene<uint32_t> {
    private:
        static const int   DEFAULT_AVARAGE_STEP   = 8;
        static const int   DEFAULT_INDICATOR_UNIT = 4;
        static const float DEFAULT_BIAS_VALUE     = 1.0;

        int    avarage_step;
        float *fft_result;

        float bias_val;
        int indicator_unit;

        uint32_t pixcol[8];

    public:
        FFTScene() : Scene(),
                     avarage_step(DEFAULT_AVARAGE_STEP),
                     fft_result(NULL),
                     bias_val(DEFAULT_BIAS_VALUE),
                     indicator_unit(DEFAULT_INDICATOR_UNIT) {

            pixcol[0] = pixcol[1] = 0x00000202; // GRB = 00_80_80 = purple
            pixcol[2] = pixcol[3] = 0x00000003; // GRB = 00_00_80 = blue
            pixcol[4] = pixcol[5] = 0x00030300; // GRB = 80_80_00 = yellow
            pixcol[6]             = 0x00010300; // GRB = 80_80_00
            pixcol[7]             = 0x00000600; // GRB = 80_00_00
        };
        ~FFTScene() {};

        void setAvarageStep(int step) { avarage_step = step; };
        void setBias(float val) { bias_val = val; };
        void setIndicatorUnit(float val) { bias_val = val; };
        void updateFFT(float *result) { fft_result = result; };
        float simpleAvarage(float *fft_vals, int sz);

        void draw();
};

}

#endif  // __SPR_NEOPIXEL_FFTSCENE_H__

