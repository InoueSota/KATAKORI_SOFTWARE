#include "Screen.h"
#include "MatVec.h"
#include "Quad.h"
#include "Function.h"
#include "Key.h"



void Screen::Init() {
	mWorldCenter = { 0.0f, 0.0f };
	mScroll = { 0.0f, 0.0f };
	mZoom = 1.0f;
	mScreenShake = { 0.0f, 0.0f };
};

void Screen::SetShake(int min, int max, bool condition) {

	if (condition == true)
	{
		mScreenShake.x = RAND(min, max);
		mScreenShake.y = RAND(min, max);
	}
	else
	{
		mScreenShake = { 0.0f, 0.0f };
	}

}

void Screen::SetShake(int minX, int maxX, int minY, int maxY, bool condition) {

	if (condition == true)
	{
		mScreenShake.x = RAND(minX, maxX);
		mScreenShake.y = RAND(minY, maxY);
	}
	else
	{
		mScreenShake = { 0.0f, 0.0f };
	}

}

void Screen::SetZoom() {

	if (Key::IsPress(DIK_UP))
	{
		mZoom += 0.01f;
	}
	else if (Key::IsPress(DIK_DOWN))
	{
		mZoom -= 0.01f;
	}

}


//--------------------------------------------------------------------------------------------//


void Screen::DrawBox(Vec2 Position, float w, float h, float angle, unsigned int color, FillMode fillMode) {
	Position = ScreenTransform(Position);
	Novice::DrawBox((int)Position.x, (int)Position.y, w * mZoom, h * mZoom, angle, color, fillMode);
}


void Screen::DrawEllipse(Vec2 Position, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode) {
	Position = ScreenTransform(Position);
	Novice::DrawEllipse((int)Position.x, (int)Position.y, radiusX * mZoom, radiusY * mZoom, angle, color, fillMode);
}


void Screen::DrawCircle(Vec2 Position, float radius, unsigned int color, FillMode fillMode) {
	DrawEllipse(Position, radius, radius, 0.0f, color, fillMode);
}


void Screen::DrawSquare(Vec2 Position, float Radius, unsigned int color, FillMode fillMode) {
	DrawRectAngle(Position, Radius, Radius, color, fillMode);
}


void Screen::DrawRectAngle(Vec2 Position, float Width, float Height, unsigned int color, FillMode fillMode) {
	Quad OriginalPosition = RectAssign(Width, Height);
	Quad Rect = Transform(OriginalPosition, MakeAffineMatrix({ mZoom, mZoom }, 0.0f, ScreenTransform(Position)));
	if (fillMode == kFillModeSolid) {
		Novice::DrawQuad((int)Rect.LeftTop.x, (int)Rect.LeftTop.y, (int)Rect.RightTop.x, (int)Rect.RightTop.y, (int)Rect.LeftBottom.x, (int)Rect.LeftBottom.y, (int)Rect.RightBottom.x, (int)Rect.RightBottom.y, 0, 0, 0, 0, 0, color);
	}
	else {
		Novice::DrawLine((int)Rect.LeftTop.x, (int)Rect.LeftTop.y, (int)Rect.RightTop.x, (int)Rect.RightTop.y, color);
		Novice::DrawLine((int)Rect.LeftTop.x, (int)Rect.LeftTop.y, (int)Rect.LeftBottom.x, (int)Rect.LeftBottom.y, color);
		Novice::DrawLine((int)Rect.RightTop.x, (int)Rect.RightTop.y, (int)Rect.RightBottom.x, (int)Rect.RightBottom.y, color);
		Novice::DrawLine((int)Rect.LeftBottom.x, (int)Rect.LeftBottom.y, (int)Rect.RightBottom.x, (int)Rect.RightBottom.y, color);
	}
}


//--------------------------------------------------------------------------------------------//


Vec2 Screen::ScreenTransform(Vec2 Position) {

	return{
		Position.x * mZoom - mScroll.x + mWorldCenter.x + mScreenShake.x,
		Position.y * mZoom - mScroll.y + mWorldCenter.y + mScreenShake.y
	};
}