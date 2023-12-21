/*
 * @file: Pen.h
 */

#pragma once

#include <string>

class Pen {
 public:
  static void draw(std::string text);
  static void stop(void);
  static void lift (int gaps);
};
