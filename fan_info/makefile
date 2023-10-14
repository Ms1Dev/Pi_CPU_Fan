
SETTINGS_FILE_LOC = /etc/fan_ctrl
SETTINGS_FILE_NAME = $(SETTINGS_FILE_LOC)/fan_temperature_settings
FAN_DATA_FILE_NAME = $(SETTINGS_FILE_LOC)/fan_speed

CXX := g++
CXXFLAGS := \
	-std=c++11 -Wall -I../fan_ctrl/inc \
	-DSETTINGS_FILE_NAME='"$(SETTINGS_FILE_NAME)"' \
	-DFAN_DATA_FILE_NAME='"$(FAN_DATA_FILE_NAME)"'

$(shell mkdir -p ./obj)

OBJDIR = ./obj/

SRCDIRS := ../fan_ctrl/src/
SRCFILES := ../fan_ctrl/src/cpu.cpp ./fan_info.cpp
SRCFILENAMES := $(notdir $(SRCFILES))

OBJSNAMES := $(SRCFILENAMES:.cpp=.o)
OBJS := $(addprefix $(OBJDIR), $(OBJSNAMES))

EXEC := /bin/fan_info

all: $(EXEC)
	touch /home/michael-zwann/.bash_aliases
	grep -q -F "alias faninfo='($(EXEC))'" "/home/michael-zwann/.bash_aliases" || echo "alias faninfo='($(EXEC))'" >> /home/michael-zwann/.bash_aliases
	
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)%.o: $(SRCDIRS)%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJDIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	sudo rm ./obj/*.o -f
	sudo rm -f $(EXEC)
