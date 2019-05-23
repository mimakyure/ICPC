#include <iostream>
#include <algorithm>


// Given: Algorithm - f(n) { Print n, n == 1: STOP, n == odd: n = 3n+1, else n = n/2, f(n) }
//        Two input numbers
// Find:  Output numbers in input order and for all numbers between and including the inputs,
//        output the count of the maximum algorithm outputs



int calc(int n) {
  
  if (n % 2 == 1) {
    n = 3 * n + 1;
  }
  else {
    n = n / 2;
  }

  return n;
}

int solution() {

  int i;
  int j;

  while (std::cin >> i >> j) {

    int start = std::min(i, j);
    int end = std::max(i, j);

    int max_count = 0;

    for (int n = start; n <= end; ++n) {

      int count = 1;
      int curr = n;

      while (curr != 1) {
        curr = calc(curr);
        count++;
      }

      max_count = std::max(max_count, count);
    }

    std::cout << i << " " << j << " " << max_count << std::endl;
  }
  
  return 0;
}
