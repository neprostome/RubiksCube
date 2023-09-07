#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include "RubiksCube.h"

namespace cr {

void RubiksCube::Rotate(const Face& face, const Direction& direction) {
  switch (face) {
    case Face::kFront:RotateFront(direction);
      break;
    case Face::kBack:RotateBack(direction);
      break;
    case Face::kLeft:RotateLeft(direction);
      break;
    case Face::kRight:RotateRight(direction);
      break;
    case Face::kTop:RotateTop(direction);
      break;
    case Face::kBottom:RotateBottom(direction);
      break;
  }
}

void RubiksCube::Print() const {
  std::cout << "Front: " << std::endl;
  front_edge_.Print();
  std::cout << "Back: " << std::endl;
  back_edge_.Print();
  std::cout << "Left: " << std::endl;
  left_edge_.Print();
  std::cout << "Right: " << std::endl;
  right_edge_.Print();
  std::cout << "Top: " << std::endl;
  top_edge_.Print();
  std::cout << "Bottom: " << std::endl;
  bottom_edge_.Print();
}

void RubiksCube::RotateFront(Direction direction) {
  if (direction == Direction::kClockwise) {
    RotateFrontClockwise();
  } else {
    RotateFrontCounterClockwise();
  }
}

void RubiksCube::RotateFrontClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate front edge clockwise.
  front_edge_.SetCells({front_cells[6], front_cells[3], front_cells[0],
                        front_cells[7], front_cells[4], front_cells[1],
                        front_cells[8], front_cells[5], front_cells[2]});
  // Rotate left edge clockwise.
  left_edge_.SetCells({left_cells[0], left_cells[1], bottom_cells[0],
                       left_cells[3], left_cells[4], bottom_cells[1],
                       left_cells[6], left_cells[7], bottom_cells[2]});
  // Rotate right edge clockwise.
  right_edge_.SetCells({top_cells[6], right_cells[1], right_cells[2],
                        top_cells[7], right_cells[4], right_cells[5],
                        top_cells[8], right_cells[7], right_cells[8]});
  // Rotate top edge clockwise.
  top_edge_.SetCells({top_cells[0], top_cells[1], top_cells[2],
                      top_cells[3], top_cells[4], top_cells[5],
                      left_cells[2], left_cells[5], left_cells[8]});
  // Rotate bottom edge clockwise.
  bottom_edge_.SetCells({right_cells[6], right_cells[3], right_cells[0],
                         bottom_cells[3], bottom_cells[4], bottom_cells[5],
                         bottom_cells[6], bottom_cells[7], bottom_cells[8]});

  moves_history_.emplace_back(Face::kFront, Direction::kClockwise);
}

void RubiksCube::RotateFrontCounterClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate front edge counter-clockwise.
  front_edge_.SetCells({front_cells[2], front_cells[5], front_cells[8],
                        front_cells[1], front_cells[4], front_cells[7],
                        front_cells[0], front_cells[3], front_cells[6]});
  // Rotate left edge counter-clockwise.
  left_edge_.SetCells({left_cells[0], left_cells[1], top_cells[8],
                       left_cells[3], left_cells[4], top_cells[6],
                       left_cells[6], left_cells[7], top_cells[7]});
  // Rotate right edge counter-clockwise.
  right_edge_.SetCells({bottom_cells[2], right_cells[1], right_cells[2],
                        bottom_cells[1], right_cells[4], right_cells[5],
                        bottom_cells[0], right_cells[7], right_cells[8]});
  // Rotate top edge counter-clockwise.
  top_edge_.SetCells({top_cells[0], top_cells[1], top_cells[2],
                      top_cells[3], top_cells[4], top_cells[5],
                      right_cells[0], right_cells[3], right_cells[6]});
  // Rotate bottom edge counter-clockwise.
  bottom_edge_.SetCells({left_cells[2], left_cells[5], left_cells[8],
                         bottom_cells[3], bottom_cells[4], bottom_cells[5],
                         bottom_cells[6], bottom_cells[7], bottom_cells[8]});

  moves_history_.emplace_back(Face::kFront, Direction::kCounterClockwise);
}

