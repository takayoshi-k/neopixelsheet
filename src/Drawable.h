#ifndef __SPR_NEOPIXEL_DRAWABLE_H__
#define __SPR_NEOPIXEL_DRAWABLE_H__

#include "RenderTarget.h"

namespace SpresenseNeoPixel
{

template <typename T>
class Drawable {
    private:
        bool is_shown;

    public:
        Drawable() : is_shown(true)  {};
        virtual ~Drawable() {};

        void setShown(bool enable) { is_shown = enable; };
        bool isShown() { return is_shown; };

        virtual void draw(RenderTarget<T> &target) = 0;
};

}

#endif  // __SPR_NEOPIXEL_DRAWABLE_H__

