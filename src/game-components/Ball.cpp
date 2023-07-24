#include "Ball.h"

Ball::Ball(unsigned int radius, olc::vd2d position, olc::vd2d velocity) : radius(radius), position(position), velocity(velocity) {}

void Ball::drawSelf(olc::PixelGameEngine* pge) {
	pge->DrawCircle(position, radius);
}