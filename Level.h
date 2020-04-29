#pragma once
#include "Header.h"
#include "Cell.h"
#include "PacMan.h"
#include "Ghost.h"

// Class of levels. Include mass of cells = labyrinth
// Methods: generate bonuses, I think that's all for now.

class Level {

private:

	Cell Map[20][20];


public:

	Level() {}

	void GenerateBonuses() {}

};
