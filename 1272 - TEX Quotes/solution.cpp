#include <iostream>
#include <string>


// Given: Text containing sections delimited by quotes
// Find:  Text replacing opening double quotes with `` and closing double quotes with ''


int solution() {

  std::string line;
  bool opening = true;

  while (std::getline(std::cin, line)) {

    for (auto& ch : line) {
      
      if (ch == '"') {

        if (opening) {
          std::cout << "``";
          opening = false;
        }
        else {
          std::cout << "''";
          opening = true;
        }
      }
      else {
        std::cout << ch;
      }

    }
    std::cout << std::endl;
  }
  
  return 0;
}