#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>


int solution() {
  
  std::string line;

  while (getline(std::cin, line)) {

    std::istringstream ss(line);
    std::string word;
    std::string::size_type begin = 0;

    // Read words in the line, reverse, and replace in place
    while (ss >> word) {

      begin = line.find(word, begin);

      std::reverse(word.begin(), word.end());

      line.replace(begin, word.length(), word);

      begin += word.length();
    }

    std::cout << line << std::endl;
  }

  return 0;
}

