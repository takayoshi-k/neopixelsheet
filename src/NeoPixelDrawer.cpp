#include "NeoPixelDrawer.h"
#include <common/up_arch.h>
#include <Arduino.h>

#include "wiring_private.h"

namespace SpresenseNeoPixel
{

NeoPixelDrawer::NeoPixelDrawer(uint8_t pin) : dout_pin(255), dout_pin_addr(0), gpio_high_regval(0), gpio_low_regval(0)
{
    dout_pin = pin;
    dout_pin_addr = get_gpio_regaddr( (uint32_t)pin_convert(pin) );

    pinMode(dout_pin, OUTPUT);
    digitalWrite(dout_pin, LOW);

    gpio_low_regval = gpio_high_regval = getreg32(dout_pin_addr);

    bitSet(gpio_high_regval, GPIO_OUTPUT_SHIFT);
    bitClear(gpio_low_regval,  GPIO_OUTPUT_SHIFT);

    putreg32(gpio_low_regval, dout_pin_addr);

    usleep(50);
}

void NeoPixelDrawer::sendOneBit(int val)
{
    int i, j;
    int sel = 1 + (val ? 1 : 0);

    for(i = 0; i < 3; i ++) {
        if (i < sel) {
            putreg32(gpio_high_regval, dout_pin_addr);
        } else {
            putreg32(gpio_low_regval, dout_pin_addr);
            for(j = 0; j < 40; j ++){}  // Adjust timing.
        }
    }
}

void NeoPixelDrawer::show(uint32_t *data, int len)
{
    uint32_t bitmask;
    for(int i=0; i<len; i++) {
        bitmask = 0x00800000; // bit[23] to bit[0]
        while(bitmask) {
            sendOneBit( (data[i] & bitmask) ? 1 : 0 );
            bitmask >>= 1;
        }
    }
}

}

