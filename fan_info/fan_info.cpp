#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include "cpu.h"

#define REFRESH_RATE_MICROS 2000000

int main(int argc, char const *argv[])
{    
    CPU *cpu = new CPU;
    
    std::cout << "---------------CPU FAN-------------" << std::endl;
    std::cout << "Fan start temperature     : " << cpu->getLowerLimit() << "°C" << std::endl;
    std::cout << "Fan fullspeed temperature : " << cpu->getUpperLimit() << "°C" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    while(1) {
        std::ifstream fan_speed_file;
        fan_speed_file.open("/etc/fan_ctrl/fan_speed");

        std::stringstream buffer;
        buffer << fan_speed_file.rdbuf();
        fan_speed_file.close();
        std::string fan_speed;
        fan_speed = buffer.str();
        if (fan_speed.length() > 0) {
            fan_speed = "  |  Fan Power: " + fan_speed + " %";
        }

        std::cout << "CPU Temperature: " << cpu->getTemp() << "°C" << fan_speed << "\t\r" << std::flush;
        usleep(REFRESH_RATE_MICROS);
    }

    delete cpu;

    return 0;
}
