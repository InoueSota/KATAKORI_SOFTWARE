#include "Player.h"
#include "Key.h"
#include "ControllerInput.h"


void Player::Init() {
	//�p�����[�^
	mPosition.setZero();
	mVelocity.setZero();
	mSize = 64;

	//�ʏ�ړ�
	mNormalMag = 3.0f;
}

void Player::Update() {

	//���x������������
	mVelocity.setZero();

	//�ʏ�ړ�
	NormalMove();

	//���x��������
	mPosition += mVelocity;

}

void Player::NormalMove() {

	//�X�e�B�b�N�̕����Ɉړ�����
	int tmpX, tmpY;
	Controller::GetLeftStick(0, tmpX, tmpY);

	//int�^ �̒l�� float�^ �ɓ����iint�^�̂܂܂��ƌv�Z���O���P�ɂȂ�j
	mNormalVelocity.x = tmpX;
	mNormalVelocity.y = tmpY;

	//�ő�l���P�ɂ���
	mNormalVelocity = mNormalVelocity.Normalized();

	//���{����
	mNormalVelocity *= mNormalMag;

	//���x��������
	mVelocity += mNormalVelocity;
}

void Player::Draw(Screen& screen) {

	screen.DrawSquare(mPosition, mSize, 0x606060FF);

}
