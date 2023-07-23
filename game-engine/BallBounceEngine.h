#include "olcPixelGameEngine.h"

class BallBounceEngine : public olc::PixelGameEngine {
private:

public:
	BallBounceEngine();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fTimeElapsed) override;
};