#include <iostream>

#include "assets/scripts/Scripts.h"

int main() {
  using namespace structopolis::utility;

  Rectangle rect = Rectangle(0, 0, 15, 15);
	std::cout << "[" <<  rect.GetLeft() << " " << rect.GetTop() << "] [" << rect.GetRight()  << " " << rect.GetBottom() << "]\n";


  rect.SetCenter({0, 0});

	std::cout << "[" <<  rect.GetLeft() << " " << rect.GetTop() << "] [" << rect.GetRight()  << " " << rect.GetBottom() << "]";

  return 0;
}