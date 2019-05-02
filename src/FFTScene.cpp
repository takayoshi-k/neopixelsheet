#include "FFTScene.h"

namespace SpresenseNeoPixel
{

float FFTScene::simpleAvarage(float *fft_vals, int sz)
{
    float ttl = 0;

    for(int i=0; i<sz; i++){
        ttl += *fft_vals++;
    }
    ttl /= sz;

    return ttl;
}

void FFTScene::setLevelColor(int level, uint32_t col)
{
    int pos = 0;
    if (level >= 0 && level < LEVEL_GROUP_NUM) {
        pos =  (level == 0) ?  0 : level_group[level-1];
        for( ; pos < level_group[level]; pos++){
            pixcol[pos] = col;
        }
    }
}

void FFTScene::clear()
{
    render_target->clear(0x00000000);
    render_target->scanout();
}

void FFTScene::draw()
{
    int avg_sz;
    int start_pos;
    int pix_val;
    
    uint32_t col;

    if( fft_result && render_target ){
        for(int x=0; x<(int)render_target->getWidth(); x++) {
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
                render_target->setPixel(x, y, &col);
            }

        }
    }

    render_target->scanout();
}

}

