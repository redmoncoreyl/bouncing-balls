COMPILER = g++
COMPILE_FLAGS = -Wall -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

OBJECTS_DIR = objects
OBJECTS = $(addprefix $(OBJECTS_DIR)/, BallSim.o BallBounceEngine.o Ball.o)

SOURCE_DIR = src

BallSim : $(OBJECTS)
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