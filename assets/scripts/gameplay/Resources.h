#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_RESOURCES_H_
#define COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_RESOURCES_H_

#include <utility>

#include "Gold.h"
#include "Material.h"

namespace structopolis::gameplay {

struct Resources {
	Gold gold;
	Wood wood;
	Stone stone;
	Steel steel;

	constexpr explicit Resources(const float &gold,
															 const float & wood,
															 const float & stone,
															 const float & steel)
			: gold(gold),
				wood(wood),
				stone(stone),
				steel(steel) {}

	constexpr explicit Resources(const Gold &gold,
															 Wood wood,
															 Stone stone,
															 Steel steel)
			: gold(gold),
				wood(std::move(wood)),
				stone(std::move(stone)),
				steel(std::move(steel)) {}

	bool operator==(const Resources &rhs) const {
		return gold == rhs.gold &&
				wood == rhs.wood &&
				stone == rhs.stone &&
				steel == rhs.steel;
	}

	bool operator!=(const Resources &rhs) const {
		return !(rhs == *this);
	}
};

Resources GetMin(const Resources &lhs, const Resources &rhs) {
	return Resources{
			Gold(std::min(lhs.gold.value, rhs.gold.value)),
			Wood(std::min(lhs.wood.value, rhs.wood.value)),
			Stone(std::min(lhs.stone.value, rhs.stone.value)),
			Steel(std::min(lhs.steel.value, rhs.steel.value))
	};
}

} // gameplay

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_RESOURCES_H_
