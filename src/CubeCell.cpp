#include <ostream>
#include <fstream>
#include "CubeCell.h"

cr::Color cr::CubeCell::GetColor() const {
  return color_;
}

void cr::CubeCell::SetColor(cr::Color color) {
  color_ = color;
}

bool cr::CubeCell::operator==(const cr::CubeCell& other) const {
  return color_ == other.color_;
}

bool cr::CubeCell::operator!=(const cr::CubeCell& other) const {
  return !operator==(other);
}

cr::Color cr::CharToColor(char c) {
  c = static_cast<char>(std::toupper(c));
  switch (c) {
    case 'W':return Color::kWhite;
    case 'Y':return Color::kYellow;
    case 'R':return Color::kRed;
    case 'O':return Color::kOrange;
    case 'B':return Color::kBlue;
    case 'G':return Color::kGreen;
    default:throw std::invalid_argument("Invalid color character");
  }
}

std::ostream& cr::operator<<(std::ostream& os, const cr::Color& color) {
  switch (color) {
    case Color::kWhite:os << "W";
      break;
    case Color::kYellow:os << "Y";
      break;
    case Color::kRed:os << "R";
      break;
    case Color::kOrange:os << "O";
      break;
    case Color::kBlue:os << "B";
      break;
    case Color::kGreen:os << "G";
      break;
  }
  return os;
}

