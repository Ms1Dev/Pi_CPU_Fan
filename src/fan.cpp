#include "fan.h"
#include <wiringPi.h>
#include <cmath>


Fan::Fan(int pwm_pin) :
_constantMultiplier(_calcConstantMultiplier())
{   
    this->pwm_pin = pwm_pin;

    if (wiringPiSetup() != -1) {
       pinMode(pwm_pin, PWM_OUTPUT); 
    }
}

void Fan::set_power_prcnt(int power)
{
    if (power > 100) {
        power = 100;
    } 
    else if (power <= 0) {
        _set_power(0);
        return;
    } 

    double power_out = _min_power * pow(_constantMultiplier, power);

    int output = power_out + 0.5;
    
    _set_power(output);
}

double Fan::_calcConstantMultiplier()
{   
    double x1 = 0.0;
    double y1 = _min_power;
    double x2 = 100.0;
    double y2 = _max_power;
    
    double left = y1 / y2;
    double power = x1 - x2;
    
    double inversePower = 1.0 / power;
    
    double b = pow(left, inversePower);

    return b;
}

void Fan::_set_power(int power)
{
    pwmWrite(pwm_pin, power);
}
