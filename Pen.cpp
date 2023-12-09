/*
 * @file: Pen.cpp
 */

#include "Pen.h"

#include <iostream>

void Pen::draw(std::string text) {
  std::cout << text;
}

void Pen::stop() {
  std::cout << std::endl;
}
