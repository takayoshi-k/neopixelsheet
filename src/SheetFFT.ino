
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
  Serial.begin(115200);
    myScene.setRenderTarget(&Target);

    setData(0.0);

    myScene.updateFFT(data);
    myScene.draw();

    usleep(50);
}

void loop() {
    static int loop_counter = 0;
    static float value = 0.0;
    value += 4.0;
    if (value > 32.0){
      value = 0.0;
      Serial.print("Loop = ");
      Serial.print(loop_counter);
      Serial.print(" diff [0] = ");
      Serial.print(SpresenseNeoPixel::diff_time[0]);
      Serial.print(" [1] = ");
      Serial.println(SpresenseNeoPixel::diff_time[1]);
      loop_counter = 0;
    }

    setData(value);
    myScene.draw();

    usleep(1);
    
    loop_counter++;
}

