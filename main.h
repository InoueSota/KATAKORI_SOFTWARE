#pragma once
#include <Novice.h>
#include "Key.h"
#include "Vec2.h"
#include "Screen.h"
#include "Player.h"

//インスタンス化
Screen screen;
Player player;

//スイッチ文で main.cpp を分けるやつ
enum Scene
{
	TITLE,
	INGAME,
	OUTGAME
};
Scene scene = TITLE;
