/*
 * @file: Box-unicode.h
 */

#pragma once

#include <string>

class BoxUnicode {
  private:
    std::string _top_left = "┌";
    std::string _top_right = "┐";
    std::string _intersect_left = "├";
    std::string _intersect_top = "┬";
    std::string _intersect_right = "┤";
    std::string _intersect_bottom = "┴";
    std::string _intersect_middle = "┼";
    std::string _bottom_left = "└";
    std::string _bottom_right = "┘";
    std::string _line_horizontal = "─";
    std::string _line_vertical = "│";

  public:
    std::string top_left() {
      return _top_left;
    }

    std::string top_right() {
      return _top_right;
    }

    std::string intersect_left() {
      return _intersect_left;
    }

    std::string intersect_top() {
      return _intersect_top;
    }

    std::string intersect_right() {
      return _intersect_right;
    }

    std::string intersect_bottom() {
      return _intersect_bottom;
    }

    std::string intersect_middle() {
      return _intersect_middle;
    }

    std::string bottom_left() {
      return _bottom_left;
    }

    std::string bottom_right() {
      return _bottom_right;
    }

    std::string line_horizontal() {
      return _line_horizontal;
    }

    std::string line_vertical() {
      return _line_vertical;
    }
};
