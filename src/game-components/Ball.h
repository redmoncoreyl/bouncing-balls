#ifndef BALL_H
#define BALL_H

#include "../game-engine/olcPixelGameEngine.h"
#include "Force.h"

class Ball {
private:
	olc::vd2d position, velocity, acceleration;
	unsigned int radius;

public:
	Ball(unsigned int radius, olc::vd2d position, olc::vd2d velocity);
	void drawSelf(olc::PixelGameEngine* pge);
	void addForce(const Force& force);
	void updateSelf(const float& elapsedTimeSeconds, const bool& resetAcceleration);
	void resetAcceleration();
};

#endif