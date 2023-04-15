#pragma once
#include <Windows.h>


RECT GetRectWithXY(int x, int y, int xOffset, int yOffset, int size)
{

	RECT rect{};
	ZeroMemory(&rect, sizeof(RECT));

	int relativeX = x + xOffset;
	int relativeY = y + yOffset;

	rect.left = relativeX - size * 0.5f;
	rect.top = relativeY - size * 0.5f;
	rect.right = relativeX + size * 0.5f;
	rect.bottom = relativeY + size * 0.5f;

	return rect;
}