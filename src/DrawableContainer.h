#ifndef __SPR_NEOPIXEL_DRAWABLECONTAINER_H__
#define __SPR_NEOPIXEL_DRAWABLECONTAINER_H__

#include <stdlib.h>
#include "Drawable.h"

namespace SpresenseNeoPixel
{

template <typename T = uint32_t>
class DrawableContainer {
    private:
        Drawable<T> * payload;
        DrawableContainer<T> *next;

    public:
        DrawableContainer() : payload(NULL), next(NULL) {};
        virtual ~DrawableContainer() {};

        DrawableContainer<T> *addTail(DrawableContainer<T> *c) {
                DrawableContainer<T> *tmp = this;
                while(tmp->next) tmp = tmp->next;
                tmp->next = c;
                return c;
        };

        DrawableContainer<T> *getNext() { return next; };

        DrawableContainer<T> *setPayload(Drawable<T> *d) { payload = d; return this; };

        void draw(RenderTarget<T> &target) {
                for( DrawableContainer<T> *tmp = this; tmp; tmp = tmp->getNext() ){
                  if(tmp->payload && tmp->payload->isShown()) tmp->payload->draw(target);
                }
        };
};

}

#endif  // __SPR_NEOPIXEL_DRAWABLECONTAINER_H__

