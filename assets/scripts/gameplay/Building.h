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
	utility::Signal<void(Cell*)> OnBuilt;

 private:
	const BuildingInfo *info_;
	float multiplier_ = 1;

 public:
	constexpr Building(const BuildingInfo *info, float multiplier)
			: info_(info), multiplier_(multiplier) {}

	[[nodiscard]]
	const BuildingInfo *GetInfo() const {
		return info_;
	}

	[[nodiscard]]
	float GetMultiplier() const {
		return multiplier_;
	}

	void SetMultiplier(float multiplier) {
		multiplier_ = multiplier;
	}

	void Build(Cell* cell) {
		Resources production = GetMin(cell->resources, info_.);
		if (!cell->empty || production == Resources{}) {
			return;
		}

		production_ = production;
		std::jthread([this]{
			while(true) {
				std::this_thread::sleep_for(std::chrono::duration<float>(
						production_time_ / multiplier_));
				OnProduced.Notify(production_);
			}
		}).detach();

		cell->empty = false;
		OnBuilt.Notify(cell);
	}
};
}

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_BUILDING_H_
