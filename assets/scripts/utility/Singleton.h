#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_SINGLETON_H
#define COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_SINGLETON_H

namespace structopolis::utility {
template<typename T>
class Singleton {
 public:
  Singleton(const Singleton &other) = delete;

  Singleton(Singleton &&other) noexcept = delete;

  Singleton &operator=(const Singleton &other) = delete;

  Singleton &operator=(Singleton &&other) noexcept = delete;

  template<typename ...Args>
  constexpr static T &GetInstance(Args ...args) {
	static T instance = T(args...);

	return instance;
  }

 protected:
  Singleton() = default;

  virtual ~Singleton() = default;
};
}

#endif
