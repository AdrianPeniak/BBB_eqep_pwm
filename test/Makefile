CXX = g++
TARGET = controller

HEADERDIR = include/motor_controller
EQEPDIR = interface/encoders/src
BLACKLIBDIR = interface/BlackLib/v2_0/src
SRCDIR = src

BLACKLIBSRC = $(BLACKLIBDIR)/BlackGPIO.cpp $(BLACKLIBDIR)/BlackPWM.cpp $(BLACKLIBDIR)/BlackCore.cpp $(BLACKLIBDIR)/BlackTiming.cpp $(BLACKLIBDIR)/BlackADC.cpp $(BLACKLIBDIR)/BlackI2C.cpp $(BLACKLIBDIR)/BlackLib.cpp

SOURCE = $(EQEPDIR)/eqep.cpp $(SRCDIR)/controller.cpp $(SRCDIR)/PID.cpp $(BLACKLIBDIR)/BlackGPIO.cpp $(BLACKLIBDIR)/BlackPWM.cpp $(BLACKLIBDIR)/BlackCore.cpp
SOURCE_GPIO = $(SRCDIR)/test_GPIO.cpp $(BLACKLIBDIR)/BlackGPIO.cpp $(BLACKLIBDIR)/BlackCore.cpp $(BLACKLIBDIR)/Timing.cpp
SOURCE_PWM = $(SRCDIR)/test_PWM.cpp $(BLACKLIBDIR)/BlackPWM.cpp $(BLACKLIBDIR)/BlackCore.cpp $(BLACKLIBDIR)/Timing.cpp
SOURCE_ENCODERS = $(EQEPDIR)/eqep.cpp $(SRCDIR)/test_encoders.cpp

INCLUDES = -I./$(HEADERDIR) -I./$(EQEPDIR)/../include -I./$(BLACKLIBDIR)/../include
 
VPATH = $(EQEPDIR) $(SRCDIR) $(BLACKLIBDIR)
OBJ=$(join $(addsuffix ../obj/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.o)))
OBJ_GPIO=$(join $(addsuffix ../obj/, $(dir $(SOURCE_GPIO))), $(notdir $(SOURCE_GPIO:.cpp=.o)))
OBJ_PWM=$(join $(addsuffix ../obj/, $(dir $(SOURCE_PWM))), $(notdir $(SOURCE_PWM:.cpp=.o)))
OBJ_ENCODERS=$(join $(addsuffix ../obj/, $(dir $(SOURCE_ENCODERS))), $(notdir $(SOURCE_ENCODERS:.cpp=.o)))

## Fix dependency destination to be ../.dep relative to the src dir
DEPENDS=$(join $(addsuffix ../.dep/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.d)))
DEPENDS_GPIO=$(join $(addsuffix ../.dep/, $(dir $(SOURCE_GPIO))), $(notdir $(SOURCE_GPIO:.cpp=.d)))
DEPENDS_PWM=$(join $(addsuffix ../.dep/, $(dir $(SOURCE_PWM))), $(notdir $(SOURCE_PWM:.cpp=.d)))
DEPENDS_ENCODERS=$(join $(addsuffix ../.dep/, $(dir $(SOURCE_ENCODERS))), $(notdir $(SOURCE_ENCODERS:.cpp=.d)))

CPPFLAGS = -Wall -g -std=c++11 

## Default rule 
all : $(TARGET) 

## Rule for making the actual target
$(TARGET): $(OBJ)
		@echo "============="
		@echo $(OBJ)
		@echo "Linking the target $@"
		@echo "============="
		@$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)
		@echo -- Link finished --

## Rule for making the actual target
testGPIO: $(OBJ_GPIO)
		@echo "============="
		@echo $(OBJ_GPIO)
		@echo "Linking the target $@"
		@echo "============="
		@$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)
		@echo -- Link finished --

## Rule for making the actual target
testPWM: $(OBJ_PWM)
		@echo "============="
		@echo $(OBJ_PWM)
		@echo "Linking the target $@"
		@echo "============="
		@$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)
		@echo -- Link finished --

## Rule for making the actual target
testEncoders: $(OBJ_ENCODERS)
		@echo "============="
		@echo $(OBJ_ENCODERS)
		@echo "Linking the target $@"
		@echo "============="
		@$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)
		@echo -- Link finished --

## Clean Rulere
clean:
		@-rm -f $(TARGET) $(OBJ) $(DEPENDS) testGPIO $(OBJ_GPIO) $(DEPENDS_GPIO) testPWM $(OBJ_PWM) $(DEPENDS_PWM) testEncoders $(OBJ_ENCODERS) $(DEPENDS_ENCODERS)

## Rule for making the actual target
$(TARGET): $(OBJ)
		@echo "============="
		@echo $(OBJ)
		@echo "Linking the target $@"
		@echo "============="
		@$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)
		@echo -- Link finished --

## Generic compilation rule
%.o : %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo "Compiling $<"
		@$(CXX) $(CPPFLAGS) -c $< -o $@

## Rules for object files from cpp files
## Object file for each file is put in obj directory
## one level up from the actual source directory.
../obj/%.o : %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo "Compiling $<"
		@$(CXX) $(CPPFLAGS) -c $< -o $@

# Rule for "other directory"  You will need one per "other" dir
$(EQEPDIR)/../obj/%.o : %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo "Compiling $<"
		@$(CXX) $(CPPFLAGS) -c $< -o $@

# Rule for "other directory"  You will need one per "other" dir
$(SRCDIR)/../obj/%.o : %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo "Compiling $<"
		@$(CXX) $(CPPFLAGS) -c $< -o $@

# Rule for "other directory"  You will need one per "other" dir
$(BLACKLIBDIR)/../obj/%.o : %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo "Compiling $<"
		@$(CXX) $(CPPFLAGS) -c $< -o $@

## Make dependancy rules
../.dep/%.d: %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo Building dependencies file for $*.o
		@$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^../obj/$*.o^" > $@'

## Dependency rule for "other" directory
$(EQEPDIR)/../.dep/%.d: %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo Building dependencies file for $*.o
		@$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^$(EQEPDIR)/../obj/$*.o^" > $@'

## Dependency rule for "other" directory
$(SRCDIR)/../.dep/%.d: %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo Building dependencies file for $*.o
		@$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^$(SCRDIR)/../obj/$*.o^" > $@'

## Dependency rule for "other" directory
$(BLACKLIBDIR)/../.dep/%.d: %.cpp
		@mkdir -p $(dir $@)
		@echo "============="
		@echo Building dependencies file for $*.o
		@$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^$(SCRDIR)/../obj/$*.o^" > $@'


## Include the dependency files
-include $(DEPENDS)


