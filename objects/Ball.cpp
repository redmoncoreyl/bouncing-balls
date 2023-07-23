#include "Ball.h"

Ball::Ball() : position(10, 10), radius(30) {}

void Ball::drawSelf(olc::PixelGameEngine* pge) {
	pge->DrawCircle(position, radius);
}