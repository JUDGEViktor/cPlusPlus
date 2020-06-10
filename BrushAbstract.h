#pragma once
#include "Libraries.h"
#include "Canvas.h"
#include "Graphics.h"


class BrushAbstract : public Graphics{

protected:

	colorRGB color;

	int width;

public:

	BrushAbstract() {
		color = { 255, 255, 255 };
		width = 1;
	}

	virtual void action(const coordinates& pointCoord) = 0;

	virtual void draw(HDC hdc) = 0;

	void setColor(const colorRGB& setColor) {
		color = setColor;
	}

	void setWidth(const int setWidth) {
		width = setWidth;
	}


};