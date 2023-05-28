#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_POINTER_LIST_H
#define COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_POINTER_LIST_H

#include <vector>
#include <cstdint>

namespace structopolis::utility {

template<class T>
class PointerList
	: public std::vector<T *> {
  using std::vector<T *>::vector;
  using Base = std::vector<T *>;

 public:
  [[nodiscard]]
  T &Get(const uint16_t i) {
	return *Base::at(i);
  }

  [[nodiscard]] const T &Get(const uint16_t i) const {
	return *Base::at(i);
  }
};

template<class T>
using ConstPointerList = PointerList<const T>;
}

#endif
