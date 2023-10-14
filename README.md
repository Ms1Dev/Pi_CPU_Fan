# Pi_CPU_Fan

Service that will run on startup to adjust cooling fan speed based on CPU temperature.

Uing the GeeekPi 4 Extreme Cooling Heat Sink. The fan is only 2-pin so speed is adjusted using PWM.

This repo contains two programs fan_ctrl and fan_info. Fan_ctrl is installed as a systemctl service that launches at startup. Fan_info can be called with the alias ```faninfo``` and shows the cpu temp and fan power percentage.
