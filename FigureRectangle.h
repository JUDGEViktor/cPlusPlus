#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"


class FigureRectangle : public BrushAbstract {

private:

	const int countOfPointsToDraw = 2;

	vector<coordinates> points;


public:

	virtual void action(const coordinates& pointCoord);

	virtual void draw(HDC hdc);

};
