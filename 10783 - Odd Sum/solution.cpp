#include <iostream>


int solution() {
  int cases;
  std::cin >> cases; 
  std::cin.ignore();

  for (int c = 1; c <= cases; c++) {
    int num1, num2;
    std::cin >> num1 >> num2; 
    std::cin.ignore();

    int sum = 0;
    for (int num = num1; num <= num2; num++) {
      if (num % 2 > 0) {
        sum += num;
      }
    }
    std::cout << "Case " << c << ": " << sum << std::endl;
  }

  return 0;
}