#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_GOLD_H_
#define COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_GOLD_H_

namespace structopolis::gameplay {

struct Gold {
	float value{};

	bool operator==(const Gold &rhs) const {
		return value == rhs.value;
	}
	bool operator!=(const Gold &rhs) const {
		return !(rhs == *this);
	}
};

} // gameplay

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_GOLD_H_
