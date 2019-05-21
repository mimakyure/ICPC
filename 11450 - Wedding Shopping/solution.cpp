#include <iostream>
#include <vector>
#include <algorithm>


// Read in garment data
std::vector< std::vector<int> > getGarmentData(int c_types) {

  std::vector< std::vector<int> > gmts;

  // Get available models for each garment type
  while (c_types--) {

    int k_models;
    std::cin >> k_models;

    std::vector<int> mdls(k_models, 0);

    // Get price data for garment models
    // This puts it in reverse order but that doesn't matter
    while (k_models--) {
      std::cin >> mdls.at(k_models);
    }
    std::cin.ignore();

    gmts.push_back(mdls);
  }

  return gmts;
}

// Analyze garment data to find max purchase
int getMaxCost(int money, int c_types, std::vector< std::vector<int> > gmts) {

  // Track cost totals for garment combinations
  // Use -1 to identify 'no solution' result
  std::vector< std::vector<int> > cost(money + 1, std::vector<int>(c_types + 1, -1));

  // Check which garmets can be purchased at increasing budget values
  // Start from m = 0 to initialize totals
  for (std::vector<int>::size_type m = 0; m < cost.size(); m++) {

    // Set initial purchase total
    cost.at(m).at(0) = 0;

    for (std::vector<int>::size_type c = 0; c < gmts.size(); c++) {

      for (std::vector<int>::size_type k = 0; k < gmts.at(c).size(); k++) {

        // Only add items within current budget and with preeceding garments within budget
        int price = gmts.at(c).at(k);

        if (price <= m && cost.at(m - price).at(c) != -1) {
          cost.at(m).at(c + 1) = std::max(cost.at(m).at(c + 1), cost.at(m - price).at(c) + price);
        }
      }
    }
  }
  return cost.back().back();
}

// Maximize the amount of money used while buying one of each type of garment
// Return amount of money used or 'no solution'
int solution() {
  int cases;
  std::cin >> cases;
  std::cin.ignore();

  // Read in price data for all garment models available
  while (cases--) {
    int money;   // Available money, 1 to 200
    int c_types; // Number of garment types to buy, 1 to 20
    std::cin >> money >> c_types;
    std::cin.ignore();

    std::vector< std::vector<int> > gmts = getGarmentData(c_types);

    int cost = getMaxCost(money, c_types, gmts);


    if (cost == -1) {
      std::cout << "no solution" << std::endl;
    }
    else {
      std::cout << cost << std::endl;
    }

  }
  return 0;
}
