#include "../game-engine/olcPixelGameEngine.h"

class Ball {
private:
	olc::vd2d position;
	unsigned int radius;

public:
	void drawSelf(olc::PixelGameEngine* pge);
};