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

	//パラメータ
	Vec2 mPosition;
	Vec2 mVelocity;
	float mSize;

	//通常移動 = NormalMove
	Vec2 mNormalVelocity;
	float mNormalMag;
	void NormalMove();

};


