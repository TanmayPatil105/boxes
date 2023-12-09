/*
 * @file: Box.cpp
 */

#include "Box.h"

#include "Pen.h"

Box::Box(int rows = 1, int cols = 1) {
  n_rows = rows;
  n_cols = cols;
  padding_level = PADDING_LEVEL_SMALL;
}

Box::Box(int rows = 1, int cols = 1, PaddingLevel padding = PADDING_LEVEL_SMALL) {
  n_rows = rows;
  n_cols = cols;
  padding_level = padding;
}

void Box::draw_col_padding() {
  for (int level = 0; level < 3 * padding_level; level++) {
    Pen::draw(unicode.line_horizontal());
  }
}

void Box::draw_coord(int row_no, int col_no) {
  if (col_no == 0) {
    if (row_no == 0) {
      Pen::draw(unicode.top_left());
    } else if (row_no == n_rows) {
      Pen::draw(unicode.bottom_left());
    } else {
      Pen::draw(unicode.intersect_left());
    }
  } else if (col_no == n_cols) {
    if (row_no == 0) {
      Pen::draw(unicode.top_right());
    } else if (row_no == n_rows) {
      Pen::draw(unicode.bottom_right());
    } else {
      Pen::draw(unicode.intersect_right());
    }
  } else {
    if (row_no == 0) {
      Pen::draw(unicode.intersect_top());
    } else if (row_no == n_rows) {
      Pen::draw(unicode.intersect_bottom());
    } else {
      Pen::draw(unicode.intersect_middle());
    }
  }
}

void Box::draw_row(int row_no) {
  for (int i = 0; i <= n_cols; i++) {
    draw_coord(row_no, i);

    if (i == n_cols) break;

    draw_col_padding();
  }
}

static std::string calc_gaps(int pads) {
  return std::string(3 * pads, ' ');
}

void Box::draw_row_padding() {
  for (int i = 0; i <= n_cols; i++) {
    Pen::draw(unicode.line_vertical() + calc_gaps(static_cast<int>(padding_level)));
  }
}

void Box::draw() {
  for (int i = 0; i <= n_rows; i++) {
    draw_row(i);
    Pen::stop();

    if (i == n_rows) break;

    draw_row_padding();
    Pen::stop();
  }
}
