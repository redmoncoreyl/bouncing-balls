#include "BallFactory.h"

BallFactory::BallFactory() : state(State::STAND_BY) {}

BallFactory BallFactory::instance = BallFactory();

BallFactory& BallFactory::getInstance() {
	return instance;
}