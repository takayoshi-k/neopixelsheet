#ifndef __SPR_NEOPIXEL_RENDERTARGET_H__
#define __SPR_NEOPIXEL_RENDERTARGET_H__

#include "Image.h"

namespace SpresenseNeoPixel
{

template <typename T>
class RenderTarget : public Image<T> {
    public:
       RenderTarget(uint32_t w, uint32_t h) : Image<T>(w, h) {};
       virtual ~RenderTarget() {};

       virtual void scanout() = 0;
};

}

#endif  // __SPR_NEOPIXEL_RENDERTARGET_H__

