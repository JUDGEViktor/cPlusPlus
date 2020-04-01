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

private:
	coordinates COORD;

public:
	coordinates GetCOORD();

	void AddVector(Vector NewWay);

	void ChangeX(float X);

	void ChangeY(float Y);
};
Vector ObjVector;

coordinates Vector::GetCOORD() {
	return COORD;
}

void Vector::AddVector(Vector NewWay) {
	COORD.x += NewWay.GetCOORD().x;
	COORD.y += NewWay.GetCOORD().y;
}

void Vector::ChangeX(float X) {
	COORD.x = X;
}

void Vector::ChangeY(float Y) {
	COORD.y = Y;
}

class Mob {

private:
	coordinates COORD;

	Vector Way;//вектор движения

	Vector GetVector();

	collision Collisions(RECT rcClient);

public:

	void AddVector(Vector NewWay);

	void Move(RECT rcClient, Vector &NewWay);

	coordinates GetCOORD();

	void SetPosition(float X, float Y);
};
Mob ObjMob;

collision Mob::Collisions(RECT rcClient) {

	if (COORD.x + HEIGHT + GetVector().GetCOORD().x > rcClient.right)
		return right_collision;
	else if (COORD.x + GetVector().GetCOORD().x < rcClient.left)
		return left_collision;
	else if (COORD.y - HEIGHT + GetVector().GetCOORD().y < rcClient.top)
		return bottom_collision;
	else if (COORD.y + GetVector().GetCOORD().y > rcClient.bottom)
		return upper_collision;
	else
		return no_collision;
}

void Mob::AddVector(Vector NewWay) {
	Way.AddVector(NewWay);
}

void Mob::Move(RECT rcClient, Vector &NewWay) {//функция перемещения по вектору
	switch (Collisions(rcClient)) {

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


coordinates Mob::GetCOORD() {
	return COORD;
}

void Mob::SetPosition(float X, float Y) {
	COORD.x = X;
	COORD.y = Y;
}

Vector Mob::GetVector() {
	return Way;
}
