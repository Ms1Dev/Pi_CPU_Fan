#ifndef FAN_H
#define FAN_H

#ifndef FAN_DATA_FILE_NAME
    #define FAN_DATA_FILE_NAME "/etc/fan_ctrl/fan_speed"
#endif

class Fan
{
private:
    int pwm_pin;
    const int _min_power = 150;
    const int _max_power = 400;
    const double _constantMultiplier;
    int powerPrcnt;
    double _calcConstantMultiplier();
    void _set_power();
    void _write_speed_data_file();
public:
    Fan(int);
    void set_power_prcnt(int);
};

#endif