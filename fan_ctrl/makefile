
UPPER_LIMIT_KEY = FAN_TEMP_UPPER
LOWER_LIMIT_KEY = FAN_TEMP_LOWER
UPPER_DEFAULT_VALUE = 50
LOWER_DEFAULT_VALUE = 34
SETTINGS_FILE_LOC = /etc/fan_ctrl
SETTINGS_FILE_NAME = $(SETTINGS_FILE_LOC)/fan_temperature_settings
FAN_DATA_FILE_NAME = $(SETTINGS_FILE_LOC)/fan_speed

CXX := g++
CXXFLAGS := \
	-std=c++11 -Wall -I./inc/ \
	-DUPPER_LIMIT_KEY='"$(UPPER_LIMIT_KEY)"' \
	-DLOWER_LIMIT_KEY='"$(LOWER_LIMIT_KEY)"' \
	-DSETTINGS_FILE_NAME='"$(SETTINGS_FILE_NAME)"' \
	-DFAN_DATA_FILE_NAME='"$(FAN_DATA_FILE_NAME)"'

SRCS := ./src/*
OBJS := $(SRCS:.cpp=.o)
EXEC := /bin/fan_ctrl

all: $(EXEC) createConf 

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) -lwiringPi

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	sudo rm -f /bin/fan_ctrl

createConf:
	mkdir -p $(SETTINGS_FILE_LOC)
	touch $(SETTINGS_FILE_NAME)
	touch $(FAN_DATA_FILE_NAME)
	echo "$(LOWER_LIMIT_KEY)=$(LOWER_DEFAULT_VALUE)" > $(SETTINGS_FILE_NAME)
	echo "$(UPPER_LIMIT_KEY)=$(UPPER_DEFAULT_VALUE)" >> $(SETTINGS_FILE_NAME)
	cp ./fan_ctrl.service /etc/systemd/system/fan_ctrl.service
	chmod 755 /etc/systemd/system/fan_ctrl.service
	systemctl daemon-reload
	systemctl enable fan_ctrl
	systemctl restart fan_ctrl