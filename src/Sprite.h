#ifndef __SPR_NEOPIXEL_SPRITE_H__
#define __SPR_NEOPIXEL_SPRITE_H__

#include "Image.h"
#include "RenderTarget.h"

namespace SpresenseNeoPisel
{

class Animation;

struct DrawArea {
    uint32_t start_x;
    uint32_t start_y;
    uint32_t screen_x;
    uint32_t screen_y;
    uint32_t draw_w;
    uint32_t draw_h;
}

template <typename T = uint32_t>
class Sprite : public Image<T> {
    private:
        bool is_shown;
        T *pixeldata;
        Animation *anim;

    public:
        Sprite<T>(uint32_t w, uint32_t h) : Image<T>(w, h), pixeldata(NULL) {};
        virtual ~Sprite<T>() {};

        void setPixelData(T *dat) { pixeldata = dat; };

        virtual T *getPixel(uint32_t x, uint32_t y); 
        virtual void setPixel(uint32_t x, uint32_t y, T *);
        virtual void setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b);

        void setAnimation(Animation *a) { anim = a; };
};

class Animation {
    private:
        int32_t pos_x, pos_y;
        template <typename T> Sprite<T> *sprite;

    public:
        Animation() : pos_x(0), pos_y(0), sprite(NULL) {};
        ~Animation() {};

        bool isShown() { return is_shown; };
        void enableShow(bool en) { is_shown = en; }

        virtual void stepAnimation() = 0;
        virtual bool isDrawable(uint32_t screen_w, uint32_t screen_h, DrawArea &area) = 0;

        template <typename T> void setSprite(T &spr) { sprite = &spr; };
};

}

#endif  // __SPR_NEOPIXEL_SPRITE_H__
