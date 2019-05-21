#include <iostream>


int solution() {
  int num1, num2;
  while (std::cin >> num1 >> num2) {
    std::cin.ignore();
    int carries = 0;
    int carry = 0;

    int tmp1 = num1, tmp2 = num2;
    while (tmp1 > 0 || tmp2 > 0) {
      carry = (tmp1 % 10 + tmp2 % 10 + carry);
      if (carry > 9) {
        carries++;
      }
      carry = carry / 10;
      tmp1 /= 10;
      tmp2 /= 10;
    }

    if (num1 == 0 && num2 == 0) {
      break;
    }

    switch (carries) {
    case 0:
      std::cout << "No carry operation.";
      break;
    case 1:
      std::cout << carries << " carry operation.";
      break;
    default:
      std::cout << carries << " carry operations.";
    }
    std::cout << std::endl;
  }

  return 0;
}