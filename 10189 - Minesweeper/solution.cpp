#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution() {
  int rows, cols;
  int field = 1;

  while (cin >> rows >> cols)
  {
    cin.ignore();
    vector<vector<int> > counts(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i)
    {
      string input;
      if (getline(cin, input))
      {
        for (int j = 0; j < cols; ++j)
        {
          if (input[j] == '*') {
            counts[i][j] = 9;
            for (int n = max(0, i - 1); n < min(rows, i + 2); ++n)
            {
              for (int m = max(0, j - 1); m < min(cols, j + 2); ++m)
              {
                ++counts[n][m];
              }
            }
          }
        }
      }
    }

    if (rows > 0 and cols > 0)
    {
      if (field > 1)
      {
        cout << endl;
      }
      cout << "Field #" << field << ":" << endl;
    }

    for (int i = 0; i < counts.size(); ++i)
    {
      vector<int> row = counts[i];
      for (int j = 0; j < row.size(); ++j)
      {
        int count = row[j];
        if (count > 8)
        {
          cout << "*";
        }
        else
        {
          cout << count;
        }
      }

      cout << endl;
    }
    ++field;
  }

  return 0;
}

