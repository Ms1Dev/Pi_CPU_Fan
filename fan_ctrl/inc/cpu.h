#ifndef CPU_H
#define CPU_H

#ifndef SETTINGS_FILE_NAME
    #define SETTINGS_FILE_NAME "/etc/fan_ctrl/fan_temperature_settings"
#endif

#ifndef LOWER_LIMIT_KEY
    #define LOWER_LIMIT_KEY "FAN_TEMP_LOWER"
#endif

#ifndef UPPER_LIMIT_KEY
    #define UPPER_LIMIT_KEY "FAN_TEMP_UPPER"
#endif


/**
 * @brief Monitors the cpu temperature
*/
class CPU
{
private:
    const char* _settingsFileLoc = SETTINGS_FILE_NAME;
    const char _settingsFileDelimeter = '=';
    const char* _settings_lower_key = LOWER_LIMIT_KEY;
    const char* _settings_upper_key = UPPER_LIMIT_KEY;
    const int _default_lower_limit = 30;
    const int _default_upper_limit = 50;

    int _temp_lower_limit;
    int _temp_upper_limit;
public:
    CPU();

    /**
     * @brief Returns the current temperature of the CPU
    */
    float getTemp();

    /**
     * @brief returns the temperature as a percentage between the upper and lower limits
    */
    int getTempPrcnt();

    /**
     * @brief Returns the lower limit - the temperature the fan starts
    */
    int getLowerLimit();

    /**
     * @brief Returns the upper limit - the temperature the fan is at max power
    */
    int getUpperLimit();
};

#endif