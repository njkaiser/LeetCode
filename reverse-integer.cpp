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

using namespace std;


class Solution {
public:
  int reverse(int x) {

    if(abs(x) < 10) { return x; }

    int len = log10(abs(x)) + 1;
    cout << len << endl;

    long output = 0;
    for(int i = 1; i <= len; ++i) {
      output += (x % 10) * (long)pow(10, len-i);
      // cout << "output at iteration " << i << ": " << output << endl;
      x /= 10;
    }
    output = (output > 2147483647) ? 0 : output;
    output = (output < -2147483648) ? 0 : output;
    return (int)output;
  }
};


int main(int argc, char** argv)
{
  int x = 1534236469;

  Solution sol;
  int answer = sol.reverse(x);

  cout << "answer = " << answer << endl;
}
