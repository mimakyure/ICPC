#include <iostream>
#include <string>
using namespace std;

int solution() {
  int inputs;
  cin >> inputs;
  cin.ignore();

  while (inputs--)
  {
    string results;
    getline(cin, results);
    int score = 0;
    int total = 0;
    for (auto& ch : results)
    {
      if (ch == 'O')
      {
        score += 1;
      }
      else
      {
        score = 0;
      }
      total += score;
    }
    cout << total << endl;
  }


}
