#include "Sprite.h"

namespace SpresenseNeoPisel
{

template <typename T> T *Sprite<T>::getPixel(uint32_t x, uint32_t y)
{
    if( (pixeldata != NULL) && (x >= 0) && (y >= 0) && (x < getWidth()) && (y < getHeight()) ) {
        return &pixeldata[y*getWidth() + x];
    }

    return NULL;
}

template <typename T> void Sprite<T>::setPixel(uint32_t x, uint32_t y, T *dat)
{
    if( (pixeldata != NULL) && (x >= 0) && (y >= 0) && (x < getWidth()) && (y < getHeight()) ) {
        pixeldata[y*getWidth() + x] = *dat;
    }
}

template <typename T> void Sprite<T>::setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b)
{
    // Not implemented now... sooner or later...
}

}

