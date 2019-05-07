#ifndef __SPR_NEOPIXEL_IMAGE_H__
#define __SPR_NEOPIXEL_IMAGE_H__

#include <stdint.h>

namespace SpresenseNeoPixel
{

template <typename T = uint32_t>
class Image {
    private:
        uint32_t width, height;

    public:
        Image<T>(uint32_t w, uint32_t h) : width(w), height(h) {};
        virtual ~Image<T>() {};

        uint32_t getWidth()  { return width; };
        uint32_t getHeight() { return height; };

        virtual T *getPixel(uint32_t x, uint32_t y) = 0; 
        virtual void setPixel(uint32_t x, uint32_t y, T *) = 0;
        virtual void setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b) = 0;

        void clear(T *col) {
            for(uint32_t i=0; i<height; i++){
                for(uint32_t j=0; j<width; j++){
                    setPixel(j, i, col);
                }
            }
        };

        void clear(uint8_t r, uint8_t g, uint8_t b) {
            for(uint32_t i=0; i<height; i++){
                for(uint32_t j=0; j<width; j++){
                    setPixel(j, i, r, g, b);
                }
            }
        };
};

}

#endif  // __SPR_NEOPIXEL_IMAGE_H__

