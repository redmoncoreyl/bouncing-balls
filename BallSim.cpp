#include <ctime>
#include <cstdlib>

#include "game-engine/BallBounceEngine.h"
#include "objects/Ball.h"
#include "Settings.h"

// g++ -o BallSim.exe BallSim.cpp .\game-engine\BallBounceEngine.cpp .\objects\Ball.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17
// .\BallSim.exe

int main() {
	std::srand(std::time(nullptr));

	BallBounceEngine ballSim;
	if (ballSim.Construct(Settings::SCREEN_WIDTH, Settings::SCREEN_HEIGHT, Settings::PIXEL_WIDHT, Settings::PIXEL_HEIGHT)) {
		ballSim.addBall(Ball());
		ballSim.Start();
	}
}