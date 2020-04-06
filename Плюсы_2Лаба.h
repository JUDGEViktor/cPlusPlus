#pragma once

#include "resource.h"
#include <math.h>
#include <stdio.h>
#include <list>
using namespace std;

#define HEIGHT 20
#define NUMBER_TRACK 10

enum collisions {
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

public:
	
	Vector& operator += (Vector& NewWay) {
		COORD.x += NewWay.COORD.x;
		COORD.y += NewWay.COORD.y;
		return *this;
	}

	void ChangeX(float X) {
		COORD.x = X;
	}

	void ChangeY(float Y) {
		COORD.y = Y;
	}

	coordinates GetCOORD() {
		return COORD;
	}
};

class Mob {

private:
	
	Vector Way;//вектор движения

	coordinates COORD;

	collisions collisions_result(RECT rcClient) {

		if (COORD.x + HEIGHT + Way.GetCOORD().x > rcClient.right)
			return right_collision;
		else if (COORD.x + Way.GetCOORD().x < rcClient.left)
			return left_collision;
		else if (COORD.y - HEIGHT + Way.GetCOORD().y < rcClient.top)
			return bottom_collision;
		else if (COORD.y + Way.GetCOORD().y > rcClient.bottom)
			return upper_collision;
		else
			return no_collision;
	}

public:
	
	void AddVector(Vector NewWay) {
		Way += NewWay;
	}
	
	void Move(RECT rcClient, Vector &NewWay) {

		switch (collisions_result(rcClient)) {

		case right_collision:
			Way.ChangeX(-Way.GetCOORD().x);
			
			break;

		case left_collision:
			Way.ChangeX(-Way.GetCOORD().x);
			break;

		case upper_collision:
			Way.ChangeY(-Way.GetCOORD().y);
			break;

		case bottom_collision:
			Way.ChangeY(-Way.GetCOORD().y);
			break;

		case no_collision:
			COORD.x += Way.GetCOORD().x;
			COORD.y += Way.GetCOORD().y;
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
