COMPILER = g++
COMPILE_FLAGS = -Wall -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

OBJECTS_DIR = objects
OBJECTS = $(addprefix $(OBJECTS_DIR)/, BallSim.o BallBounceEngine.o Ball.o)

SOURCE_DIR = src
# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# How to recursively find all files with the same name in a given folder
SOURCE_FILES := $(call rwildcard,src/,*.cpp)

BallSim : $(OBJECTS)
	echo $(SOURCE_FILES)
	$(COMPILER) -o BallSim $(OBJECTS) $(COMPILE_FLAGS)

$(OBJECTS_DIR)/BallSim.o : $(SOURCE_DIR)/BallSim.cpp
	mkdir -p $(OBJECTS_DIR)
	$(COMPILER) -c -o $@ $<

$(OBJECTS_DIR)/BallBounceEngine.o : $(SOURCE_DIR)/game-engine/BallBounceEngine.cpp
	mkdir -p $(OBJECTS_DIR)
	$(COMPILER) -c -o $@ $<

$(OBJECTS_DIR)/Ball.o : $(SOURCE_DIR)/game-components/Ball.cpp
	mkdir -p $(OBJECTS_DIR)
	$(COMPILER) -c -o $@ $<

run :
	./BallSim

clean :
	rm -rf $(OBJECTS_DIR)
	rm BallSim