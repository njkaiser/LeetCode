// Determine whether an integer is a palindrome. Do this without extra space.

// #include <vector>
// #include <unordered_map>
#include <iostream>
#include <cmath>
// #include <algorithm>
// #include <string>


using namespace std;


class Solution {
public:
  bool isPalindrome(int x) {
    if(x < 0) { return 0; }
    int a = 1;
    int b = static_cast<int>(log10(x))+1;
    // cout << "a & b: " << a << ", " << b << endl;
    while(a < b) {
      int lval = x / static_cast<int>(pow(10, b-1)) % 10;
      int rval = x % static_cast<int>(pow(10, a)) / static_cast<int>(pow(10, a-1));

      if(lval != rval) {
        // cout << "indices " << a << " and " << b << " are not the same:" << endl;
        // cout << "values are: " << rval << " and " << lval << endl;
        return 0;
      }

      // cout << "indices " << a << " and " << b << " match:" << endl;
      // cout << "both values are: " << rval << " and " << lval << endl;
      a++; b--;
    }

    return 1;
  }
};


int main(int argc, char** argv)
{
  int input = 123454321;
  // int input = -2147483648;
  // int input = 10;
  // int input = 5;

  Solution sol;
  bool answer = sol.isPalindrome(input);
  cout << "answer = " << answer << endl;

  return 0;
}
