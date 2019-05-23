#include <iostream>
#include <cstdlib>

// Given: Size of own and opponents armies, own <= opponent, size <= 2^32
// Find:  Difference between army sizes

int solution() {

  // Army sizes, always opponent >= own
  long size1;
  long size2;

  while (std::cin >> size1 >> size2) {

    std::cout << std::abs(size1 - size2) << std::endl;
  }

  return 0;
}
