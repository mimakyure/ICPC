#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> add(std::vector<int> num1, std::vector<int> num2) {
  std::vector<int> sum;
  int carry = 0;

  int sz = std::max(num1.size(), num2.size());
  num1.resize(sz); num2.resize(sz);
  for (int i = 0; i < sz; i++) {
    int temp = num1[i] + num2[i] + carry;
    sum.push_back(temp % 10);
    carry = temp / 10;
  }

  if (carry > 0) {
    sum.push_back(carry);
  }

  return sum;
}


std::vector<int> multiply(int num1, int num2) {
  std::vector<int> prod{ 0 };
  int pos = 0;

  while (num2 > 0) {
    int carry = 0;
    int temp = num1;
    int d = num2 % 10;

    std::vector<int> temp_prod(pos, 0);

    while (temp > 0) {
      int val = (temp % 10) * d + carry;
      temp /= 10;
      temp_prod.push_back(val % 10); // numbers stored in reverse
      carry = val / 10;
    }
    if (carry > 0) {
      temp_prod.push_back(carry);
    }
    prod = add(prod, temp_prod);

    pos++;
    num2 /= 10;
  }

  return prod;
}


int solution() {
  int cases;
  std::cin >> cases; 
  std::cin.ignore();

  // read each test case	
  while (cases--) {
    int farmers;
    std::cin >> farmers; 
    std::cin.ignore();
    std::vector<int> burden{ 0 };

    // analyze farmers
    while (farmers--) {
      int size, animals, enviro;
      std::cin >> size >> animals >> enviro; 
      std::cin.ignore();

      burden = add(burden, multiply(size, enviro)); // size/animals * enviro * animals
    }

    // print results
    std::vector<int>::reverse_iterator rit = burden.rbegin();
    while (rit != burden.rend()) {
      std::cout << *rit;
      rit++;
    }
    std::cout << std::endl;
  }

  return 0;
}