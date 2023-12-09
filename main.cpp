/*
 * @file for tests
 */

#include <iostream>

#include "Box.h"

int main() {
  Box box = Box(3, 7, PADDING_LEVEL_LARGE);

  box.draw();
  return 0;
}
