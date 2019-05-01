#include <stdlib.h>

#include "NeoPixelSheetRenderTarget.h"

namespace SpresenseNeoPixel
{

int NeoPixelSheetRenderTarget::col_offset(uint32_t x, uint32_t y)
{
    //======================================================================
    //       ^ --- --    - --- (w-1,h-1)
    //       | | | |     | | |
    //       | | | | ... | | |[3]
    //       | | | |     | | |[2]
    //       | | | |     | | |[1]
    // (0,0) --- ---     --- S[0]

    int offset = -1;

    if (x < getWidth() && y < getHeight()){
        x = getWidth()  - 1 - x;
        y = (x & 0x01) ? getHeight() - 1 - y : y;
        offset = x * getHeight() + y;
    }

    return offset;
}


uint32_t *NeoPixelSheetRenderTarget::getPixel(uint32_t x, uint32_t y)
{
    uint32_t *ret = NULL;
    int ofst = col_offset(x, y);

    if (ofst >= 0 ){
       ret = &pix_data[ofst];
    }

    return ret;
}

void NeoPixelSheetRenderTarget::setPixel(uint32_t x, uint32_t y, uint32_t *col)
{
    int ofst = col_offset(x, y);

    if (ofst >= 0 ){
        pix_data[ofst] = *col;
    }
}

void NeoPixelSheetRenderTarget::setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b)
{
    // Not implemented... Sooner or Later...
}

void NeoPixelSheetRenderTarget::scanout()
{
    drawer.show(&pix_data[0], getWidth() * getHeight());
}

}

