COMPILER = g++
COMPILE_FLAGS = -Wall -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

# Make does not offer a recursive wildcard function, so here's one:
# Credit: https://stackoverflow.com/a/12959764/3543696
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SOURCE_DIR = src
SOURCE_FILES = $(patsubst $(SOURCE_DIR)/%,%,$(call rwildcard,$(SOURCE_DIR)/,*.cpp))

BINARY_DIR = bin
BINARY_FILES = $(patsubst %.cpp,$(BINARY_DIR)/%.o,$(SOURCE_FILES))

BallSim : $(BINARY_FILES)
	$(COMPILER) -o BallSim $(BINARY_FILES) $(COMPILE_FLAGS)

$(BINARY_FILES): $(BINARY_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	mkdir -p $(@D)
	$(COMPILER) -c -o $@ $<

run :
	./BallSim

clean :
	rm -rf $(BINARY_DIR)
	rm -f BallSim