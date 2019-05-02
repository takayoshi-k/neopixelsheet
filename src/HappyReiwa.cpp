#include "HappyReiwa.h"

namespace SpresenseNeoPixel
{

HappyReiwa::HappyReiwa() : font()
{
    step = 0;
    shuku_color[0] = 0x00103000;
    shuku_color[1] = 0x00184000;
    shuku_color[2] = 0x00205000;
    shuku_color[3] = 0x00286000;
    shuku_color[4] = 0x00307000;
    shuku_color[5] = 0x00388000;
    shuku_color[6] = 0x00409000;
    shuku_color[7] = 0x0048A000;
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
                pixcol = shuku_color[(y + step) % 8];
            }
            target.setPixel(x, y, &pixcol);
        }

        // Other charactor is as same color.
        for(; x<font.getWidth(); x++){
            pixcol = *font.getPixel(x, y);
            if(pixcol) {
                pixcol = 0x00101010;
            }
            target.setPixel(x, y, &pixcol);
        }
    }

    step++;
    if(step >= 8) step = 0;
}

}
