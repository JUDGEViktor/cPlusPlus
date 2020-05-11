#pragma once
#include "Header.h"

enum status {
	REGULAR,
	FRIGHTENED
};

class GameMob {

private:

	status STATUS;

	coordinates COORD;

public:

	GameMob(coordinates setCoordinates) {
		STATUS = REGULAR;
		COORD.first = setCoordinates.first;
		COORD.second = setCoordinates.second;
	}

	coordinates& GetCOORD() {
		return COORD;
	}

	status GetStatus() {
		return STATUS;
	}


};
