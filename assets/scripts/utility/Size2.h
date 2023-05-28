#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_SIZE_2_H
#define COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_SIZE_2_H

#include <cstdint>

#include "Vector2.h"

namespace structopolis::utility {
class Size2 : public Vector2<uint16_t> {
 public:
  using Base = Vector2<uint16_t>;
  using Base::Base;

 public:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
  Size2(const Base &base) : Base(base) {}
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
  Size2(Base &&base) noexcept: Base(base) {}
#pragma clang diagnostic pop

  [[nodiscard]]
  constexpr uint16_t GetWidth() const {
	return GetX();
  }

  [[nodiscard]]
  constexpr uint16_t GetHeight() const {
	return GetY();
  }

  void SetWidth(const uint16_t width) {
	SetX(width);
  }

  void SetHeight(const uint16_t width) {
	SetY(width);
  }

  [[nodiscard]]
  constexpr uint32_t GetSquare() const {
	return GetWidth() * GetHeight();
  }
};
}

#endif

