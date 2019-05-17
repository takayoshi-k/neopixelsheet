#ifndef __SPR_NEOPIXEL_FFTSCENE_H__
#define __SPR_NEOPIXEL_FFTSCENE_H__

#include "Scene.h"

namespace SpresenseNeoPixel
{

class FFTScene : public Scene<uint32_t> {
    protected:
        static const int   DEFAULT_AVARAGE_STEP   = 8;
        static const int   DEFAULT_INDICATOR_UNIT = 4;
        static const float DEFAULT_BIAS_VALUE     = 1.0;
        static const int   LEVEL_GROUP_NUM = 5;

        int    avarage_step;
        float *fft_result;

        float bias_val;
        int indicator_unit;

        uint32_t pixcol[8];

        int level_group[LEVEL_GROUP_NUM];
        bool isOverride;

    public:
        FFTScene() : Scene(),
                     avarage_step(DEFAULT_AVARAGE_STEP),
                     fft_result(NULL),
                     bias_val(DEFAULT_BIAS_VALUE),
                     indicator_unit(DEFAULT_INDICATOR_UNIT),
                     isOverride(true) {

            level_group[0] = 2;
            level_group[1] = 4;
            level_group[2] = 6;
            level_group[3] = 7;
            level_group[4] = 8;

            // Set default colors.
            setLevelColor(0, 0x00000202); // GRB = 00_80_80 = purple
            setLevelColor(1, 0x00000003); // GRB = 00_00_80 = blue
            setLevelColor(2, 0x00030300); // GRB = 80_80_00 = yellow
            setLevelColor(3, 0x00010300); // GRB = 40_80_00 = orange
            setLevelColor(4, 0x00000600); // GRB = 00_80_00 = red
        };
        ~FFTScene() {};

        void setOverrideMode(bool enable) { isOverride = enable; };
        void setLevelColor(int level, uint32_t col);
        void setAvarageStep(int step) { avarage_step = step; };
        void setBias(float val) { bias_val = val; };
        void setIndicatorUnit(float val) { bias_val = val; };
        void updateFFT(float *result) { fft_result = result; };
        float simpleAvarage(float *fft_vals, int sz);
        void clear();

        virtual void draw(unsigned char withScan = 1);
};

}

#endif  // __SPR_NEOPIXEL_FFTSCENE_H__
