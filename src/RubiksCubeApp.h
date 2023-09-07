#pragma once
#include "RubiksCube.h"

namespace cr {

class RubiksCubeApp {
 public:
  RubiksCubeApp() = default;
  ~RubiksCubeApp() = default;

  void Run();
 private:
  void ParseQuery(const std::string& query);
  static Move ParseMove(const std::string& move);
  static void PrintHelp();
  static std::vector<std::string> split(const std::string& s, char delimiter);
  RubiksCube cube_;
};

} // cr

