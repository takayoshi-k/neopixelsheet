#ifndef __SPR_NEOPIXEL_FFTSCENE2_H__
#define __SPR_NEOPIXEL_FFTSCENE2_H__

#include "FFTScene.h"

namespace SpresenseNeoPixel
{

class FFTScene2 : public FFTScene {
    public:
        void draw(unsigned char withScan = 1);
};

}


#endif  // __SPR_NEOPIXEL_FFTSCENE2_H__

