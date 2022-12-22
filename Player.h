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

	//�p�����[�^
	Vec2 mPosition;
	Vec2 mVelocity;
	float mSize;

	//�ʏ�ړ� = NormalMove
	Vec2 mNormalVelocity;
	float mNormalMag;
	void NormalMove();

};


