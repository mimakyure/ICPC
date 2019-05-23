#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Given: Lines of numbers starting with the count n of following numbers on the line, n < 3000
// Find:  Output 'Jolly' if difference between adjacent numbers takes on all values from 1 to n - 1, 'Not jolly' otherwise


bool testJolly(std::istringstream line) {

  // Count of numbers on the line
  int n;
  line >> n;

  // Track differences using vector
  std::vector<int> nums(n - 1, -1);

  int curr_num;
  line >> curr_num;

  int prev_num = curr_num;

  while (line >> curr_num) {

    int diff = std::abs(curr_num - prev_num);

    // Guard and don't track numbers not needed
    if (diff < 1 || diff > nums.size()) {
      return false;
    }
    nums.at(diff - 1) = 0;

    prev_num = curr_num;
  }

  return (std::find(nums.begin(), nums.end(), -1) == nums.end());
}


int solution() {

  std::string line;

  while (std::getline(std::cin, line)) {
    bool jolly = testJolly(std::istringstream(line));

    if (jolly) {
      std::cout << "Jolly" << std::endl;
    }
    else {
      std::cout << "Not jolly" << std::endl;
    }
  }

  return 0;
}
