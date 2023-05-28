#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_IBUILDING_H_
#define COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_IBUILDING_H_

#include "Resources.h"
#include "Cell.h"

namespace structopolis::gameplay {

class IBuilding {
 public:
	[[nodiscard]]
	virtual Resources GetCost() const = 0;

	virtual void Build(Cell* cell) = 0;

	virtual ~IBuilding() = default;
};

} // gameplay

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_IBUILDING_H_
