#include "stdafx.h"
#include "Cell.h"


Cell::Cell(bool setStatus, const bonuses& setBonus, const coordinates& setCoordinates) {
	free = setStatus;
	bonus = setBonus;
	coord = setCoordinates;
}