#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


// Given:  Number of brown, green, clear bottles in three bins
// Find:   Minimum number of bottles moved to collect same color bottles in separate bins

int solution() {

  std::string line;

  // Read inputs until none provided
  while (std::getline(std::cin, line)) {

    std::istringstream ss(line);
    std::vector< std::vector<int> > bins(3, std::vector<int>(3, 0));

    // Input formatted as B1 G1 C1 B2 G2 C2 B3 G3 C3
    int B1, G1, C1, B2, G2, C2, B3, G3, C3;
    ss >> B1 >> G1 >> C1 >> B2 >> G2 >> C2 >> B3 >> G3 >> C3;

    // Add up all possible movement totals
    // Ordered alphabetically by strings, this tiebreaks for equal sums
    std::vector<int> moves(6, 0);
    moves.at(0) = B2 + B3 + C1 + C3 + G1 + G2; // BCG
    moves.at(1) = B2 + B3 + G1 + G3 + C1 + C2; // BGC
    moves.at(2) = C2 + C3 + B1 + B3 + G1 + G2; // CBG
    moves.at(3) = C2 + C3 + G1 + G3 + B1 + B2; // CGB
    moves.at(4) = G2 + G3 + B1 + B3 + C1 + C2; // GBC
    moves.at(5) = G2 + G3 + C1 + C3 + B1 + B2; // GCB

    auto small = std::min_element(moves.begin(), moves.end());
    std::vector<int>::size_type idx = std::distance(moves.begin(), small);

    std::vector<std::string> color_string{ "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

    std::cout << color_string.at(idx) << " " << *small << std::endl;

  }

  return 0;
}

