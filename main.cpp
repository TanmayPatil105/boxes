/*
 * @file for tests
 */

#include <iostream>

#include "Box.h"

void
test_padding_none (void)
{
  std::cout << "NONE:" << std::endl;

  Box box = Box(3, 3, PADDING_LEVEL_NONE);

  box.draw();
}

void
test_padding_small (void)
{
  std::cout << "SMALL:" << std::endl;

  Box box = Box(3, 3, PADDING_LEVEL_SMALL);

  box.draw();
}

void
test_padding_normal (void)
{
  std::cout << "NORMAL + ARC BOUNDARIES:" << std::endl;

  Box box = Box(3, 3, PADDING_LEVEL_NORMAL, true);

  box.draw();
}

void
test_padding_large (void)
{
  std::cout << "LARGE:" << std::endl;

  Box box = Box(3, 3, PADDING_LEVEL_LARGE);

  box.draw();
}

int main() {
  test_padding_none ();
  test_padding_small ();
  test_padding_normal ();
  test_padding_large ();
  return 0;
}
