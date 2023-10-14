#ifndef CPU_H
#define CPU_H


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
    float getTemp();
    int getTempPrcnt();
    int getLowerLimit();
    int getUpperLimit();
};

#endif