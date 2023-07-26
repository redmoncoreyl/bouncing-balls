#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "BallBounceEngine.h"

BallBounceEngine::BallBounceEngine() : ballFactory(BallFactory::getInstance()) {
	sAppName = "Ball Bounce Engine";
}

bool BallBounceEngine::OnUserCreate() {
	return true;
}

bool BallBounceEngine::OnUserUpdate(float fTimeElapsed) {
	std::optional<Ball> newBall = ballFactory.updateSelf(fTimeElapsed, GetMouse(0), GetMousePos());
	if (newBall.has_value()) {
		balls.push_back(newBall.value());
	}

	for (auto& ball : balls) {
		ball.addForce(gravity);
	}

	for (auto& ball : balls) {
		ball.updateSelf(fTimeElapsed);
	}

	Clear(olc::BLACK);

	ballFactory.drawSelf(*this);
	for (auto ball : balls) {
		ball.drawSelf(*this);
	}

	return true;
}

void BallBounceEngine::setGravity(const Force& g) {
	gravity = g;
}

void BallBounceEngine::addBall(const Ball& b) {
	balls.push_back(b);
}