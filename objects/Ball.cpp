#include "Ball.h"

void Ball::drawSelf(olc::PixelGameEngine* pge) {
	pge->DrawCircle(position, radius);
}