#pragma once
#include "Header.h"

enum bonuses {
	REGULAR_POINT,    //������� �����
	ENERGIZER,
	FRUIT,
	NONE
};

//����� ������, ������ ���������� � "������������" ������, � ����� ����� �� ��� �����

class Cell {

private:

	bool FREE;

	//����� �� �� ���� ������ �����-�� ����� � ����� �����
	bonuses BONUS;

	coordinates COORD;


public:

	Cell(bool setStatus, bonuses setBonus, coordinates setCoordinates) {
		FREE = setStatus;
		BONUS = setBonus;

		COORD.first = setCoordinates.first;
		COORD.second = setCoordinates.second;
	}

	bool IsFreee() {
		return FREE;
	}

	bonuses& WhatBonus() {
		return BONUS;
	}

	coordinates GetCOORD() {
		return COORD;
	}

};


