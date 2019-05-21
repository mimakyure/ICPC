#include <iostream>


int solution() {
  int cases;
  std::cin >> cases; 
  std::cin.ignore();

  while (cases--) {
    int sum, diff;

    std::cin >> sum >> diff; 
    std::cin.ignore();


    // calculate scores
    int test = (sum - diff) % 2;
    int score2 = 0;

    if (test == 0) {
      score2 = (sum - diff) / 2;
    }

    if (score2 >= 0 && test == 0) {
      int score1 = diff + score2;
      std::cout << score1 << " " << score2 << std::endl;
    }
    else {
      std::cout << "impossible" << std::endl;
    }

  }

  return 0;
}