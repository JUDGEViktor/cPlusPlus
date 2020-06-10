#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"


class Eraser : public BrushAbstract {

public:

	Eraser() : BrushAbstract() {}

	//Paint always with white
	virtual void action(const coordinates& pointCoord) {
	}

	virtual void draw(HDC hdc) {
	}


};