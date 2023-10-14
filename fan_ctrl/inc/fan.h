#ifndef FAN_H
#define FAN_H

#ifndef FAN_DATA_FILE_NAME
    #define FAN_DATA_FILE_NAME "/etc/fan_ctrl/fan_speed"
#endif

/**
 * @brief Controls the CPU cooling fan
*/
class Fan
{
private:
    const int _min_power = 150;
    const int _max_power = 400;
    const double _constantMultiplier;

    int pwm_pin;
    int powerPrcnt;

    /**
     * @brief Calculates the constant multiplier to be used with exponential throttle increase
    */
    double _calcConstantMultiplier();

    /**
     * @brief Converts the percentage power into analog output value and writes value to PWM pin
    */
    void _set_power();

    /**
     * @brief Writes the current power percentage to file
    */
    void _write_speed_data_file();
public:
    Fan(int);

    /**
     * @brief Sets the power percentage of the cooling fan 
    */
    void set_power_prcnt(int);
};

#endif