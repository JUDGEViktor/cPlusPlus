#pragma once

#include "resource.h"
using namespace std;

#define HEIGHT 20

enum collision {
	upper_collision,
	bottom_collision,
	right_collision,
	left_collision,
	no_collision
};

struct coordinates {
	float x;
	float y;
};

class Vector {

public:

	coordinates COORD;

	void ChangeX(float X) {
		COORD.x = X;
	}

	void ChangeY(float Y) {
		COORD.y = Y;
	};

	Vector& operator += (Vector& NewWay) {
		COORD.x += NewWay.COORD.x;
		COORD.y += NewWay.COORD.y;
		return *this;
	}
};

class Mob {

private:

	collision Collisions(RECT rcClient) {

		if (COORD.x + HEIGHT + Way.COORD.x > rcClient.right)
			return right_collision;
		else if (COORD.x + Way.COORD.x < rcClient.left)
			return left_collision;
		else if (COORD.y - HEIGHT + Way.COORD.y < rcClient.top)
			return bottom_collision;
		else if (COORD.y + Way.COORD.y > rcClient.bottom)
			return upper_collision;
		else
			return no_collision;
	}

public:

	Vector Way;//вектор движения

	coordinates COORD;
	
	void Move(RECT rcClient, Vector &NewWay) {

		switch (Collisions(rcClient)) {

		case right_collision:
			Way.ChangeX(-Way.COORD.x);
			
			break;

		case left_collision:
			Way.ChangeX(-Way.COORD.x);
			break;

		case upper_collision:
			Way.ChangeY(-Way.COORD.y);
			break;

		case bottom_collision:
			Way.ChangeY(-Way.COORD.y);
			break;

		case no_collision:
			COORD.x += Way.COORD.x;
			COORD.y += Way.COORD.y;
			break;
		}
	}

	void SetPosition(float X, float Y) {
		COORD.x = X;
		COORD.y = Y;
	}
};
