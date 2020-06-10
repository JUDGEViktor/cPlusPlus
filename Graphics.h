#pragma once
#include "Libraries.h"
#include "Canvas.h"


class Graphics {

protected:

	void drawFilledRectangle(HDC hdc, const coordinates& firstPoint, const coordinates& secondPoint, const colorRGB& color);

	void drawFrameRectangle(HDC hdc, const coordinates& firstPoint, const coordinates& secondPoint, const colorRGB& color, const int& width);

	void drawEllipse(HDC hdc, const coordinates& firstPoint, const coordinates& secondPoint, const colorRGB& color, const int& width);

	void drawCanvas(HDC hdc, const Pixels& canvas);

};