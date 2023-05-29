#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_TIME_H_
#define COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_TIME_H_

#include <cstdint>
#include <thread>

#include "../utility/Signal.h"
#include "../utility/Singleton.h"

namespace structopolis::gameplay {

class Time final : public utility::Singleton<Time> {
	friend class utility::Singleton<Time>;

 public:
	utility::Signal<void(uint64_t)> OnLogicTick;

 private:
	uint32_t logic_delta_time_ = 100;
	uint64_t logic_tick_ = 0;
	bool active_ = false;

 public:
	[[nodiscard]]
	uint32_t GetLogicDeltaTime() const {
		return logic_delta_time_;
	}

	void Start() {
		active_ = true;

		std::jthread([this] {
			while (active_) {
				std::this_thread::sleep_for(std::chrono::milliseconds(logic_delta_time_));
				OnLogicTick.Notify(++logic_tick_);
			}
		}).detach();
	}

	void Stop() {
		active_ = false;
	}

 protected:
	Time() = default;

	~Time() override = default;
};

} // gameplay

#endif //COURSEWORKOOP_ASSETS_SCRIPTS_GAMEPLAY_TIME_H_
