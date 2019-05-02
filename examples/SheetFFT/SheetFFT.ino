
#include "NeoPixelSheetRenderTarget.h"
#include "FFTScene.h"
#include "Scene.h"
#include "HappyReiwa.h"

SpresenseNeoPixel::NeoPixelSheetRenderTarget Target(PIN_D00);
SpresenseNeoPixel::FFTScene myScene;
SpresenseNeoPixel::Scene<uint32_t> normalScene;
SpresenseNeoPixel::HappyReiwa reiwa;
SpresenseNeoPixel::DrawableContainer<uint32_t> container;

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
    // Set "祝令和" in Scene.
    normalScene.setDrawTarget(container.setPayload(&reiwa));

    // Set RenderTaregt in each Scenes.
    normalScene.setRenderTarget(Target);
    myScene.setRenderTarget(Target);

    // Initialize dummy FFT data.
    setData(0.0);

    // Set your original colors of FFT level.
    myScene.setLevelColor(0, 0x00002020);
    myScene.setLevelColor(1, 0x00000030);
    myScene.setLevelColor(2, 0x00303000);
    myScene.setLevelColor(3, 0x00103000);
    myScene.setLevelColor(4, 0x00006000);

    // Cnahge FFT average steps.
    myScene.setAvarageStep(2);

    // Cnahge FFT show bias of avaraged data.
    myScene.setBias(1.0);

    // Change Indicator Unit number per one step.
    myScene.setIndicatorUnit(2);

    // Set dummy data.
    myScene.updateFFT(data);

    // Draw "祝令和" on the Target.
    normalScene.draw();
    
    usleep(50);
}

void loop() {
    static int mode = 0;
    static int count_frames = 0;
    static float value = 0.0;

    if((count_frames % 8)== 0) value += 4.0;
    if (value > 32.0){
      value = 0.0;
    }

    setData(value);

    switch (mode) {
    case 0:
        // Mode 0 is showing "祝令和"
        normalScene.draw();
        break;
    case 1:
        // Mode 1 is showing FFT value over "祝令和"
        normalScene.draw(0);
        myScene.setOverrideMode(false);
        myScene.draw();
        break;
    case 2:
        // Mode 2 is showing FFT value.
        myScene.setOverrideMode(true);
        myScene.draw();
        break;
    default:
        mode = 0;
        break;
    }

    count_frames++;
    if(count_frames >= 128) {
      mode++;
      Serial.print("Mode = ");
      Serial.println(mode);
      count_frames = 0;
    }
    
    usleep(1);
}
