#include <iostream>


unsigned long reverse(unsigned long num) {
  unsigned long rev = 0;

  while (num > 0) {
    rev = rev * 10 + num % 10;
    num /= 10;
  }

  return rev;
}

int solution() {
  int cases;
  std::cin >> cases;
  std::cin.ignore();

  while (cases > 0) {
    int adds = 0;
    unsigned long sum;
    unsigned long num;

    std::cin >> num;
    std::cin.ignore();

    // All palindromes computable  in < 1000
    for (int i = 0; i < 1000; i++) {
      unsigned long rev;
      unsigned long rev_sum;

      rev = reverse(num);
      sum = num + rev;
      adds++;

      rev_sum = reverse(sum);

      // Palindrome
      if (rev_sum == sum) {
        break;
      }

      num = sum;
    }

    std::cout << adds << " " << sum << std::endl;
    cases--;
  }



  return 0;
}