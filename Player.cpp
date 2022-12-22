#include "Player.h"
#include "Key.h"
#include "ControllerInput.h"


void Player::Init() {
	//パラメータ
	mPosition.setZero();
	mVelocity.setZero();
	mSize = 64;

	//通常移動
	mNormalMag = 3.0f;
}

void Player::Update() {

	//速度を初期化する
	mVelocity.setZero();

	//通常移動
	NormalMove();

	//速度を代入する
	mPosition += mVelocity;

}

void Player::NormalMove() {

	//スティックの方向に移動する
	int tmpX, tmpY;
	Controller::GetLeftStick(0, tmpX, tmpY);

	//int型 の値を float型 に入れる（int型のままだと計算が０か１になる）
	mNormalVelocity.x = tmpX;
	mNormalVelocity.y = tmpY;

	//最大値を１にする
	mNormalVelocity = mNormalVelocity.Normalized();

	//ｎ倍する
	mNormalVelocity *= mNormalMag;

	//速度を代入する
	mVelocity += mNormalVelocity;
}

void Player::Draw(Screen& screen) {

	screen.DrawSquare(mPosition, mSize, 0x606060FF);

}
