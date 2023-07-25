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
	return potentialEnergy(gravity) + kineticEnergy();
}

double Ball::potentialEnergy(const Force& gravity) {
	if (gravity.mag2() == 0) return 0;

	return mass()*gravity.mag()*height(gravity);
}

double Ball::height(const Force& gravity) {
	olc::vd2d groundVector = gravity.perp();
	olc::vd2d positionProjectionOntoGround = groundVector * position.dot(groundVector)/groundVector.mag2();
	olc::vd2d heightVector = position - positionProjectionOntoGround;
	
	return heightVector.mag();
}

double Ball::kineticEnergy() {
	return mass()*velocity.mag2()/2;
}

double Ball::mass() {
	return radius*radius;
}