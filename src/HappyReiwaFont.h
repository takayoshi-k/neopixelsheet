#ifndef __SPR_NEOPIXEL_HAPPYREIWAFONT_H__
#define __SPR_NEOPIXEL_HAPPYREIWAFONT_H__


namespace SpresenseNeoPixel
{

class HappyReiwaFont : Image<uint32_t> {
    private:
        static const uint32_t happy_reiwa_width  = 32;
        static const uint32_t happy_reiwa_height = 8;
        uint32_t *font_data;

    public:
        HappyReiwaFont();
        ~HappyReiwaFont() {};

        uint32_t *getPixel(uint32_t x, uint32_t y){
            if ( (x>=0) && (x<getWidth()) && (y>=0) && (y<getHeight()) ){
                return &font_data[ y * getWidth() + x ];
            }else{
                return 0x00000000;
            }
        };

        void setPixel(uint32_t x, uint32_t y, T *){ /* Nothing to draw */ };
        void setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b){ /* Nothing to draw */ };
};

}

#endif  // __SPR_NEOPIXEL_HAPPYREIWAFONT_H__

