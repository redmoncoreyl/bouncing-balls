#ifndef BALL_H
#define BALL_H

#include "../game-engine/olcPixelGameEngine.h"

class Ball {
private:
	olc::vd2d position;
	unsigned int radius;

public:
	Ball();
	void drawSelf(olc::PixelGameEngine* pge);
};

#endif