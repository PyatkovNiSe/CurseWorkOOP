#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_MATERIAL_H_
#define COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_MATERIAL_H_

#include <stdexcept>
#include <format>

#include "Gold.h"

namespace structopolis::gameplay {

struct Material {
	float value = 0;
	const Gold cost;

	constexpr Material(const float value, const Gold &cost) : value(value), cost(cost) {}

	virtual ~Material() = default;
};

struct Wood : public Material {
	constexpr explicit Wood(const float value = 0) : Material(value, Gold(0.05)) {}
};

struct Stone : public Material {
	constexpr explicit Stone(const float value = 0) : Material(value, Gold(0.1)) {}
};

struct Steel : public Material {
	constexpr explicit Steel(const float value = 0) : Material(value, Gold(0.5)) {}
};

} // gameplay

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_MATERIAL_H_
