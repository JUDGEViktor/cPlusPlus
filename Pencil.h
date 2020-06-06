#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"


class Pencil : public BrushAbstract {

public:

	Pencil() : BrushAbstract() {}

	virtual void draw(coordinates pointCoord, vector<vector<pixel>> canvas);

};