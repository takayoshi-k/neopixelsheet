
#include "NeoPixelSheetRenderTarget.h"
#include "FFTScene.h"

SpresenseNeoPixel::NeoPixelSheetRenderTarget Target(PIN_D00);
SpresenseNeoPixel::FFTScene myScene;

#define DATA_SIZE (520)

float data[DATA_SIZE];

void setData(float val) {
    for(int i=0; i<DATA_SIZE; i++){
      if(i>16)
        data[i] = val;
      else
        data[i] = 0.0;
    }
}

void setup() {
    myScene.setRenderTarget(&Target);

    setData(0.0);

    myScene.updateFFT(data);
    myScene.draw();

    usleep(50);
}

void loop() {
    static float value = 0.0;
    value += 4.0;
    if (value > 32.0){
      value = 0.0;
    }

    setData(value);
    myScene.draw();

    usleep(1);
}

