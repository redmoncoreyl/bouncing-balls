#include <ctime>
#include <cstdlib>

#include "game-engine/BallBounceEngine.h"
#include "game-components/Ball.h"
#include "game-components/Force.h"
#include "Settings.h"

using namespace Settings;

int main() {
	std::srand(std::time(nullptr));

	BallBounceEngine ballSim;

	if (ballSim.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, PIXEL_WIDHT, PIXEL_HEIGHT)) {
		ballSim.setGravity(Force(GRAVITY_X, GRAVITY_Y));
		ballSim.Start();
	}
}