void RubiksCube::RotateBack(Direction direction) {
  if (direction == Direction::kClockwise) {
    RotateBackClockwise();
  } else {
    RotateBackCounterClockwise();
  }
}

void RubiksCube::RotateBackClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate back edge clockwise.
  back_edge_.SetCells({back_cells[6], back_cells[3], back_cells[0],
                       back_cells[7], back_cells[4], back_cells[1],
                       back_cells[8], back_cells[5], back_cells[2]});
  // Rotate left edge clockwise.
  left_edge_.SetCells({bottom_cells[6], left_cells[1], left_cells[2],
                       bottom_cells[7], left_cells[4], left_cells[5],
                       bottom_cells[8], left_cells[7], left_cells[8]});
  // Rotate right edge clockwise.
  right_edge_.SetCells({right_cells[0], right_cells[1], top_cells[0],
                        right_cells[3], right_cells[4], top_cells[1],
                        right_cells[6], right_cells[7], top_cells[2]});
  // Rotate top edge clockwise.
  top_edge_.SetCells({left_cells[6], left_cells[3], left_cells[0],
                      top_cells[3], top_cells[4], top_cells[5],
                      top_cells[6], top_cells[7], top_cells[8]});
  // Rotate bottom edge clockwise.
  bottom_edge_.SetCells({bottom_cells[0], bottom_cells[1], bottom_cells[2],
                         bottom_cells[3], bottom_cells[4], bottom_cells[5],
                         right_cells[8], right_cells[5], right_cells[2]});

  moves_history_.emplace_back(Face::kBack, Direction::kClockwise);
}

void RubiksCube::RotateBackCounterClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate back edge counter-clockwise.
  back_edge_.SetCells({back_cells[2], back_cells[5], back_cells[8],
                       back_cells[1], back_cells[4], back_cells[7],
                       back_cells[0], back_cells[3], back_cells[6]});
  // Rotate left edge counter-clockwise.
  left_edge_.SetCells({top_cells[2], left_cells[1], left_cells[2],
                       top_cells[1], left_cells[4], left_cells[5],
                       top_cells[0], left_cells[7], left_cells[8]});
  // Rotate right edge counter-clockwise.
  right_edge_.SetCells({right_cells[0], right_cells[1], bottom_cells[8],
                        right_cells[3], right_cells[4], bottom_cells[7],
                        right_cells[6], right_cells[7], bottom_cells[6]});
  // Rotate top edge counter-clockwise.
  top_edge_.SetCells({right_cells[2], right_cells[5], right_cells[8],
                      top_cells[3], top_cells[4], top_cells[5],
                      top_cells[6], top_cells[7], top_cells[8]
                     });
  // Rotate bottom edge counter-clockwise.
  bottom_edge_.SetCells({bottom_cells[0], bottom_cells[1], bottom_cells[2],
                         bottom_cells[3], bottom_cells[4], bottom_cells[5],
                         left_cells[0], left_cells[3], left_cells[6]});

  moves_history_.emplace_back(Face::kBack, Direction::kCounterClockwise);
}

void RubiksCube::RotateLeft(Direction direction) {
  if (direction == Direction::kClockwise) {
    RotateLeftClockwise();
  } else {
    RotateLeftCounterClockwise();
  }
}

