
UPPER_LIMIT_KEY = FAN_TEMP_UPPER
LOWER_LIMIT_KEY = FAN_TEMP_LOWER
SETTINGS_FILE_LOC = /etc/fan_ctrl
SETTINGS_FILE_NAME = $(SETTINGS_FILE_LOC)/fan_temperature_settings

CXX := g++
CXXFLAGS := -std=c++11 -Wall -DUPPER_LIMIT_KEY='"$(UPPER_LIMIT_KEY)"' -DLOWER_LIMIT_KEY='"$(LOWER_LIMIT_KEY)"' -DSETTINGS_FILE_NAME='"$(SETTINGS_FILE_NAME)"'

SRCS := ./src/*
OBJS := $(SRCS:.cpp=.o)
EXEC := /bin/fan_ctrl

all: createConf  $(EXEC)

createConf:
	mkdir -p $(SETTINGS_FILE_LOC)
	touch $(SETTINGS_FILE_NAME)
	echo "$(LOWER_LIMIT_KEY)=32" > $(SETTINGS_FILE_NAME)
	echo "$(UPPER_LIMIT_KEY)=50" >> $(SETTINGS_FILE_NAME)
	touch /etc/init.d/fan_ctrl_start.sh
	echo "#!/bin/bash" > /etc/init.d/fan_ctrl_start.sh
	echo "/bin/fan_ctrl" >> /etc/init.d/fan_ctrl_start.sh
	chmod -x /etc/init.d/fan_ctrl_start.sh
	update-rc.d fan_ctrl_start.sh defaults

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) -lwiringPi -I./inc/

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	sudo rm -f /bin/fan_ctrl
