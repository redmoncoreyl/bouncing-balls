#ifndef BALL_FACTORY_H
#define BALL_FACTORY_H

class BallFactory {
public:
	enum class State { STAND_BY, BUILDING_BALL, BALL_READY };

private: 
	State state;

	static BallFactory instance;

	BallFactory();

public:
	static BallFactory& getInstance();
	
};

#endif