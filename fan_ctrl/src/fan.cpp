#include "fan.h"
#include <wiringPi.h>
#include <cmath>
#include <fstream>
#include <random>

Fan::Fan(int pwm_pin) :
_constantMultiplier(_calcConstantMultiplier())
{   
    this->pwm_pin = pwm_pin;
    powerPrcnt = 0;
    if (wiringPiSetup() != -1) {
       pinMode(pwm_pin, PWM_OUTPUT); 
    }
}

void Fan::set_power_prcnt(int power)
{
    // boost to get it going as it wont start at lowest power
    if (!isRunning() && power > 0) {
        pwmWrite(pwm_pin, _min_power + 50);
        delay(500);
    }
    powerPrcnt = power;
    if (powerPrcnt > 100) {
        powerPrcnt = 100;
    } 
    else if (powerPrcnt <= 0) {
        powerPrcnt = 0;
    }

    _set_power();
    _write_speed_data_file();
}

bool Fan::isRunning()
{
    return powerPrcnt > 0;
}

double Fan::_calcConstantMultiplier()
{   
    double x1 = 0.0;
    double y1 = 1;
    double x2 = 100.0;
    double y2 = _max_power - _min_power;
    
    double left = y1 / y2;
    double power = x1 - x2;
    
    double inversePower = 1.0 / power;
    
    double b = pow(left, inversePower);

    return b;
}

void Fan::_set_power()
{
    int output = 0;
    if (powerPrcnt > 0) {
        double power_out = 1 * pow(_constantMultiplier, powerPrcnt);
        output = power_out + 0.5 + _min_power;
    }
    pwmWrite(pwm_pin, output);
}

void Fan::_write_speed_data_file()
{
    std::ofstream fan_speed_file;
    fan_speed_file.open(FAN_DATA_FILE_NAME);
    fan_speed_file << powerPrcnt;
    fan_speed_file.flush();
    fan_speed_file.close();
}
