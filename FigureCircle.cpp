#include "stdafx.h"
#include "FigureCircle.h"


void FigureCircle::action(const coordinates& pointCoord) {
	if (points.size() < countOfPointsToDraw) {
		points.push_back(pointCoord);
	}
}

void FigureCircle::draw(HDC hdc) {
	if (points.size() == countOfPointsToDraw) {
		drawEllipse(hdc, points.at(0), points.at(1), color, width);
		points.clear();
	}
}