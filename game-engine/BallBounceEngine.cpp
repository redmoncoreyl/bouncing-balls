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
	int randomVariableX = std::rand() % ScreenWidth();
	int randomVariableY = std::rand() % ScreenHeight();

	Draw(randomVariableX, randomVariableY);

	return true;
}

void BallBounceEngine::addBall(const Ball& b) {
	balls.push_back(b);
}