void RubiksCube::RotateLeftClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate left edge clockwise.
  left_edge_.SetCells({left_cells[6], left_cells[3], left_cells[0],
                       left_cells[7], left_cells[4], left_cells[1],
                       left_cells[8], left_cells[5], left_cells[2]});
  // Rotate front edge clockwise.
  front_edge_.SetCells({top_cells[0], front_cells[1], front_cells[2],
                        top_cells[3], front_cells[4], front_cells[5],
                        top_cells[6], front_cells[7], front_cells[8]});
  // Rotate back edge clockwise.
  back_edge_.SetCells({bottom_cells[6], back_cells[1], back_cells[2],
                       bottom_cells[3], back_cells[4], back_cells[5],
                       bottom_cells[0], back_cells[7], back_cells[8]});
  // Rotate top edge clockwise.
  top_edge_.SetCells({back_cells[6], top_cells[1], top_cells[2],
                      back_cells[3], top_cells[4], top_cells[5],
                      back_cells[0], top_cells[7], top_cells[8]});
  // Rotate bottom edge clockwise.
  bottom_edge_.SetCells({front_cells[0], bottom_cells[1], bottom_cells[2],
                         front_cells[3], bottom_cells[4], bottom_cells[5],
                         front_cells[6], bottom_cells[7], bottom_cells[8]});

  moves_history_.emplace_back(Face::kLeft, Direction::kClockwise);
}

void RubiksCube::RotateLeftCounterClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate left edge counter-clockwise.
  left_edge_.SetCells({left_cells[2], left_cells[5], left_cells[8],
                       left_cells[1], left_cells[4], left_cells[7],
                       left_cells[0], left_cells[3], left_cells[6]});
  // Rotate front edge counter-clockwise.
  front_edge_.SetCells({bottom_cells[0], front_cells[1], front_cells[2],
                        bottom_cells[3], front_cells[4], front_cells[5],
                        bottom_cells[6], front_cells[7], front_cells[8]});
  // Rotate back edge counter-clockwise.
  back_edge_.SetCells({top_cells[6], back_cells[1], back_cells[2],
                       top_cells[3], back_cells[4], back_cells[5],
                       top_cells[0], back_cells[7], back_cells[8]});
  // Rotate top edge counter-clockwise.
  top_edge_.SetCells({front_cells[0], top_cells[1], top_cells[2],
                      front_cells[3], top_cells[4], top_cells[5],
                      front_cells[6], top_cells[7], top_cells[8]});
  // Rotate bottom edge counter-clockwise.
  bottom_edge_.SetCells({back_cells[6], bottom_cells[1], bottom_cells[2],
                         back_cells[3], bottom_cells[4], bottom_cells[5],
                         back_cells[0], bottom_cells[7], bottom_cells[8]});

  moves_history_.emplace_back(Face::kLeft, Direction::kCounterClockwise);
}

void RubiksCube::RotateRight(Direction direction) {
  if (direction == Direction::kClockwise) {
    RotateRightClockwise();
  } else {
    RotateRightCounterClockwise();
  }
}

void RubiksCube::RotateRightClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate right edge clockwise.
  right_edge_.SetCells({right_cells[6], right_cells[3], right_cells[0],
                        right_cells[7], right_cells[4], right_cells[1],
                        right_cells[8], right_cells[5], right_cells[2]});
  // Rotate front edge clockwise.
  front_edge_.SetCells({front_cells[0], front_cells[1], bottom_cells[2],
                        front_cells[3], front_cells[4], bottom_cells[5],
                        front_cells[6], front_cells[7], bottom_cells[8]});
  // Rotate back edge clockwise.
  back_edge_.SetCells({back_cells[0], back_cells[1], top_cells[8],
                       back_cells[3], back_cells[4], top_cells[5],
                       back_cells[6], back_cells[7], top_cells[2]});
  // Rotate top edge clockwise.
  top_edge_.SetCells({top_cells[0], top_cells[1], front_cells[2],
                      top_cells[3], top_cells[4], front_cells[5],
                      top_cells[6], top_cells[7], front_cells[8]});
  // Rotate bottom edge clockwise.
  bottom_edge_.SetCells({bottom_cells[0], bottom_cells[1], back_cells[8],
                         bottom_cells[3], bottom_cells[4], back_cells[5],
                         bottom_cells[6], bottom_cells[7], back_cells[2]});

  moves_history_.emplace_back(Face::kRight, Direction::kClockwise);
}

