#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"


class Pencil : public BrushAbstract {

public:

	Pencil() : BrushAbstract() {}

	virtual void action(const coordinates& pointCoord) {
	}

	virtual void draw(HDC hdc) {
	}

};