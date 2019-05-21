#include <iostream>
#include <string>
using namespace std;


int solution() {
  string from = R"(WERTYUIOP[]\SDFGHJKL;,'XCVBNM,./1234567890-= )";
  string to = R"(QWERTYUIOP[]ASDFGHJKLM;ZXCVBNM,.`1234567890- )";
  string input;

  while (getline(cin, input))
  {

    for (auto& c : input)
    {
      for (int i = 0; i < from.length(); i++)
      {
        if (from[i] == c)
        {
          cout << to[i];
          break;
        }
      }
    }
    cout << endl;
  }

  return 0;
}