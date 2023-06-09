#ifndef COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_RECTANGLE_H
#define COURSEWORKOOP_ASSETS_SCRIPTS_UTILITY_RECTANGLE_H

#include <algorithm>

#include "Size2.h"

namespace structopolis::utility {
class Rectangle {
 private:
	Size2 p_1_, p_2_;

 public:
	constexpr Rectangle(const Size2 &p_1, const Size2 &p_2)
			: p_1_(std::min(p_1.GetX(), p_2.GetX()),
						 std::min(p_1.GetY(), p_2.GetY())),
				p_2_(std::max(p_1.GetX(), p_2.GetX()),
						 std::max(p_1.GetY(), p_2.GetY())) {

	}

	constexpr Rectangle(const float x_1,
											const float y_1,
											const float x_2,
											const float y_2)
			: p_1_(std::min(x_1, x_2), std::min(y_1, y_2)),
				p_2_(std::max(x_1, x_2), std::max(y_1, y_2)) {}

	[[nodiscard]]
	Size2 GetPos() const {
		return GetLeftTopCorner();
	}

	[[nodiscard]]
	float GetTop() const {
		return p_1_.GetY();
	}

	[[nodiscard]]
	float GetBottom() const {
		return p_2_.GetY();
	}

	[[nodiscard]]
	float GetLeft() const {
		return p_1_.GetX();
	}

	[[nodiscard]]
	float GetRight() const {
		return p_2_.GetX();
	}

	[[nodiscard]]
	Size2 GetLeftTopCorner() const {
		return p_1_;
	}

	[[nodiscard]]
	Size2 GetRightBottomCorner() const {
		return p_2_;
	}

	[[nodiscard]]
	Size2 GetLeftBottomCorner() const {
		return {p_1_.GetX(), p_2_.GetY()};
	}

	[[nodiscard]]
	Size2 GetRightTopCorner() const {
		return {p_2_.GetX(), p_1_.GetY()};
	}

	[[nodiscard]]
	Size2 GetCenter() const {
		return (p_1_ + p_2_) / 2;
	}

	[[nodiscard]]
	Size2 GetSize() const {
		return p_2_ - p_1_;
	}

	[[nodiscard]]
	float GetWidth() const {
		return GetSize().GetWidth();
	}

	[[nodiscard]]
	float GetHeight() const {
		return GetSize().GetHeight();
	}

	void SetPos(const Size2 &p) {
		SetLeftTopCorner(p);
	}

	void SetLeft(const float left) {
		*this = Rectangle(left, p_1_.GetY(), p_2_.GetX(), p_2_.GetY());
	}

	void SetTop(const float top) {
		*this = Rectangle(p_1_.GetX(), top, p_2_.GetX(), p_2_.GetY());
	}

	void SetBottom(const float bottom) {
		*this = Rectangle(p_1_.GetX(), p_1_.GetY(), p_2_.GetX(), bottom);
	}

	void SetRight(const float right) {
		*this = Rectangle(p_1_.GetX(), p_1_.GetY(), right, p_2_.GetY());
	}

	void SetLeftTopCorner(const Size2 &left_top) {
		*this = Rectangle(left_top, p_2_);
	}

	void SetRightBottomCorner(const Size2 &right_bottom) {
		*this = Rectangle(p_1_, right_bottom);
	}

	void SetRightTopCorner(const Size2 &right_top) {
		*this = Rectangle(p_1_.GetX(),
											right_top.GetY(),
											right_top.GetX(),
											p_2_.GetY());
	}

	void SetLeftBottomCorner(const Size2 &left_bottom) {
		*this = Rectangle(left_bottom.GetX(),
											p_1_.GetY(),
											p_2_.GetX(),
											left_bottom.GetY());
	}

	void SetWidth(const float width) {
		p_2_.SetX(p_1_.GetX() + width);
	}

	void SetHeight(const float height) {
		p_2_.SetY(p_1_.GetY() + height);
	}

	void SetHeight(const Size2 &size) {
		SetWidth(size.GetX());
		SetHeight(size.GetY());
	}

	void SetCenter(const Size2 &p) {
		Size2 shift = p - GetCenter();
		p_1_ += shift;
		p_2_ += shift;
	}

	[[nodiscard]]
	float GetSquare() const {
		return GetWidth() * GetHeight();
	}
};
}

#endif
