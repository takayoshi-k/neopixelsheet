#include "FFTScene2.h"

namespace SpresenseNeoPixel
{

void FFTScene2::draw(unsigned char withScan)
{
    int avg_sz;
    int start_pos;
    int pix_val;
    
    uint32_t col;

    int center_pos;
    if( fft_result && render_target ){
        center_pos = (int)render_target->getWidth() / 2;
        for(int x=0; x<center_pos; x++) {
            avg_sz = avarage_step;
            start_pos = x * avarage_step - (avarage_step / 2);
            if (start_pos < 0) {
                avg_sz += start_pos;
                start_pos = 0;
            }

            pix_val = (int)(simpleAvarage(&fft_result[start_pos], avg_sz) * bias_val); // Bias
            pix_val = (pix_val + indicator_unit - 1) / indicator_unit;

            for(int y=0; y<(int)render_target->getHeight(); y++) {
                col = ( pix_val > y ) ? pixcol[y] : 0x00000000;
                if(isOverride == true){
                    render_target->setPixel(center_pos + x, y, &col);
                    render_target->setPixel(center_pos - x, y, &col);
                }else{
                    if(col != 0){
                        render_target->setPixel(center_pos + x, y, &col);
                        render_target->setPixel(center_pos - x, y, &col);
                    }
                }
            }
        }
    }

    if(withScan)
        render_target->scanout();
}

}

