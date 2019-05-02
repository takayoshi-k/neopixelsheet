#ifndef __SPR_NEOPIXEL_HAPPYREIWA_H__
#define __SPR_NEOPIXEL_HAPPYREIWA_H__

#include "HappyReiwaFont.h"
#include "Drawable.h"

namespace SpresenseNeoPixel
{

class HappyReiwa : public Drawable<uint32_t> {
    private:
        HappyReiwaFont font;
        uint32_t shuku_color[8];
        int step;

    public:
        HappyReiwa();
        ~HappyReiwa() {};
        void draw(RenderTarget<uint32_t> &target);
};

}

#endif  // __SPR_NEOPIXEL_HAPPYREIWA_H__

