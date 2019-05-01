#ifndef __SPR_NEOPIXEL_SCENE_H__
#define __SPR_NEOPIXEL_SCENE_H__

#include <stdlib.h>

#include "RenderTarget.h"

namespace SpresenseNeoPixel
{

template <typename T>
class Scene {
    protected:
        RenderTarget<T> *render_target;

    public:
        Scene(): render_target(NULL) {};
        virtual ~Scene(void) {};

        void setRenderTarget(RenderTarget<T> *tgt) { render_target = tgt; };

        virtual void draw() = 0;
};

}

#endif  // __SPR_NEOPIXEL_SCENE_H__
