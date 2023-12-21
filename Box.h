/*
 * @file: Box.h
 */

#pragma once

#include <iostream>
#include <cstdbool>
#include "Box-unicode.h"

typedef enum
{
  PADDING_LEVEL_NONE = 1,
  PADDING_LEVEL_SMALL,
  PADDING_LEVEL_NORMAL,
  PADDING_LEVEL_LARGE,
} PaddingLevel;

class Box {
  private:
    int          n_rows;
    int          n_cols;
    PaddingLevel padding_level;
    BoxUnicode   unicode;
    bool         arc_boundaries;

  public:
    Box       (int, int,
               PaddingLevel level  = PADDING_LEVEL_SMALL,
               bool arc_boundaries = false);
    void draw (void);

    /*
     * Returns the drawing in the form of string
     */
    std::string sketch (void);

  private:
    void draw_row         (int);
    void draw_row_padding (void);
    void draw_coord       (int, int);
    void draw_col_padding (void);
};
