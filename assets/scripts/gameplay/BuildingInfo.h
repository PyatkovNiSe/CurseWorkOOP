#ifndef STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_BUILDINGINFO_H_
#define STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_BUILDINGINFO_H_

#include <utility>

#include "Resources.h"

namespace structopolis::gameplay {

struct BuildingInfo {
	Resources cost;

	constexpr explicit BuildingInfo(Resources cost)
			: cost(std::move(cost)) {}

	virtual ~BuildingInfo() = default;
};

struct MiningBuildingInfo : public BuildingInfo {
	Resources production;
	float production_time;

	constexpr MiningBuildingInfo(const Resources &cost,
															 Resources production,
															 float production_time)
			: BuildingInfo(cost),
				production(std::move(production)),
				production_time(production_time) {}
};

struct SupportBuildingInfo : public BuildingInfo {
	float multiplier;

	constexpr SupportBuildingInfo(const Resources &cost, float multiplier) :
			BuildingInfo(cost), multiplier(multiplier) {}
};

struct MainBuildingInfo
		: public MiningBuildingInfo, public SupportBuildingInfo {

	constexpr MainBuildingInfo(const Resources &cost,
														 const Resources &production,
														 float production_time,
														 float multiplier) : MiningBuildingInfo(cost,
																																		production,
																																		production_time),
																								 SupportBuildingInfo(cost,
																																		 multiplier) {}
};

constexpr MiningBuildingInfo kSmallSawmillInfo{
		Resources{1, 0, 0, 0},
		Resources{0, 1, 0, 0},
		1
};

constexpr MiningBuildingInfo kSawmillInfo{
		Resources{5, 40, 0, 0},
		Resources{0, 5, 0, 0},
		1
};

constexpr MiningBuildingInfo kBigSawmillInfo{
		Resources{20, 100, 0, 5},
		Resources{0, 2, 0, 0},
		0.1
};

constexpr MiningBuildingInfo kSmallQuarryInfo{
		Resources{3, 15, 0, 0},
		Resources{0, 0, 0.5, 0.1},
		1
};

constexpr MiningBuildingInfo kQuarryInfo{
		Resources{10, 30, 15, 2},
		Resources{0, 0, 2, 0.2},
		1
};

constexpr MiningBuildingInfo kBigQuarryInfo{
		Resources{30, 10, 40, 15},
		Resources{0, 0, 10, 0.5},
		1
};

constexpr MiningBuildingInfo kSmallMineInfo{
		Resources{7, 40, 0, 10},
		Resources{0, 0, 1, 1},
		1
};

constexpr MiningBuildingInfo kMineInfo{
		Resources{25, 60, 15, 25},
		Resources{0, 0, 2, 3},
		1
};

constexpr MiningBuildingInfo kBigMineInfo{
		Resources{60, 80, 40, 50},
		Resources{0, 0, 4, 7},
		1
};

constexpr MainBuildingInfo kMainBuildingInfo{
		Resources{0, 0, 0, 0},
		Resources{1, 0, 0, 0},
		10,
		1.15
};

constexpr MainBuildingInfo Bank{
		Resources{20, 70, 35, 0},
		Resources{1, 0, 0, 0},
		5,
		0.8
};

constexpr SupportBuildingInfo kWoodenChurch{
		Resources{0, 50, 0, 0},
		1.1
};

constexpr SupportBuildingInfo kStoneChurch{
		Resources{0, 0, 30, 0},
		1.25
};

constexpr BuildingInfo kCastleInfo {
		Resources{200, 600, 500, 175}
};

} // gameplay

#endif //STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_BUILDINGINFO_H_
