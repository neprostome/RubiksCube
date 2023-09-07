#include <sstream>
#include "RubiksCubeApp.h"

namespace cr {
void RubiksCubeApp::Run() {
  cube_.Print();
  std::string query;
  while (true) {
    std::cout << ">> ";
    std::getline(std::cin, query);
    if (query == "EXIT") {
      break;
    }
    try {
      ParseQuery(query);
    } catch (const std::invalid_argument& e) {
      std::cout << e.what() << std::endl;
    }
  }
}

void RubiksCubeApp::ParseQuery(const std::string& query) {
  auto tokens = split(query, ' ');
  if (tokens[0] == "ROTATE") {
    auto move = ParseMove(tokens[1]);
    cube_.Rotate(move.face_, move.direction_);
  } else if (tokens[0] == "RANDOMIZE") {
    cube_.Randomize();
  } else if (tokens[0] == "PRINT") {
    cube_.Print();
  } else if (tokens[0] == "HISTORY") {
    cube_.PrintMovesHistory();
  } else if (tokens[0] == "SOLVE") {
    cube_.PrintSolve();
  } else if (tokens[0] == "HELP") {
    PrintHelp();
  } else if (tokens[0] == "ANEW") {
    cube_.Anew();
  } else if (tokens[0] == "SAVE") {
    cube_.Save(tokens[1]);
  } else if (tokens[0] == "LOAD") {
    cube_.Load(tokens[1]);
  } else {
    throw std::invalid_argument("Unknown command. Type HELP for help.");
  }
}

std::vector<std::string> RubiksCubeApp::split(const std::string& s,
                                              char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream token_stream(s);
  while (std::getline(token_stream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

Move RubiksCubeApp::ParseMove(const std::string& move) {
  if (move.empty() || move.size() > 2) {
    throw std::invalid_argument("Invalid move.");
  }
  Face face;
  Direction direction;
  switch (move[0]) {
    case 'F':face = Face::kFront;
      break;
    case 'B':face = Face::kBack;
      break;
    case 'L':face = Face::kLeft;
      break;
    case 'R':face = Face::kRight;
      break;
    case 'U':face = Face::kTop;
      break;
    case 'D':face = Face::kBottom;
      break;
    default:throw std::invalid_argument("Invalid move");
  }

  if (move.size() == 1) {
    direction = Direction::kClockwise;
  } else if (move[1] == '\'') {
    direction = Direction::kCounterClockwise;
  } else {
    throw std::invalid_argument("Invalid move");
  }

  return {face, direction};
}

void RubiksCubeApp::PrintHelp() {
  std::cout << "Valid queries:" << std::endl;
  std::cout << "\tROTATE <FACE><DIRECTION>" << std::endl;
  std::cout << "\tRANDOMIZE" << std::endl;
  std::cout << "\tPRINT" << std::endl;
  std::cout << "\tHISTORY" << std::endl;
  std::cout << "\tSOLVE" << std::endl;
  std::cout << "\tHELP" << std::endl;
}
} // cr