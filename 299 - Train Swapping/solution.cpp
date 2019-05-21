#include <iostream>
#include <vector>
#include <algorithm>

int solution()
{
  int cases;
  std::cin >> cases;
  std::cin.ignore();


  // Read in cases
  while (cases--) {
    int length;
    std::vector<int> order;
    int total_swaps = 0;
    int tmp_swaps = 0;

    std::cin >> length;
    std::cin.ignore();

    // Read in carriage order
    while (length > 0) {
      int carriage;
      std::cin >> carriage;
      std::cin.ignore();

      order.push_back(carriage);

      // Analyze carriages only if there's more than 0
      tmp_swaps = 1;
      length--;
    }

    // Analyze swaps
    while (tmp_swaps > 0) {
      tmp_swaps = 0;

      std::vector<int>::iterator it = order.begin();
      for (std::advance(it, 1); it != order.end(); it++) {
        if (*it < *(it - 1)) {
          iter_swap(it, it - 1);
          tmp_swaps++;
        }
      }

      total_swaps += tmp_swaps;
    }

    std::cout << "Optimal train swapping takes " << total_swaps << " swaps." << std::endl;
  }

  return 0;

}