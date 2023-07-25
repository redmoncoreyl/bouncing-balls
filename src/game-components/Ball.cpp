#include "Ball.h"

Ball::Ball(unsigned int radius, olc::vd2d position, olc::vd2d velocity) : radius(radius), position(position), velocity(velocity) {}

void Ball::drawSelf(olc::PixelGameEngine* pge) {
	pge->DrawCircle(position, radius);
}

void Ball::addForce(const Force& force) {
	acceleration += force;
}

void Ball::updateSelf(const float& timeElapsedSeconds, const bool& resetAcceleration) {
	position += acceleration*timeElapsedSeconds*timeElapsedSeconds/2 + velocity*timeElapsedSeconds;
	velocity += acceleration*timeElapsedSeconds;
	if (resetAcceleration) this->resetAcceleration();
}

void Ball::resetAcceleration() {
	acceleration = olc::vd2d();
}