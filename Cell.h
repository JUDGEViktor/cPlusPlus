#pragma once
#include "Libraries.h"

enum bonuses {
	REGULAR_POINT,    
	ENERGIZER,
	FRUIT,
	NONE
};



class Cell {

private:

	bool free;

	
	bonuses bonus;

	coordinates coord;


public:

	Cell(bool setStatus, const bonuses& setBonus, const coordinates& setCoordinates);

	bool IsFreee() const {
		return free;
	}

	bonuses WhatBonus() const {
		return bonus;
	}

	void ChangBonus(bonuses setBonus) {
		bonus = setBonus;
	}

	coordinates GetCoord() const {
		return coord;
	}

};


