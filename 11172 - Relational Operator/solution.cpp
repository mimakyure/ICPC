#include <iostream>

// Given: Two numbers A, B where |A| and |B| < 1,000,000,001
// Find:  Output relation between A and B, < > or =

int solution() {

  int cases;
  std::cin >> cases;
  std::cin.ignore();

  while (cases--) {
    
    int num1;
    int num2;

    std::cin >> num1 >> num2;
    std::cin.ignore();

    if (num1 > num2) {
      std::cout << ">" << std::endl;
    }
    else if (num1 < num2) {
      std::cout << "<" << std::endl;
    }
    else {
      std::cout << "=" << std::endl;
    }
  
  }


  return 0;
}
