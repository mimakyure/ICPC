#include <iostream>
#include <string>


int solution() {

  while (true) {
    int height;  // well height
    std::cin >> height;
    if (height == 0) {
      break;
    }

    float climb; // day climb distance
    int slide;   // night slide distance
    int fatigue; // fatigue factor
    std::cin >> climb >> slide >> fatigue; 
    std::cin.ignore();

    int day = 0; // current day
    float pos = 0; // snail position
    float loss = climb * fatigue / 100;

    while (true) {
      day++;
      pos += climb;        // move up
      if (pos > height) {  // exited the well
        break;
      }

      pos -= slide;     // slide down
      if (pos < 0) {    // failed the climb
        break;
      }

      climb -= loss;
      if (climb < 0) {
        climb = 0;
      }
    }
    std::string res = (pos > 0) ? "success" : "failure";
    std::cout << res << " on day " << day << std::endl;
  }

  return 0;
}