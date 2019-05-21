#include <iostream>
#include <string>
#include <algorithm>


// Change string S into string T by:
// Changing 0 to 1
// Convert ? to 0 or 1
// Swapping characters in S
int solution() {
  unsigned cases;
  std::cin >> cases;
  std::cin.ignore();

  for (unsigned c = 0; c < cases; ++c) {
    std::string S_str;
    std::string T_str;

    std::getline(std::cin, S_str);
    std::getline(std::cin, T_str);

    unsigned moves = 0;

    // Character counts
    int T1 = 0, T0 = 0, S1 = 0, S0 = 0, SQ = 0;

    // Determine swaps by analyzing S/T relationships
    int S1T0 = 0, SQT0 = 0, SQT1 = 0;

    for (std::string::size_type c = 0; c < S_str.length(); c++) {

      bool is_T0 = (T_str.at(c) == '0');
      bool is_T1 = (T_str.at(c) == '1');
      bool is_S0 = (S_str.at(c) == '0');
      bool is_S1 = (S_str.at(c) == '1');
      bool is_SQ = (S_str.at(c) == '?');

      T0 += is_T0;
      T1 += is_T1;
      S1 += is_S1;
      S0 += is_S0;
      SQ += is_SQ;

      S1T0 += is_S1 && is_T0;
      SQT0 += is_SQ && is_T0;
      SQT1 += is_SQ && is_T1;
    }

    std::cout << "Case " << c + 1 << ": ";

    // Check if conversion possible
    if (S1 > T1) {

      std::cout << -1 << std::endl;
      continue;
    }

    // Convert ? to 1
    int mv = std::min(SQ - std::max(T0 - S0, 0), T1 - S1);
    moves += mv;

    // Convert ? to 0
    moves += std::max(T0 - S0, 0);

    // Convert 0 to 1
    moves += T1 - S1 - mv;

    // Count swaps by determining number of S1/T0 pairs
    moves += S1T0 + std::min(SQT0, std::max(mv - SQT1, 0));

    std::cout << moves << std::endl;
  }

  return 0;
}
