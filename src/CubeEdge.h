#pragma once

#include <vector>
#include <cstdint>
#include <array>
#include "CubeCell.h"

namespace cr {

static const uint8_t kNumCells = 9;

struct CubeEdgeInitializer {
  CubeEdgeInitializer(char top_left, char top, char top_right,
                      char left, char center, char right,
                      char bottom_left, char bottom, char bottom_right);
  std::array<CubeCell, kNumCells> cells;
};

class CubeEdge {
 public:
  explicit CubeEdge(CubeEdgeInitializer initializer);
  CubeEdge() = default;
  ~CubeEdge() = default;

  [[nodiscard]] std::array<CubeCell, kNumCells> GetCells() const;
  void SetCells(std::array<CubeCell, kNumCells> cells);

  void Print() const;
 private:
  std::array<CubeCell, kNumCells> cells_;
};

} // cr
