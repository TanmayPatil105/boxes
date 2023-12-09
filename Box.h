/*
 * @file: Box.h
 */

#pragma once

#include <iostream>

#include "Box-unicode.h"

typedef enum {
  PADDING_LEVEL_NONE = 0,
  PADDING_LEVEL_SMALL,
  PADDING_LEVEL_NORMAL,
  PADDING_LEVEL_LARGE,
} PaddingLevel;

class Box {
 private:
  int n_rows;
  int n_cols;
  PaddingLevel padding_level;
  BoxUnicode unicode;

 public:
  Box(int, int);
  Box(int, int, PaddingLevel);
  void draw();
  void draw_row(int);
  void draw_row_padding();
  void draw_coord(int, int);
  void draw_col_padding();
};
