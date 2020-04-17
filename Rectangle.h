#pragma once
#include "Header.h"


class MyRectangle {


protected:

	FRAME frame;

	COLOR color;


public:

	MyRectangle(FRAME newFrame, COLOR newColor) {
		frame.BEGINING_POINT.x = newFrame.BEGINING_POINT.x;
		frame.BEGINING_POINT.y = newFrame.BEGINING_POINT.y;
		frame.OPPOSIT_POINT.x = newFrame.OPPOSIT_POINT.x;
		frame.OPPOSIT_POINT.y = newFrame.OPPOSIT_POINT.y;

		color.R = newColor.R;
		color.G = newColor.G;
		color.B = newColor.B;
	}

	FRAME GetFrame() {
		return frame;
	}

	COLOR GetColor() {
		return color;
	}

};