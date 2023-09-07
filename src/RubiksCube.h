#pragma once

#include <utility>

#include "CubeEdge.h"

namespace cr {

enum class Face {
  kFront,
  kBack,
  kLeft,
  kRight,
  kTop,
  kBottom
};

enum class Direction {
  kClockwise,
  kCounterClockwise
};

struct Move {
  Face face_;
  Direction direction_;

  Move(const Face& face, const Direction& direction)
      : face_(face), direction_(direction) {}
  [[nodiscard]] Move GetInverse() const;
};

char FaceToChar(const Face& face);
char DirectionToChar(const Direction& direction);
std::ostream& operator<<(std::ostream& os, const Move& move);

class RubiksCube {
 public:
  RubiksCube();
  ~RubiksCube() = default;

  void Rotate(const Face& face, const Direction& direction);

  void Randomize();
  void Print() const;
  void PrintMovesHistory() const;
  void PrintSolve();
  [[nodiscard]] std::vector<Move> GetSolve();
  void Anew();

  void Save(const std::filesystem::path& path) const;
  void Load(const std::filesystem::path& path);
 private:
  CubeEdge front_edge_;
  CubeEdge back_edge_;
  CubeEdge left_edge_;
  CubeEdge right_edge_;
  CubeEdge top_edge_;
  CubeEdge bottom_edge_;
  std::vector<Move> moves_history_;
  void RotateFront(Direction direction);
  void RotateBack(Direction direction);
  void RotateLeft(Direction direction);
  void RotateRight(Direction direction);
  void RotateTop(Direction direction);
  void RotateBottom(Direction direction);
  void RotateFrontClockwise();
  void RotateFrontCounterClockwise();
  void RotateBackClockwise();
  void RotateBackCounterClockwise();
  void RotateLeftClockwise();
  void RotateLeftCounterClockwise();
  void RotateRightClockwise();
  void RotateRightCounterClockwise();
  void RotateTopClockwise();
  void RotateTopCounterClockwise();
  void RotateBottomClockwise();
  void RotateBottomCounterClockwise();
};

} // cr

