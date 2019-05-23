#include <iostream>
#include <string>
#include <regex>

// Given: Lines of text
// Find:  Number of consecutive letter sequences on each line


int solution() {

  std::string line;
  std::regex const re("[a-zA-Z]+");

  while (std::getline(std::cin, line)) {

    std::cout << std::distance(
      std::sregex_iterator(line.begin(), line.end(), re),
      std::sregex_iterator()) << std::endl;
  }

  return 0;
}
