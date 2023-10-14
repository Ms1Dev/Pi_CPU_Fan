## Pi_CPU_Fan

Service that will run on startup to adjust cooling fan speed based on CPU temperature.

Uing the GeeekPi 4 Extreme Cooling Heat Sink. The fan is only 2-pin so speed is adjusted using PWM.

<img src="https://github.com/Ms1Dev/Pi_CPU_Fan/blob/master/PXL_20231014_214856203.NIGHT.jpg" width="250">

This repo contains two programs fan_ctrl and fan_info. Fan_ctrl is installed as a systemctl service that launches at startup. Fan_info can be called with the alias ```faninfo``` and shows the cpu temp and fan power percentage.

![image](https://github.com/Ms1Dev/Pi_CPU_Fan/blob/master/Screenshot%20from%202023-10-14%2022-55-03.png)

Upper and lower temperature parameters can be adjusted by modifying the values in ```/etc/fan_ctrl/fan_temperature_settings``` then restarting the service or rebooting.
