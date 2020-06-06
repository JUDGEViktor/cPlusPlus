#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"

class Rectangle : BrushAbstract{

private:


public:

	virtual void draw(coordinates pointCoord, vector<vector<pixel>> canvas) = 0;


};