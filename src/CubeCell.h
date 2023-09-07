#pragma once
#include <iostream>
#include <filesystem>

namespace cr {

enum class Color {
  kWhite,
  kYellow,
  kRed,
  kOrange,
  kBlue,
  kGreen
};

Color CharToColor(char c);
std::ostream& operator<<(std::ostream& os, const Color& color);

class CubeCell {
 public:
  CubeCell() = default;
  explicit CubeCell(Color color) : color_(color) {}
  ~CubeCell() = default;

  [[nodiscard]] Color GetColor() const;
  void SetColor(Color color);

  bool operator==(const CubeCell& other) const;
  bool operator!=(const CubeCell& other) const;
 private:
  Color color_ = Color::kWhite;
};

}

