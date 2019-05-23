#include <iostream>

// Given: Particle initial velocity and particle travel time
// Find:  The distance the particle travels in twice the given time

int solution() {

  int vel;
  int dt;

  while (std::cin >> vel >> dt) {

    std::cin.ignore();

    std::cout << vel * dt * 2 << std::endl;
      
  }

  return 0;
}