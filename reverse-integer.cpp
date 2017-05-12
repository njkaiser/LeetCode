// Reverse digits of an integer.
//
// Example1: x = 123, return 321
// Example2: x = -123, return -321
//
// Note:
// The input is assumed to be a 32-bit signed integer. Your function
// should return 0 when the reversed integer overflows.

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;


class Solution {
public:
  int reverse(int x) {
    long output = 0;
    while(x) {
      output = output*10 + x%10;
      // cout << "output = " << output << endl;
      x /= 10;
    }
    return (output > INT_MAX || output < INT_MIN) ? 0 : output;
  }
};


int main(int argc, char** argv)
{
  int x = -321;

  Solution sol;
  int answer = sol.reverse(x);

  cout << "answer = " << answer << endl;
}
