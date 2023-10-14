UPPER_LIMIT_KEY = FAN_TEMP_UPPER
LOWER_LIMIT_KEY = FAN_TEMP_LOWER
UPPER_DEFAULT_VALUE = 50
LOWER_DEFAULT_VALUE = 34
SETTINGS_FILE_LOC = /etc/fan_ctrl
SETTINGS_FILE_NAME = $(SETTINGS_FILE_LOC)/fan_temperature_settings
FAN_DATA_FILE_NAME = $(SETTINGS_FILE_LOC)/fan_speed

CXX := g++
CXXFLAGS := \
	-std=c++11 -Wall -I../fan_ctrl/inc \
	-DUPPER_LIMIT_KEY='"$(UPPER_LIMIT_KEY)"' \
	-DLOWER_LIMIT_KEY='"$(LOWER_LIMIT_KEY)"' \
	-DSETTINGS_FILE_NAME='"$(SETTINGS_FILE_NAME)"' \
	-DFAN_DATA_FILE_NAME='"$(FAN_DATA_FILE_NAME)"'

SRCS := ./fan_info.cpp ../fan_ctrl/src/cpu.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := /bin/fan_info

all: $(EXEC)
	alias faninfo='($(EXEC))'

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	rm *.o -f
	rm $(OBJS) -f
	sudo rm -f $(EXEC)
