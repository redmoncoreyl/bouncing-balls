#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "BallBounceEngine.h"

BallBounceEngine::BallBounceEngine() {
	sAppName = "Ball Bounce Engine";
}

bool BallBounceEngine::OnUserCreate() {
	return true;
}

bool BallBounceEngine::OnUserUpdate(float fTimeElapsed) {
	for (auto ball : balls) {
		ball.drawSelf(this);
	}

	return true;
}

void BallBounceEngine::setGravity(const Force& g) {
	gravity = g;
}

void BallBounceEngine::addBall(const Ball& b) {
	balls.push_back(b);
}