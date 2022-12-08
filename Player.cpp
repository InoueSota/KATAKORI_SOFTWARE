#include "Player.h"
#include "Key.h"


void Player::Init() {
	mPosition.x = 300;
	mPosition.y = 300;
	mRadius = 50;
}
void Player::Update() {

}
void Player::Draw(Screen& screen) {
	screen.DrawSquare(mPosition, mRadius, WHITE, kFillModeWireFrame);
}
