#include "BallFactory.h"

const double BallFactory::RADIUS_GROWTH_RATE = 30;

BallFactory::BallFactory() : state(State::STAND_BY) {}

BallFactory BallFactory::instance = BallFactory();

BallFactory& BallFactory::getInstance() {
	return instance;
}

std::optional<Ball> BallFactory::updateSelf(float timeElapsedSeconds, olc::HWButton leftMouseButton, olc::vi2d mousePosition) {
	if (state == State::STAND_BY && leftMouseButton.bPressed) state = State::BALL_GROWING;
	else if (state == State::BALL_GROWING && leftMouseButton.bPressed) state = State::BALL_DRAGGING;
	else if (state == State::BALL_DRAGGING && leftMouseButton.bReleased) state = State::BALL_RELEASING;
	
	if (state == State::BALL_GROWING) {
		ballRadius += RADIUS_GROWTH_RATE*timeElapsedSeconds;
	}

	if (state == State::BALL_RELEASING) {
		state = State::STAND_BY;
		double newBallRadius = ballRadius;
		ballRadius = 0;
		return Ball(newBallRadius, mousePosition, olc::vd2d());
	}

	return std::nullopt;
}

void BallFactory::drawSelf(olc::PixelGameEngine& pge) const {
	if (state == State::STAND_BY) return;
	pge.DrawCircle(pge.GetMousePos(), ballRadius);
}