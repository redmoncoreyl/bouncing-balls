COMPILER = g++
COMPILE_FLAGS = -Wall -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17
OBJECTS = BallSim.o BallBounceEngine.o Ball.o
OBJECTS_FOLDER = objects

BallSim : $(OBJECTS)
	$(COMPILER) -o BallSim $(OBJECTS) $(COMPILE_FLAGS)

BallSim.o : BallSim.cpp
	$(COMPILER) -c BallSim.cpp

BallBounceEngine.o : game-engine/BallBounceEngine.cpp
	$(COMPILER) -c game-engine/BallBounceEngine.cpp

Ball.o : game-components/Ball.cpp
	$(COMPILER) -c game-components/Ball.cpp

