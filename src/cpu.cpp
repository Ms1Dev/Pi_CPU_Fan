#include "cpu.h"
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <exception>


CPU::CPU()
{
    _temp_lower_limit = _default_lower_limit;
    _temp_upper_limit = _default_upper_limit;

    std::fstream settingsFile;
    settingsFile.open(_settingsFileLoc, std::fstream::in);
    
    if (settingsFile) {
        std::string line;
        while(std::getline(settingsFile,line)) {
            std::stringstream ss(line);

            std::size_t delimeterPos = line.find(_settingsFileDelimeter);
            std::string key = line.substr(0,delimeterPos);
            std::string value = line.substr(delimeterPos+1,delimeterPos+3);

            try {
                int temp = std::stoi(value);

                if (key == _settings_lower_key) {
                    _temp_lower_limit = temp;
                }
                else if (key == _settings_upper_key) {
                    _temp_upper_limit = temp;
                }
            } catch (std::invalid_argument &) {
                std::cout << "CPU FAN CTRL: Invalid temperature settings file" << std::endl;
            }
        }        
    }

    settingsFile.close();
}


float CPU::getTemp()
{
    std::ifstream cpu_temp_file;
    cpu_temp_file.open("/sys/class/thermal/thermal_zone0/temp");

    std::stringstream buffer;
    buffer << cpu_temp_file.rdbuf();
    cpu_temp_file.close();

    float cpu_temp = 0.0;
    cpu_temp = std::stof(buffer.str());
    cpu_temp = cpu_temp / 1000; 
    cpu_temp = std::roundf(cpu_temp * 100) / 100; 

    return cpu_temp;    
}

int CPU::getTempPrcnt()
{
    int prcnt = (100.0 / (_temp_upper_limit - _temp_lower_limit)) * (getTemp() - _temp_lower_limit) + 0.5;
    if (prcnt > 100) {
        prcnt = 100;
    }
    else if (prcnt < 0) {
        prcnt = 0;
    }
    return prcnt;
}

int CPU::getLowerLimit()
{
    return _temp_lower_limit;
}

int CPU::getUpperLimit()
{
    return _temp_upper_limit;
}
