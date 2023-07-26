#include "BallFactory.h"

BallFactory::BallFactory() : state(State::STAND_BY) {}

BallFactory BallFactory::instance = BallFactory();

BallFactory& BallFactory::getInstance() {
	return instance;
}

std::optional<Ball> BallFactory::updateSelf(float elapsedTimeSeconds, olc::HWButton leftMouseButton) {
	if (state == State::STAND_BY && leftMouseButton.bPressed) state = State::BUILDING_BALL;
	else if (state == State::BUILDING_BALL && leftMouseButton.bPressed) state = State::BALL_READY;
	else if (state == State::BALL_READY && leftMouseButton.bReleased) state = State::STAND_BY;
	
	return std::nullopt;
}