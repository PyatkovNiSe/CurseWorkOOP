#ifndef STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_CONDITIONFACTORY_H_
#define STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_CONDITIONFACTORY_H_

#include "Cell.h"

namespace structopolis::gameplay {

class ConditionFactory {
 public:
	virtual bool CheckCondition(Cell* cell) = 0;
};

class SupportBuildingCondition : public ConditionFactory{
 public:
	bool CheckCondition(Cell* cell) override {

	}
};

} // gameplay

#endif //STRUCTOPOLIS_ASSETS_SCRIPTS_GAMEPLAY_CONDITIONFACTORY_H_
