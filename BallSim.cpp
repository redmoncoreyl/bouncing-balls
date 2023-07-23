#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <ctime>
#include <cstdlib>

class BallSim : public olc::PixelGameEngine {
private:
	const int WIDTH, HEIGHT;

public:
	BallSim() : WIDTH(600), HEIGHT(600) {
		sAppName = "BallSim";
	}

	bool OnUserCreate() override {
		return true;
	}

	bool OnUserUpdate(float fTimeElapsed) override {
		int randomVariableX = std::rand() % WIDTH;
		int randomVariableY = std::rand() % HEIGHT;

		Draw(randomVariableX, randomVariableY);

		return true;
	}
};

// g++ -o BallSim.exe BallSim.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17
// .\BallSim.exe

int main() {
	std::srand(std::time(nullptr));

	BallSim ballSim;
	if (ballSim.Construct(600, 600, 1, 1)) {
		ballSim.Start();
	}
}