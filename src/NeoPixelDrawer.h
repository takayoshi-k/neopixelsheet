#ifndef __SPR_NEOPIXEL_DRAWER_H__
#define __SPR_NEOPIXEL_DRAWER_H__

#include <sdk/config.h>

#include <stdint.h>

namespace SpresenseNeoPixel
{

class NeoPixelDrawer {
    private:
        uint8_t  dout_pin;                  /**< File descriptor for use neopixel device file */
        uint32_t dout_pin_addr;             /**< File descriptor for use neopixel device file */
        uint32_t gpio_high_regval;
        uint32_t gpio_low_regval;
        inline void wait_cycles(uint32_t n) { // 4 clocks per cycle
            __asm volatile (
                "0:" "subs %[count], 1;"
                "bne 0b;"
                : [count] "+r" (n));
        }

    public:
        NeoPixelDrawer(uint8_t pin);
        ~NeoPixelDrawer() {};

        void show(uint32_t *data, int len);
};

}

#endif  // __SPR_NEOPIXEL_DRAWER_H__

