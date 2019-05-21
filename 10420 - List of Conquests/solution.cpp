#include <iostream>
#include <map>
#include <sstream>


int solution() {
  int lines;
  std::cin >> lines;
  std::cin.ignore();


  std::map<std::string, int> count;

  while (lines--) {
    std::string line;
    std::getline(std::cin, line);

    std::string country;
    std::stringstream(line) >> country;

    count[country]++;
  }

  for (auto& key : count) {
    std::cout << key.first << " " << key.second << std::endl;
  }

  return 0;
}