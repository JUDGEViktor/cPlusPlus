#include "stdafx.h"
#include "Element.h"



void Element::SetColor(vector<float> numbers) {
	color.r = numbers[0];
	color.g = numbers[1];
	color.b = numbers[2];
}


void Element::SetFrame(vector<float> numbers) {
	frame.BEGINING_POINT.x = numbers[0];
	frame.BEGINING_POINT.y = numbers[1];

	frame.OPPOSIT_POINT.x = numbers[2];
	frame.OPPOSIT_POINT.y = numbers[3];
}