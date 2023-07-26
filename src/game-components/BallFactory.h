#ifndef BALL_FACTORY_H
#define BALL_FACTORY_H

#include <optional>

#include "../game-engine/olcPixelGameEngine.h"
#include "Ball.h"

class BallFactory {
private:
	const static double RADIUS_GROWTH_RATE;
	enum class State { STAND_BY, BALL_GROWING, BALL_DRAGGING, BALL_RELEASING};
	State state;
	double ballRadius;

	static BallFactory instance;
	BallFactory();

public:
	static BallFactory& getInstance();

	std::optional<Ball> updateSelf(float timeElapsedSeconds, olc::HWButton leftMouseButton, olc::vi2d mousePosition);
	void drawSelf(olc::PixelGameEngine& pge) const;
};

#endif