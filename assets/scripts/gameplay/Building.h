#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_BUILDING_H_
#define COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_BUILDING_H_

#include <thread>
#include <utility>

#include "../utility/Signal.h"
#include "Resources.h"
#include "BuildingInfo.h"
#include "ConditionFactory.h"
#include "Cell.h"

namespace structopolis::gameplay {

class Building {
 public:
	utility::Signal<void(Resources)> OnProduced;

 private:
	const BuildingInfo *info_;

 public:
	constexpr Building(const BuildingInfo *info, float multiplier)
			: info_(info) {}

	[[nodiscard]]
	const BuildingInfo *GetInfo() const {
		return info_;
	}

	virtual bool Build(Cell* cell) = 0;
};
}

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_BUILDING_H_
