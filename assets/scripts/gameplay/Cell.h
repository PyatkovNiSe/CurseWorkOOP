#ifndef STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_CELL_H_
#define STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_CELL_H_

#include <utility>

#include "../utility/Size2.h"

namespace structopolis::gameplay {

struct Cell {
	utility::Size2 point;
	Resources resources;
	bool empty = true;

	Cell(const utility::Size2 &point, Resources resources)
			: point(point), resources(std::move(resources)) {}
};

} // gameplay

#endif //STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_CELL_H_