void RubiksCube::RotateRightCounterClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate right edge counter-clockwise.
  right_edge_.SetCells({right_cells[2], right_cells[5], right_cells[8],
                        right_cells[1], right_cells[4], right_cells[7],
                        right_cells[0], right_cells[3], right_cells[6]});
  // Rotate front edge counter-clockwise.
  front_edge_.SetCells({front_cells[0], front_cells[1], top_cells[2],
                        front_cells[3], front_cells[4], top_cells[5],
                        front_cells[6], front_cells[7], top_cells[8]});
  // Rotate back edge counter-clockwise.
  back_edge_.SetCells({back_cells[0], back_cells[1], bottom_cells[8],
                       back_cells[3], back_cells[4], bottom_cells[5],
                       back_cells[6], back_cells[7], bottom_cells[2]});
  // Rotate top edge counter-clockwise.
  top_edge_.SetCells({top_cells[0], top_cells[1], back_cells[8],
                      top_cells[3], top_cells[4], back_cells[5],
                      top_cells[6], top_cells[7], back_cells[2]});
  // Rotate bottom edge counter-clockwise.
  bottom_edge_.SetCells({bottom_cells[0], bottom_cells[1], front_cells[2],
                         bottom_cells[3], bottom_cells[4], front_cells[5],
                         bottom_cells[6], bottom_cells[7], front_cells[8]});

  moves_history_.emplace_back(Face::kRight, Direction::kCounterClockwise);
}

void RubiksCube::RotateTop(Direction direction) {
  if (direction == Direction::kClockwise) {
    RotateTopClockwise();
  } else {
    RotateTopCounterClockwise();
  }
}

void RubiksCube::RotateTopClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate top edge clockwise.
  top_edge_.SetCells({top_cells[0], top_cells[3], top_cells[6],
                      top_cells[1], top_cells[4], top_cells[7],
                      top_cells[2], top_cells[5], top_cells[8]});
  // Rotate front edge clockwise.
  front_edge_.SetCells({left_cells[0], left_cells[1], left_cells[2],
                        front_cells[3], front_cells[4], front_cells[5],
                        front_cells[6], front_cells[7], front_cells[8]});
  // Rotate back edge clockwise.
  back_edge_.SetCells({right_cells[2], right_cells[1], right_cells[0],
                       back_cells[3], back_cells[4], back_cells[5],
                       back_cells[6], back_cells[7], back_cells[8]});
  // Rotate left edge clockwise.
  left_edge_.SetCells({back_cells[2], back_cells[1], back_cells[0],
                       left_cells[3], left_cells[4], left_cells[5],
                       left_cells[6], left_cells[7], left_cells[8]});
  // Rotate right edge clockwise.
  right_edge_.SetCells({front_cells[0], front_cells[1], front_cells[2],
                        right_cells[3], right_cells[4], right_cells[5],
                        right_cells[6], right_cells[7], right_cells[8]});

  moves_history_.emplace_back(Face::kTop, Direction::kClockwise);
}

void RubiksCube::RotateTopCounterClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();
  // Rotate top edge counter-clockwise.
  top_edge_.SetCells({top_cells[6], top_cells[3], top_cells[0],
                      top_cells[7], top_cells[4], top_cells[1],
                      top_cells[8], top_cells[5], top_cells[2]});
  // Rotate front edge counter-clockwise.
  front_edge_.SetCells({right_cells[0], right_cells[1], right_cells[2],
                        front_cells[3], front_cells[4], front_cells[5],
                        front_cells[6], front_cells[7], front_cells[8]});
  // Rotate back edge counter-clockwise.
  back_edge_.SetCells({left_cells[2], left_cells[1], left_cells[0],
                       back_cells[3], back_cells[4], back_cells[5],
                       back_cells[6], back_cells[7], back_cells[8]});
  // Rotate left edge counter-clockwise.
  left_edge_.SetCells({front_cells[0], front_cells[1], front_cells[2],
                       left_cells[3], left_cells[4], left_cells[5],
                       left_cells[6], left_cells[7], left_cells[8]});
  // Rotate right edge counter-clockwise.
  right_edge_.SetCells({back_cells[2], back_cells[1], back_cells[0],
                        right_cells[3], right_cells[4], right_cells[5],
                        right_cells[6], right_cells[7], right_cells[8]});

  moves_history_.emplace_back(Face::kTop, Direction::kCounterClockwise);
}

