#ifndef __SPR_NEOPIXEL_SCENE_H__
#define __SPR_NEOPIXEL_SCENE_H__

#include <stdlib.h>

#include "RenderTarget.h"
#include "DrawableContainer.h"

namespace SpresenseNeoPixel
{

template <typename T>
class Scene {
    protected:
        RenderTarget<T> *render_target;
        DrawableContainer<T> *drawables;

    public:
        Scene(): render_target(NULL), drawables(NULL) {};
        virtual ~Scene(void) {};

        void setRenderTarget(RenderTarget<T> tgt) { render_target = &tgt; };

        DrawableContainer<T> *setDrawTarget(DrawableContainer<T> *tgt) {
            if(drawables) drawables->addTail(tgt);
            else          drawables = tgt;
            return tgt;
        };

        virtual void draw() {
            for( DrawableContainer<T> *draw_target = drawables;
                    draw_target != NULL;
                    draw_target = draw_target->getNext() ) {
                draw_target->draw(*render_target);
            }
        };
};

}

#endif  // __SPR_NEOPIXEL_SCENE_H__
