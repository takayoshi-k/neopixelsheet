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

void NeoPixelDrawer::show(uint32_t *data, int len)
{
    for(int i=0; i<len; i++) {
        uint32_t val = data[i];
        for (int j = 23; j >= 0; j--) {
            if ((val >> j) & 1) {
                putreg32(gpio_high_regval, dout_pin_addr);
                wait_cycles(20);
                putreg32(gpio_low_regval, dout_pin_addr);
                wait_cycles(2);
            } else {
                putreg32(gpio_high_regval, dout_pin_addr);
                wait_cycles(4);
                putreg32(gpio_low_regval, dout_pin_addr);
                wait_cycles(20);
            }
        }
    }
}

}

