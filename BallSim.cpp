#include <ctime>
#include <cstdlib>

#include "game-engine/BallBounceEngine.h"
#include "game-components/Ball.h"
#include "Settings.h"

int main() {
	std::srand(std::time(nullptr));

	BallBounceEngine ballSim;
	if (ballSim.Construct(Settings::SCREEN_WIDTH, Settings::SCREEN_HEIGHT, Settings::PIXEL_WIDHT, Settings::PIXEL_HEIGHT)) {
		ballSim.addBall(Ball());
		ballSim.Start();
	}
}