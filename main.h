#pragma once
#include <Novice.h>
#include "ControllerInput.h"
#include "Key.h"
#include "Vec2.h"
#include "Screen.h"
#include "Ingame.h"
#include "Player.h"

//インスタンス化
Screen screen;
Ingame ingame;
Player player;

//スイッチ文で main.cpp を分けるやつ
enum Scene
{
	TITLE,
	INGAME,
	OUTGAME
};
Scene scene = INGAME;
