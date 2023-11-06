#include <iostream>
#include <unistd.h>
#include "fan.h"
#include "cpu.h"

#define PWM_PIN 1
#define REFRESH_RATE_MICROS 5000000
#define FAN_ON_TEMP_OFFSET 10

int main(int argc, char const *argv[])
{
    Fan *fan = new Fan(PWM_PIN);
    CPU *cpu = new CPU;

    while(1) {  
        int temperaturePercent = cpu->getTempPrcnt();
        // offset keeps the fan running below lower limit 
        // this prevents it from switching on and off repeatedly
        if (fan->isRunning()) {
            temperaturePercent += FAN_ON_TEMP_OFFSET;
        }
        fan->set_power_prcnt(temperaturePercent);
        usleep(REFRESH_RATE_MICROS);
    }

    delete fan;
    delete cpu;

    return 0;
}
