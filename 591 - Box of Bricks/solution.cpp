#include <iostream>
#include <vector>
#include <algorithm>

int solution() {
  int tot_stacks;
  int n_set = 0;

  std::cin >> tot_stacks;


  // Process sets until termination value of zero is found
  while (tot_stacks > 0) {
    n_set++;

    // Read in initial stack heights
    std::vector<int> h(tot_stacks);
    int tot_blocks = 0;

    for (auto& h_n : h) {
      std::cin >> h_n;
      tot_blocks += h_n;
    }

    // Determine target stack height
    int avg = tot_blocks / tot_stacks;

    // Count the total number of bricks in stacks over the target height
    int n_moved = 0;
    for (auto& h_n : h) {
      if (h_n > avg) {
        n_moved += h_n - avg;
      }
    }

    std::cout << "Set #" << n_set << std::endl;
    std::cout << "The minimum number of moves is " << n_moved << "." << std::endl << std::endl;


    std::cin >> tot_stacks;
  }


  return 0;
}