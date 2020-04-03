#pragma once

#include "resource.h"
#include <math.h>
#include <stdio.h>
#include <list>
using namespace std;

#define HEIGHT 20
#define NUMBER_TRACK 10

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
private:

	coordinates COORD;

	Vector& operator += (Vector& NewWay) {
		COORD.x += NewWay.COORD.x;
		COORD.y += NewWay.COORD.y;
		return *this;
	}

public:

	void ChangeX(float X) {
		COORD.x = X;
	}

	void ChangeY(float Y) {
		COORD.y = Y;
	}

	friend class Mob;
};

class Mob {

private:
	
	Vector Way;//вектор движения

	coordinates COORD;

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
	
	void AddVector(Vector NewWay) {
		Way += NewWay;
	}
	
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
	
	//Запоминаю последние NUMBER_TRACK положений
	void RememberPos(list <coordinates> &track) {
		if (track.size() <= NUMBER_TRACK)
			track.push_front(COORD);
		else {
			track.pop_back();
			track.push_front(COORD);
		}
	}
};
