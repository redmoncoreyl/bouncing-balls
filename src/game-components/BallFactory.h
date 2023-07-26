#ifndef BALL_FACTORY_H
#define BALL_FACTORY_H

#include <optional>

#include "../game-engine/olcPixelGameEngine.h"
#include "Ball.h"

class BallFactory {
public:
	enum class State { STAND_BY, BUILDING_BALL, BALL_READY };

private: 
	State state;

	static BallFactory instance;

	BallFactory();

public:
	static BallFactory& getInstance();

	std::optional<Ball> updateSelf(float elapsedTimeSeconds, olc::HWButton leftMouseButton);
	
};

#endif