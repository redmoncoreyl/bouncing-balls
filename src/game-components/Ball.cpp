#include "Ball.h"

Ball::Ball(unsigned int radius, olc::vd2d position, olc::vd2d velocity) : radius(radius), position(position), velocity(velocity) {}

void Ball::drawSelf(olc::PixelGameEngine* pge) {
	pge->DrawCircle(position, radius);
}

void Ball::addForce(const Force& force) {
	acceleration += force;
}

void Ball::updateSelf(float timeElapsedSeconds, bool shouldResetAcceleration) {
	position += acceleration*timeElapsedSeconds*timeElapsedSeconds/2 + velocity*timeElapsedSeconds;
	velocity += acceleration*timeElapsedSeconds;
	if (shouldResetAcceleration) resetAcceleration();
}

void Ball::resetAcceleration() {
	acceleration = olc::vd2d();
}

double Ball::totalEnergy(const Force& gravity) {
	return potentialEnergy(gravity) + keneticEnergy();
}

double Ball::potentialEnergy(const Force& gravity) {
	
}

double Ball::keneticEnergy() {
	return mass()*velocity.mag2()/2;
}

double Ball::mass() {
	return radius*radius;
}