#include <ctime>
#include <cstdlib>

#include "game-engine/BallBounceEngine.h"

// g++ -o BallSim.exe BallSim.cpp .\game-engine\BallBounceEngine.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17
// .\BallSim.exe

int main() {
	std::srand(std::time(nullptr));

	BallBounceEngine ballSim;
	if (ballSim.Construct(600, 600, 1, 1)) {
		ballSim.Start();
	}
}