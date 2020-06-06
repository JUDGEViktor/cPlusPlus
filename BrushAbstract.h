#pragma once
#include "Libraries.h"


class BrushAbstract {

protected:

	colorRGB color;

	int width;

	virtual void draw(coordinates pointCoord, vector<vector<pixel>> canvas) = 0;

	void setColor(colorRGB setColor) {
		color = setColor;
	}

	void setWidth(int setWidth) {
		width = setWidth;
	}


};



