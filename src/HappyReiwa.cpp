#include "HappyReiwa.h"

namespace SpresenseNeoPixel
{

HappyReiwa::HappyReiwa() : font()
{
    step = 0;
    shuku_color[0] = 0x00041400;
    shuku_color[1] = 0x00061800;
    shuku_color[2] = 0x00081C00;
    shuku_color[3] = 0x000A2000;
    shuku_color[4] = 0x000C2400;
    shuku_color[5] = 0x000E2800;
    shuku_color[6] = 0x00102C00;
    shuku_color[7] = 0x00123000;
}

void HappyReiwa::draw(RenderTarget<uint32_t> &target)
{

    // currently this implementation is assuming the rendertarget has fixed size 32x8.
    for(uint32_t y=0; y<font.getHeight(); y++){
        uint32_t x;
        uint32_t pixcol;

        // Charactor "Shuku" will change the color every frame.
        for(x=0; x<10; x++){
            pixcol = *font.getPixel(x, y);
            if(pixcol) {
                pixcol = shuku_color[(y + step/2) % 8];
            }
            target.setPixel(x, y, &pixcol);
        }

        // Other charactor is as same color.
        for(; x<font.getWidth(); x++){
            pixcol = *font.getPixel(x, y);
            if(pixcol) {
#if 0
                if((step/8) >= 8) {
                    pixcol = 0x00010101 * (16 - (step/8)) + 0x00010101;
                }else{
                    pixcol = 0x00010101 * (step/8) + 0x00010101;
                }
#else
                pixcol = 0x00080808;
#endif
            }
            target.setPixel(x, y, &pixcol);
        }
    }

    step++;
    if(step >= 8*8*2) step = 0;
}

}
