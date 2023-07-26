#ifndef BALL_BOUNCE_ENGINE_H
#define BALL_BOUNCE_ENGINE_H

#include <vector>

#include "olcPixelGameEngine.h"
#include "../game-components/Ball.h"
#include "../game-components/Force.h"
#include "../game-components/BallFactory.h"

class BallBounceEngine : public olc::PixelGameEngine {
private:
	Force gravity;
	std::vector<Ball> balls;
	BallFactory ballFactory;

public:
	BallBounceEngine();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fTimeElapsed) override;

	void setGravity(const Force& g);
	void addBall(const Ball& b);
};

#endif