#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"


class Eraser : public BrushAbstract {

public:

	Eraser() : BrushAbstract() {}

	virtual void draw(coordinates pointCoord, vector<vector<pixel>> canvas);


};