#include "../game-engine/olcPixelGameEngine.h"

class Ball {
private:
	double x, y, r;

public:
	void drawSelf(olc::PixelGameEngine* pge);
};