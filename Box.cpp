/*
 * @file: Box.cpp
 */

#include "Box.h"
#include "Pen.h"


/*
 * FIXME: We have made it global for now,
 * probably we should let the user decide it
 */
#define PADDING_GAP 3
/*
 * Returns an integer equivalent for `PaddingLevel`
 */
#define INT_PADDING(level) (static_cast<int>(level) \
                              * PADDING_GAP)

#define N_ROW_PADDING(level) (static_cast<int>(level) - 1)

Box::Box (int rows = 1, int cols = 1)
{
  n_rows = rows;
  n_cols = cols;
  padding_level = PADDING_LEVEL_SMALL;
}

Box::Box (int rows = 1, int cols = 1, PaddingLevel padding = PADDING_LEVEL_SMALL)
{
  n_rows = rows;
  n_cols = cols;
  padding_level = padding;
}

void
Box::draw_col_padding (void)
{
  for (int level = 0; level < INT_PADDING (padding_level); level++) {
    Pen::draw (unicode.line_horizontal());
  }
}

void
Box::draw_coord (int row_no, int col_no)
{
  if (col_no == 0) {
    if (row_no == 0) {
      Pen::draw (unicode.top_left());
    } else if (row_no == n_rows) {
      Pen::draw (unicode.bottom_left());
    } else {
      Pen::draw (unicode.intersect_left());
    }
  } else if (col_no == n_cols) {
    if (row_no == 0) {
      Pen::draw (unicode.top_right());
    } else if (row_no == n_rows) {
      Pen::draw (unicode.bottom_right());
    } else {
      Pen::draw (unicode.intersect_right());
    }
  } else {
    if (row_no == 0) {
      Pen::draw (unicode.intersect_top());
    } else if (row_no == n_rows) {
      Pen::draw (unicode.intersect_bottom());
    } else {
      Pen::draw (unicode.intersect_middle());
    }
  }
}

void
Box::draw_row (int row_no)
{
  for (int i = 0; i <= n_cols; i++) {
    draw_coord(row_no, i);

    if (i == n_cols)
      break;

    draw_col_padding();
  }
  Pen::stop();
}

void
Box::draw_row_padding (void)
{
  for (int i = 0; i < N_ROW_PADDING (padding_level); i++) {
    for (int j = 0; j <= n_cols; j++) {
      Pen::draw (unicode.line_vertical());
      Pen::lift (INT_PADDING (padding_level));
    }

    if (i == N_ROW_PADDING (padding_level) - 1)
      break;

    Pen::stop();
  }

  if (N_ROW_PADDING (padding_level) > 0)
    Pen::stop();
}

void
Box::draw (void)
{
  for (int i = 0; i <= n_rows; i++) {
    draw_row(i);

    if (i == n_rows)
      break;

    draw_row_padding();
  }
}
