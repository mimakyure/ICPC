#include <iostream>
#include <string>

// Given: Text encoded by single arithmetic manipulation, addition of 7
// Find:  The decoded text

int solution() {

  std::string line;

  while (std::getline(std::cin, line)) {

    for (auto& ch : line) {
      int num = (int) ch - 7;

      std::cout << (char) num;
    }
    std::cout << std::endl;

  }

  return 0;
}