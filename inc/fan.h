#ifndef FAN_H
#define FAN_H

class Fan
{
private:
    int pwm_pin;
    const int _min_power = 150;
    const int _max_power = 400;
    const double _constantMultiplier;
    double _calcConstantMultiplier();
    void _set_power(int);
public:
    Fan(int);
    void set_power_prcnt(int);
};

#endif