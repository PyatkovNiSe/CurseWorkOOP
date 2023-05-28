#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_BUILDING_H_
#define COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_BUILDING_H_

#include <thread>
#include <utility>

#include "../utility/Signal.h"
#include "Resources.h"
#include "IBuilding.h"
#include "Cell.h"

namespace structopolis::gameplay {

class Building : IBuilding {
 public:
	utility::Signal<void(Resources)> OnProduced;

 private:
	Resources cost_;
	Resources production_;
	float production_time_;
	std::function<void(uint64_t)> producer_;

 public:
	Building(Resources cost,
					 Resources production_per_time,
					 float production_time)
			: cost_(std::move(cost)),
				production_(std::move(production_per_time)),
				production_time_(production_time) {
		producer_ = [this](const uint64_t logic_tick){
			std::jthread([this]{
				std::this_thread::sleep_for(std::chrono::duration<float>(production_time_));
				OnProduced.Notify(production_);
			}).detach();
		};
	}

	[[nodiscard]] Resources GetCost() const override {
		return cost_;
	}

	void Build(Cell* cell) override {

	}
};
}

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_BUILDING_H_