void RubiksCube::RotateBottom(Direction direction) {
  if (direction == Direction::kClockwise) {
    RotateBottomClockwise();
  } else {
    RotateBottomCounterClockwise();
  }
}

void RubiksCube::RotateBottomClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate bottom edge clockwise.
  bottom_edge_.SetCells({bottom_cells[6], bottom_cells[3], bottom_cells[0],
                         bottom_cells[7], bottom_cells[4], bottom_cells[1],
                         bottom_cells[8], bottom_cells[5], bottom_cells[2]});
  // Rotate front edge clockwise.
  front_edge_.SetCells({front_cells[0], front_cells[1], front_cells[2],
                        front_cells[3], front_cells[4], front_cells[5],
                        left_cells[6], left_cells[7], left_cells[8]});
  // Rotate back edge clockwise.
  back_edge_.SetCells({back_cells[0], back_cells[1], back_cells[2],
                       back_cells[3], back_cells[4], back_cells[5],
                       right_cells[8], right_cells[7], right_cells[6]});
  // Rotate left edge clockwise.
  left_edge_.SetCells({left_cells[0], left_cells[1], left_cells[2],
                       left_cells[3], left_cells[4], left_cells[5],
                       back_cells[8], back_cells[7], back_cells[6]});
  // Rotate right edge clockwise.
  right_edge_.SetCells({right_cells[0], right_cells[1], right_cells[2],
                        right_cells[3], right_cells[4], right_cells[5],
                        front_cells[6], front_cells[7], front_cells[8]});

  moves_history_.emplace_back(Face::kBottom, Direction::kClockwise);
}

void RubiksCube::RotateBottomCounterClockwise() {
  std::array<CubeCell, kNumCells> front_cells = front_edge_.GetCells();
  std::array<CubeCell, kNumCells> back_cells = back_edge_.GetCells();
  std::array<CubeCell, kNumCells> left_cells = left_edge_.GetCells();
  std::array<CubeCell, kNumCells> right_cells = right_edge_.GetCells();
  std::array<CubeCell, kNumCells> top_cells = top_edge_.GetCells();
  std::array<CubeCell, kNumCells> bottom_cells = bottom_edge_.GetCells();

  // Rotate bottom edge counter-clockwise.
  bottom_edge_.SetCells({bottom_cells[2], bottom_cells[5], bottom_cells[8],
                         bottom_cells[1], bottom_cells[4], bottom_cells[7],
                         bottom_cells[0], bottom_cells[3], bottom_cells[6]});
  // Rotate front edge counter-clockwise.
  front_edge_.SetCells({front_cells[0], front_cells[1], front_cells[2],
                        front_cells[3], front_cells[4], front_cells[5],
                        right_cells[6], right_cells[7], right_cells[8]});
  // Rotate back edge counter-clockwise.
  back_edge_.SetCells({back_cells[0], back_cells[1], back_cells[2],
                       back_cells[3], back_cells[4], back_cells[5],
                       left_cells[8], left_cells[7], left_cells[6]});
  // Rotate left edge counter-clockwise.
  left_edge_.SetCells({left_cells[0], left_cells[1], left_cells[2],
                       left_cells[3], left_cells[4], left_cells[5],
                       front_cells[6], front_cells[7], front_cells[8]});
  // Rotate right edge counter-clockwise.
  right_edge_.SetCells({right_cells[0], right_cells[1], right_cells[2],
                        right_cells[3], right_cells[4], right_cells[5],
                        back_cells[8], back_cells[7], back_cells[6]});

  moves_history_.emplace_back(Face::kBottom, Direction::kCounterClockwise);
}

