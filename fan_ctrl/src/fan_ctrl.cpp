#include <iostream>
#include <unistd.h>
#include "fan.h"
#include "cpu.h"

#define PWM_PIN 1
#define REFRESH_RATE_MICROS 10000000

int main(int argc, char const *argv[])
{
    Fan *fan = new Fan(PWM_PIN);
    CPU *cpu = new CPU;

    while(1) {  
        int temperaturePercent = cpu->getTempPrcnt();
        fan->set_power_prcnt(temperaturePercent);
        usleep(REFRESH_RATE_MICROS);
    }

    delete fan;
    delete cpu;

    return 0;
}
