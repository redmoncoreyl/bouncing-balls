#ifndef BALL_FACTORY_H
#define BALL_FACTORY_H

#include <optional>
#include <queue>

#include "../game-engine/olcPixelGameEngine.h"
#include "Ball.h"

class BallFactory {
private:
	const static double RADIUS_GROWTH_RATE;
	const static double RELEASE_VELOCITY_DT;
	enum class State { STAND_BY, BALL_GROWING, BALL_DRAGGING, BALL_RELEASING};

	State state;
	double ballRadius;
	std::queue<std::pair<float, olc::vi2d> > previousMousePositions;
	double totalQueuedTime;

	static BallFactory instance;
	BallFactory();

public:
	static BallFactory& getInstance();

	std::optional<Ball> updateSelf(float timeElapsedSeconds, olc::HWButton leftMouseButton, olc::vd2d mousePosition);
	void drawSelf(olc::PixelGameEngine& pge) const;
};

#endif