RubiksCube::RubiksCube() {
  front_edge_ = CubeEdge({'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'});
  back_edge_ = CubeEdge({'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'});
  left_edge_ = CubeEdge({'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'});
  right_edge_ = CubeEdge({'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'});
  top_edge_ = CubeEdge({'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'});
  bottom_edge_ = CubeEdge({'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'});
}

void RubiksCube::Randomize() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 11);
  std::uniform_int_distribution<> dis2(10, 25);
  int num_rotations = dis2(gen);
  for (int i = 0; i < num_rotations; ++i) {
    int random = dis(gen);
    switch (random) {
      case 0:Rotate(Face::kFront, Direction::kClockwise);
        break;
      case 1:Rotate(Face::kBack, Direction::kClockwise);
        break;
      case 2:Rotate(Face::kLeft, Direction::kClockwise);
        break;
      case 3:Rotate(Face::kRight, Direction::kClockwise);
        break;
      case 4:Rotate(Face::kTop, Direction::kClockwise);
        break;
      case 5:Rotate(Face::kBottom, Direction::kClockwise);
        break;
      case 6:Rotate(Face::kFront, Direction::kCounterClockwise);
        break;
      case 7:Rotate(Face::kBack, Direction::kCounterClockwise);
        break;
      case 8:Rotate(Face::kLeft, Direction::kCounterClockwise);
        break;
      case 9:Rotate(Face::kRight, Direction::kCounterClockwise);
        break;
      case 10:Rotate(Face::kTop, Direction::kCounterClockwise);
        break;
      case 11:Rotate(Face::kBottom, Direction::kCounterClockwise);
        break;
      default:break;
    }
  }
}

