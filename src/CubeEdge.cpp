#include <stdexcept>
#include <iostream>
#include <fstream>
#include "CubeEdge.h"

namespace cr {

std::array<CubeCell, kNumCells> CubeEdge::GetCells() const {
  return cells_;
}

void CubeEdge::SetCells(std::array<CubeCell, kNumCells> cells) {
  cells_ = cells;
}

void CubeEdge::Print() const {
  for (int i = 0; i < kNumCells; ++i) {
    std::cout << cells_[i].GetColor();
    if (i % 3 == 2) {
      std::cout << std::endl;
    }
  }
}

CubeEdge::CubeEdge(CubeEdgeInitializer initializer) {
  cells_ = initializer.cells;
}

CubeEdgeInitializer::CubeEdgeInitializer(char top_left,
                                         char top,
                                         char top_right,
                                         char left,
                                         char center,
                                         char right,
                                         char bottom_left,
                                         char bottom,
                                         char bottom_right) {
  cells[0].SetColor(CharToColor(top_left));
  cells[1].SetColor(CharToColor(top));
  cells[2].SetColor(CharToColor(top_right));
  cells[3].SetColor(CharToColor(left));
  cells[4].SetColor(CharToColor(center));
  cells[5].SetColor(CharToColor(right));
  cells[6].SetColor(CharToColor(bottom_left));
  cells[7].SetColor(CharToColor(bottom));
  cells[8].SetColor(CharToColor(bottom_right));
}
} // cr