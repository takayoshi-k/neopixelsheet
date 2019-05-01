
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

    // Create dummy data.
    setData(0.0);

    // Set your original colors.
    myScene.setLevelColor(0, 0x00002020);
    myScene.setLevelColor(1, 0x00000030);
    myScene.setLevelColor(2, 0x00303000);
    myScene.setLevelColor(3, 0x00103000);
    myScene.setLevelColor(4, 0x00006000);

    // Cnahge average steps.
    myScene.setAvarageStep(2);

    // Cnahge bias of avaraged data.
    myScene.setBias(1.0);

    // Change Indicator Unit number per one step.
    myScene.setIndicatorUnit(4);

    // Set dummy data.
    myScene.updateFFT(data);

    // Draw data on the Target.
    myScene.draw();

    usleep(50);
}

void loop() {
    static float value = 0.0;
    value += 4.0;
    if (value > 32.0){
      value = 0.0;
    }

    // Update dummy data.
    setData(value);

    // Draw data on the Target.
    myScene.draw();

    usleep(1);
}

