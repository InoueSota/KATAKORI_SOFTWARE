#pragma once
#include <Novice.h>
#include "Vec2.h"

class Screen
{
public:

	static constexpr int kWindowWidth = 480;
	static constexpr int kWindowHeight = 320;

	Screen() {
		Init();
	}

private:

	Vec2 mWorldCenter;	//���[���h�̒��S
	Vec2 mScreenShake;	//�V�F�C�N�l
	Vec2 mScroll;		//�X�N���[���l
	float mZoom;		//�Y�[���l

public:


	/// <summary>
	/// ������
	/// </summary>
	void Init();

	/// <summary>
	/// �J�����V�F�C�N�i X�� �� Y�� �ǂ���������l �j
	/// </summary>
	/// <param name="min">�ŏ��l</param>
	/// <param name="max">�ő�l</param>
	/// <param name="condition">�V�F�C�N�������</param>
	void SetShake(int min, int max, bool condition);

	/// <summary>
	/// �J�����V�F�C�N�i X�� �� Y �� �ʂ̒l �j
	/// </summary>
	/// <param name="minX">�ŏ��l�i X�� �j</param>
	/// <param name="maxX">�ő�l�i X�� �j</param>
	/// <param name="minY">�ŏ��l�i Y�� �j</param>
	/// <param name="maxY">�ő�l�i Y�� �j</param>
	/// <param name="condition">�V�F�C�N�������</param>
	void SetShake(int minX, int maxX, int minY, int maxY, bool condition);

	/// <summary>
	/// �Y�[��
	/// </summary>
	void SetZoom();


	//--------------------------------------------------------------------------------------------//


	/// <summary>
	/// �l�p�`��`�悷��
	/// </summary>
	/// <param name="position">�`�悷��l�p�`�̍�����W</param>
	/// <param name="width">�`�悷��l�p�`�̉���</param>
	/// <param name="height">�`�悷��l�p�`�̏c��</param>
	/// <param name="angle">�`�悷��l�p�`�̉�]�p</param>
	/// <param name="color">�`�悷��l�p�`�̐F</param>
	/// <param name="fillMode">�h��Ԃ����[�h</param>
	void DrawBox(Vec2 position, float width, float height, float angle = 0.0f, unsigned int color = WHITE, FillMode fillMode = kFillModeSolid);

	/// <summary>
	/// �ȉ~��`�悷��
	/// </summary>
	/// <param name="position">�ȉ~�̒��S���W</param>
	/// <param name="radiusX">�ȉ~�̔��a (X����) </param>
	/// <param name="radiusY">�ȉ~�̔��a (Y����) </param>
	/// <param name="angle">�ȉ~�̉�]�p(rad)</param>
	/// <param name="color">�ȉ~�̐F</param>
	void DrawEllipse(Vec2 position, float radiusX, float radiusY, float angle = 0.0f, unsigned int color = WHITE, FillMode fillMode = kFillModeSolid);

	/// <summary>
	/// �~��`�悷��
	/// </summary>
	/// <param name="position">�~�̒��S���W</param>
	/// <param name="radius">�~�̔��a</param>
	/// <param name="color">�~�̐F</param>
	void DrawCircle(Vec2 position, float radius, unsigned int color = WHITE, FillMode fillMode = kFillModeSolid);

	//----- DrawBox �Ƃ̈Ⴂ �� Position �����S���W�ł���Ƃ��� -----//
	/// <summary>
	/// �����`��`�悷��
	/// </summary>
	/// <param name="position">���S���W</param>
	/// <param name="radius">���a</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="fillMode">�h��Ԃ����[�h</param>
	void DrawSquare(Vec2 position, float radius, unsigned int color = WHITE, FillMode fillMode = kFillModeSolid);

	/// <summary>
	/// �����`��`�悷��
	/// </summary>
	/// <param name="position">���S���W</param>
	/// <param name="Width">����</param>
	/// <param name="Height">�c��</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="fillMode">�h��Ԃ����[�h</param>
	void DrawRectAngle(Vec2 position, float width, float height, unsigned int color = WHITE, FillMode fillMode = kFillModeSolid);


	//--------------------------------------------------------------------------------------------//


	/// <summary>
	/// �X�N���[�����W�ɕϊ�����
	/// </summary>
	Vec2 ScreenTransform(Vec2 position);
};


