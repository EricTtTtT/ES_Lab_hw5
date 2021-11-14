/*
 * Copyright (c) 2014-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.
PwmOut led(PA_15);

int main()
{
    // specify period first
    led.period(0.05f);      // 4 second period
    led.write(0.20f);      // 50% duty cycle, relative to period
    //led = 0.5f;          // shorthand for led.write()
    //led.pulsewidth(2);   // alternative to led.write, set duty cycle time in seconds
    // while (1);


    // send S.O.S signal in MOS-code
    while (1) {
        led.period(0.5f);
        led.write(0.2f);
        ThisThread::sleep_for(1500);
        led.period(0.5f);
        led.write(0.0f);
        ThisThread::sleep_for(500);   

        led.period(1.0f);
        led.write(0.8f);
        ThisThread::sleep_for(3500);  
        led.period(0.5f);
        led.write(0.0f);
        ThisThread::sleep_for(500);   

        led.period(0.5f);
        led.write(0.2f);
        ThisThread::sleep_for(1500);

        led.period(0.5f);
        led.write(0.0f);
        ThisThread::sleep_for(2500);   
    }
}
