#include <iostream>
#include <vector>
#include <algorithm>


// Find the 1500th number whose only prime factors are 2, 3, and 5
// Progressively calculate each number until 1500 has been found
int solution() {
  int count = 1;
  int target = 1500;
  std::vector<long> ugs = { 1 };

  long idx2 = 0;
  long idx3 = 0;
  long idx5 = 0;

  while (count < target) {
    long next2 = ugs[idx2] * 2;
    long next3 = ugs[idx3] * 3;
    long next5 = ugs[idx5] * 5;

    long next_ug = next2;
    if (next2 > next3) {
      if (next3 > next5) {
        next_ug = next5;
        idx5++;
      }
      else {
        next_ug = next3;
        idx3++;
      }
    }
    else if (next2 > next5) {
      next_ug = next5;
      idx5++;
    }
    else {
      next_ug = next2;
      idx2++;
    }

    if (next_ug > ugs.back()) {
      ugs.push_back(next_ug);

      count++;
    }
  }
  std::cout << "The " << target << "'th ugly number is " << ugs.back() << "." << std::endl;

}