void RubiksCube::PrintMovesHistory() const {
  std::cout << "Moves history: " << std::endl;
  for (auto i : moves_history_) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void RubiksCube::PrintSolve() {
  std::cout << "Solve: " << std::endl;
  std::vector<Move> solve = GetSolve();
  for (auto i : solve) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

std::vector<Move> RubiksCube::GetSolve() {
  std::vector<Move> solve;
  std::vector<Move> moves_history_copy = moves_history_;
  std::reverse(moves_history_copy.begin(), moves_history_copy.end());
  for (auto i : moves_history_copy) {
    solve.push_back(i.GetInverse());
  }
  return solve;
}

void RubiksCube::Anew() {
  moves_history_.clear();
  front_edge_ = CubeEdge({'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'});
  back_edge_ = CubeEdge({'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'});
  left_edge_ = CubeEdge({'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'});
  right_edge_ = CubeEdge({'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'});
  top_edge_ = CubeEdge({'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'});
  bottom_edge_ = CubeEdge({'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'});
}

void RubiksCube::Save(const std::filesystem::path& path) const {
  std::ofstream file(path, std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Can't open file");
  }

  for (auto i : moves_history_) {
    char face = static_cast<char>(i.face_);
    char direction = static_cast<char>(i.direction_);
    file.write(&face, sizeof(char));
    file.write(&direction, sizeof(char));
  }
  file.write("Q", sizeof(char));
  for (auto i : front_edge_.GetCells()) {
    Color color = i.GetColor();
    file.write(reinterpret_cast<const char*>(&color), sizeof(color));
  }

  for (auto i : back_edge_.GetCells()) {
    Color color = i.GetColor();
    file.write(reinterpret_cast<const char*>(&color), sizeof(color));
  }

  for (auto i : left_edge_.GetCells()) {
    Color color = i.GetColor();
    file.write(reinterpret_cast<const char*>(&color), sizeof(color));
  }

  for (auto i : right_edge_.GetCells()) {
    Color color = i.GetColor();
    file.write(reinterpret_cast<const char*>(&color), sizeof(color));
  }

  for (auto i : top_edge_.GetCells()) {
    Color color = i.GetColor();
    file.write(reinterpret_cast<const char*>(&color), sizeof(color));
  }

  for (auto i : bottom_edge_.GetCells()) {
    Color color = i.GetColor();
    file.write(reinterpret_cast<const char*>(&color), sizeof(color));
  }

  file.close();
}

void RubiksCube::Load(const std::filesystem::path& path) {
  std::ifstream file(path, std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Can't open file");
  }

  moves_history_.clear();
  char face;
  char direction;
  while (true) {
    file.read(&face, sizeof(char));
    if (face == 'Q') {
      break;
    }
    file.read(&direction, sizeof(char));
    Move move(static_cast<Face>(face), static_cast<Direction>(direction));
    moves_history_.push_back(move);
  }

  std::array<CubeCell, kNumCells> front_edge_cells;
  for (int i = 0; i < kNumCells; ++i) {
    Color color;
    file.read(reinterpret_cast<char*>(&color), sizeof(color));
    CubeCell cell(color);
    front_edge_cells[i] = cell;
  }
  front_edge_.SetCells(front_edge_cells);

  std::array<CubeCell, kNumCells> back_edge_cells;
  for (int i = 0; i < kNumCells; ++i) {
    Color color;
    file.read(reinterpret_cast<char*>(&color), sizeof(color));
    CubeCell cell(color);
    back_edge_cells[i] = cell;
  }

  back_edge_.SetCells(back_edge_cells);

  std::array<CubeCell, kNumCells> left_edge_cells;
  for (int i = 0; i < kNumCells; ++i) {
    Color color;
    file.read(reinterpret_cast<char*>(&color), sizeof(color));
    CubeCell cell(color);
    left_edge_cells[i] = cell;
  }

  left_edge_.SetCells(left_edge_cells);

  std::array<CubeCell, kNumCells> right_edge_cells;
  for (int i = 0; i < kNumCells; ++i) {
    Color color;
    file.read(reinterpret_cast<char*>(&color), sizeof(color));
    CubeCell cell(color);
    right_edge_cells[i] = cell;
  }

  right_edge_.SetCells(right_edge_cells);

  std::array<CubeCell, kNumCells> top_edge_cells;
  for (int i = 0; i < kNumCells; ++i) {
    Color color;
    file.read(reinterpret_cast<char*>(&color), sizeof(color));
    CubeCell cell(color);
    top_edge_cells[i] = cell;
  }

  top_edge_.SetCells(top_edge_cells);

  std::array<CubeCell, kNumCells> bottom_edge_cells;
  for (int i = 0; i < kNumCells; ++i) {
    Color color;
    file.read(reinterpret_cast<char*>(&color), sizeof(color));
    CubeCell cell(color);
    bottom_edge_cells[i] = cell;
  }

  bottom_edge_.SetCells(bottom_edge_cells);

  file.close();
}

char FaceToChar(const Face& face) {
  switch (face) {
    case Face::kFront:return 'F';
    case Face::kBack:return 'B';
    case Face::kLeft:return 'L';
    case Face::kRight:return 'R';
    case Face::kTop:return 'U';
    case Face::kBottom:return 'D';
    default:return ' ';
  }
}

char DirectionToChar(const Direction& direction) {
  switch (direction) {
    case Direction::kClockwise:return ' ';
    case Direction::kCounterClockwise:return '\'';
    default:return ' ';
  }
}

std::ostream& operator<<(std::ostream& os, const Move& move) {
  os << FaceToChar(move.face_) << DirectionToChar(move.direction_);
  return os;
}

Move Move::GetInverse() const {
  switch (direction_) {
    case Direction::kClockwise:return {face_, Direction::kCounterClockwise};
    case Direction::kCounterClockwise:return {face_, Direction::kClockwise};
  }
}
} // cr