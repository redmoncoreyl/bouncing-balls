#ifndef BALL_BOUNCE_ENGINE_H
#define BALL_BOUNCE_ENGINE_H

#include <vector>

#include "olcPixelGameEngine.h"
#include "../game-components/Ball.h"

class BallBounceEngine : public olc::PixelGameEngine {
private:
	std::vector<Ball> balls;

public:
	BallBounceEngine();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fTimeElapsed) override;

	void addBall(const Ball& b);
};

#endif