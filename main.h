#pragma once
#include <Novice.h>
#include "Key.h"
#include "Vec2.h"
#include "Screen.h"
#include "Player.h"

//�C���X�^���X��
Screen screen;
Player player;

//�X�C�b�`���� main.cpp �𕪂�����
enum Scene
{
	TITLE,
	INGAME,
	OUTGAME
};
Scene scene = TITLE;
