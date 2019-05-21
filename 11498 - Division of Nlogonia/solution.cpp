#include <iostream>
#include <string>


int solution() {

  while (true) {
    int queries = 0;
    std::cin >> queries; 
    std::cin.ignore();

    if (queries == 0) {
      break;
    }

    int div_x, div_y;
    std::cin >> div_x >> div_y; 
    std::cin.ignore();

    while (queries--) {
      int house_x, house_y;
      std::string output;
      std::cin >> house_x >> house_y; 
      std::cin.ignore();


      if (house_x == div_x || house_y == div_y) {
        output = "divisa";
      }
      else {
        output = (house_y > div_y) ? "N" : "S";
        output += (house_x > div_x) ? "E" : "O";
      }
      std::cout << output << std::endl;
    }
  }

  return 0;
}