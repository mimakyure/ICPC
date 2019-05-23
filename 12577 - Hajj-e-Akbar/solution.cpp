#include <iostream>
#include <string>

// Given: Lines of text containing either Hajj or Umrah terminating with line containing single *
// Find:  Output 'Case #: ' with # replaced by sequential number for each case followed by 
//        either Hajj-e-Akbar for matching Hajj or Hajj-e-Asghar for matching Umrah

int solution() {

  std::string text;
  int num = 1;

  while (std::cin >> text) {

    if (text == "*") {
      break;
    }

    std::cout << "Case " << num << ": ";

    if (text == "Hajj") {
      std::cout << "Hajj-e-Akbar" << std::endl;
    }
    else if (text == "Umrah") {
      std::cout << "Hajj-e-Asghar" << std::endl;
    }

    ++num;
  }
  
  return 0;
}