#include <iostream>
#include <string>

int solution() {
  int num_case;

  std::cin >> num_case;


  for (int i = 0; i < num_case; i++) {
    int salary1;
    int salary2;
    int salary3;
    int keep_salary;

    std::cin >> salary1 >> salary2 >> salary3;

    if (salary1 > salary2) {
      if (salary2 > salary3) {
        keep_salary = salary2;
      }
      else if (salary3 > salary1) {
        keep_salary = salary1;
      }
      else {
        keep_salary = salary3;
      }
    }
    else {
      if (salary2 < salary3) {
        keep_salary = salary2;
      }
      else if (salary3 < salary1) {
        keep_salary = salary1;
      }
      else {
        keep_salary = salary3;
      }
    }

    std::cout << "Case " << i + 1 << ": " << keep_salary << std::endl;
  }
  std::cout << std::endl;

  return 0;
}