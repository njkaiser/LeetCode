// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
// like this:
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
// (you may want to display this pattern in a fixed font for better legibility)
//
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
//
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Solution {
public:
  string convert(string s, int numRows) {

    if(numRows < 2) { return s; }

    vector<string> v(numRows);
    int dir = -1;
    int i = 0;
    int index = 0;

    while(index < s.size()) {
      v[i] += s[index];
      // cout << "index, i, v[i], s[i]: " << index << ", " << i << ", " << v[i] << ", " << s[i] << endl;
      if(i % (numRows-1) == 0) {
        dir *= -1;
      }
      i += dir;
      index++;
    }

    string output;
    for(int j = 0; j < numRows; ++j) {
      output += v[j];
    }

    // cout << "output: " << output << endl;
    return output;
  }
};


int main(int argc, char** argv)
{
  int rows = 3;
  string input = "PAYPALISHIRING";

  Solution sol;
  string answer = sol.convert(input, rows);
  cout << "answer = " << answer << endl;

  cout << "DONE" << endl;
  return 0;
}
