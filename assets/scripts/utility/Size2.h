#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_SIZE_2_H
#define COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_SIZE_2_H

#include "Vector2.h"

namespace structopolis::utility {
class Size2 : public Vector2<float> {
 public:
  using Base = Vector2<float>;
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
  constexpr float GetWidth() const {
	return GetX();
  }

  [[nodiscard]]
  constexpr float GetHeight() const {
	return GetY();
  }

  void SetWidth(const float width) {
	SetX(width);
  }

  void SetHeight(const float width) {
	SetY(width);
  }

  [[nodiscard]]
  constexpr float GetSquare() const {
	return GetWidth() * GetHeight();
  }
};
}

#endif

