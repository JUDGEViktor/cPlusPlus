#include "stdafx.h"
#include "Graphics.h"

void Graphics::drawFilledRectangle(HDC hdc, const coordinates& firstPoint, const coordinates& secondPoint, const colorRGB& color) {
	HBRUSH hBrush; //создаём объект-кисть
	hBrush = CreateSolidBrush(RGB(color.r, color.g, color.b));
	RECT rect = { firstPoint.x, firstPoint.y, secondPoint.y, secondPoint.y };
	FillRect(hdc, &rect, hBrush);
	DeleteObject(hBrush);
}


void Graphics::drawFrameRectangle(HDC hdc, const coordinates& firstPoint, const coordinates& secondPoint, const colorRGB& color, const int& width) {
	COLORREF colorPen = RGB(color.r, color.g, color.b);
	HPEN hPen = CreatePen(PS_SOLID, width, colorPen); SelectObject(hdc, hPen);
	Rectangle(hdc, firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y);
	DeleteObject(hPen);
}

void Graphics::drawEllipse(HDC hdc, const coordinates& firstPoint, const coordinates& secondPoint, const colorRGB& color, const int& width) {
	COLORREF colorPen = RGB(color.r, color.g, color.b);
	HPEN hPen = CreatePen(PS_SOLID, width, colorPen); SelectObject(hdc, hPen);
	Ellipse(hdc, firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y);
	DeleteObject(hPen);
}


void Graphics::drawCanvas(HDC hdc, const Pixels& canvas) {
	for (auto line : canvas) {
		for (auto column : line) {
			drawFilledRectangle(hdc, column.pixelCoord, { column.pixelCoord.x + PIXEL_SIZE , column.pixelCoord.y - PIXEL_SIZE },
				column.pixelColor);
		}
	}
}