#include <iostream>
#include <vector>
#include <algorithm>


int solution() {
  int cases;
  std::cin >> cases; 
  std::cin.ignore();

  while (cases--) {

    // read in bomb strength
    int strength; // 1 <= d <= 50
    std::cin >> strength; std::cin.ignore();

    int pops; // 1 <= n <= 20000
    std::cin >> pops; 
    std::cin.ignore();

    std::vector< std::vector<int> > kills(1025, std::vector<int>(1025));

    // read in location and size of all populations
    while (pops--) {
      int coord_x, coord_y; // 0 <= coord <= 1024
      std::cin >> coord_x >> coord_y;

      int size; // 1 <= i <= 255
      std::cin >> size; 
      std::cin.ignore();


      for (int x = std::max(0, coord_x - strength); x <= std::min(1024, coord_x + strength); x++) {
        for (int y = std::max(0, coord_y - strength); y <= std::min(1024, coord_y + strength); y++) {
          kills[x][y] += size;
        }
      }
    }

    int max_x, max_y, max_kills = 0;
    for (int x = 0; x < 1024; x++) {
      for (int y = 0; y < 1024; y++) {
        if (kills[x][y] > max_kills) {
          max_x = x;
          max_y = y;
          max_kills = kills[x][y];
        }
      }
    }
    std::cout << max_x << " " << max_y << " " << max_kills << std::endl;
  }


  return 0;
}

