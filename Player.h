#pragma once
#include "Screen.h"
#include "Vec2.h"

class Player
{
public:

	Player() {
		Init();
	}

	void Init();
	void Update();
	void Draw(Screen& screen);

	//ƒpƒ‰ƒ[ƒ^
	Vec2 mPosition;
	Vec2 mVelocity;
	float mSize;

	//’ÊíˆÚ“® = NormalMove
	Vec2 mNormalVelocity;
	float mNormalMag;
	void NormalMove();

};


