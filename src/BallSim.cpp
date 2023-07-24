#include <ctime>
#include <cstdlib>

#include "game-engine/BallBounceEngine.h"
#include "game-components/Ball.h"
#include "Settings.h"

using namespace Settings;

int main() {
	std::srand(std::time(nullptr));

	BallBounceEngine ballSim;
	if (ballSim.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, PIXEL_WIDHT, PIXEL_HEIGHT)) {
		ballSim.addBall(Ball());
		ballSim.Start();
	}
}