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

    if(numRows <= 1) { return s; }

    // vector<string> v(numRows);
    // int dir = -1;
    // int i = 0;
    // int index = 0;
    char *idx = &s[0];

    // while(index < sz) {
    //   // v[i] += s[index];
    //   v[i] += *idx;
    //   // cout << "index, i, v[i], s[i]: " << index << ", " << i << ", " << v[i] << ", " << s[i] << endl;
    //   if(i % (numRows-1) == 0) { dir *= -1; } // switch directions when appropriate
    //   i += dir;
    //   index++;
    //   idx++;
    // }

    string output;//(sz);
    // for(int j = 0; j < numRows; ++j) {
    //   output += v[j];
    // }
    int sz = s.size();
    for(int i = 0; i < numRows; ++i) {
      int loop = i;
      for(int j = i; j < sz || j-2*loop > i; j += 2*numRows-2) {
        if(j-2*loop > i && i != 0 && i != numRows-1) {
          output += *(&s[0] + j - 2*(loop-i+1));
          cout << "*i: " << i << "\tj= " << j << "\tloop: " << loop << "\toutput: " << output << endl;
          loop++;
        }
        if(j < sz) {
          idx = &s[0] + j;
          output += *idx;
          cout << " i: " << i << "\tj= " << j << "\tloop: " << loop << "\toutput: " << output << endl;
        }
        else {
          // cout << "DONE-ish?" << endl;
        }
      }
    }
    return output;
  }
};


int main(int argc, char** argv)
{
  int rows = 3;
  string input = "PAYPALISHIRING";
  // string input = "ABCD";

  Solution sol;
  string answer = sol.convert(input, rows);
  cout << "answer = " << answer << endl;

  cout << "DONE" << endl;
  return 0;
}
