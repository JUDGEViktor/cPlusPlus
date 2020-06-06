#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"

class Circle : BrushAbstract {

private:


public:

	virtual void draw(coordinates pointCoord, vector<vector<pixel>> canvas) = 0;


};