#include "stdafx.h"
#include "FigureRectangle.h"


void FigureRectangle::action(const coordinates& pointCoord) {
	if (points.size() < countOfPointsToDraw) {
		points.push_back(pointCoord);
	}
}

void FigureRectangle::draw(HDC hdc) {
	if (points.size() == countOfPointsToDraw) {
		drawFrameRectangle(hdc, points.at(0), points.at(1), color, width);
		points.clear();
	}
}