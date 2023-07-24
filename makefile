COMPILER = g++
COMPILE_FLAGS = -Wall -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

OBJECTS_DIR = objects
OBJECTS = $(addprefix $(OBJECTS_DIR)/, BallSim.o BallBounceEngine.o Ball.o)

# Make does not offer a recursive wildcard function, so here's one:
# Credit: https://stackoverflow.com/a/12959764/3543696
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SOURCE_DIR = src
SOURCE_FILES = $(patsubst $(SOURCE_DIR)/%,%,$(call rwildcard,$(SOURCE_DIR)/,*.cpp))

BINARY_DIR = bin
BINARY_FILES = $(patsubst %.cpp,%.o,$(SOURCE_FILES))

BallSim : $(OBJECTS)
	echo $(SOURCE_FILES)
	echo $(BINARY_FILES)
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