#ifndef __SPR_NEOPIXEL_SHEETRENDERTARGET_H__
#define __SPR_NEOPIXEL_SHEETRENDERTARGET_H__

#include "RenderTarget.h"
#include "NeoPixelDrawer.h"

namespace SpresenseNeoPixel
{

class NeoPixelSheetRenderTarget : public RenderTarget<uint32_t> {
    private:
        uint32_t pix_data[8*32];
        NeoPixelDrawer drawer;

    public:
        NeoPixelSheetRenderTarget(uint8_t pin) : RenderTarget(32, 8), drawer(pin) { clear(0x00000000); };

        int col_offset(uint32_t x, uint32_t y);
        virtual uint32_t *getPixel(uint32_t x, uint32_t y); 
        virtual void setPixel(uint32_t x, uint32_t y, uint32_t *col);
        virtual void setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b);
        virtual void scanout();
};

}

#endif  // __SPR_NEOPIXEL_SHEETRENDERTARGET_H__

