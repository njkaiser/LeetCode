// A robot is located at the top-left corner of an m x n grid (marked 'Start' in the
// diagram below).
//
// The robot can only move either down or right at any point in time. The robot is
// trying to reach the bottom-right corner of the grid (marked 'Finish' in the
// diagram below).
//
// How many possible unique paths are there?
//
// Note: m and n will be at most 100.


#include <iostream>

using namespace std;


class Solution {
public:
  int uniquePaths(int m, int n) {
    // base cases
    if((m == 0 && n == 1) || (m == 1 && n == 0)) { return 1; }
    if((m == 1 || n == 1)) { return 1; } // just in case

    // check memoized values
    // IS THIS POSSIBLE? HOW TO MEMOIZE BASED ON m, n PAIR OF VALUES?

    // calculate output
    int output = 0;
    if(m > 0) { output += uniquePaths(m-1, n); }
    if(n > 0) { output += uniquePaths(m, n-1); }
    cout << "(" << m << ", " << n << ") output: " << output << endl;
    return output;
  }
};


int main(int argc, char** argv)
{
  int m1 = 3, n1 = 7;
  int m2 = 1, n2 = 2;
  int m3 = 1, n3 = 10;
  int m3 = 23, n3 = 12;

  Solution sol;
  cout << "m = " << m1 << ", n = " << n1 << ", sol = " << sol.uniquePaths(m1, n1) << endl;
  cout << "m = " << m2 << ", n = " << n2 << ", sol = " << sol.uniquePaths(m2, n2) << endl;
  cout << "m = " << m3 << ", n = " << n3 << ", sol = " << sol.uniquePaths(m3, n3) << endl;
  cout << "m = " << m4 << ", n = " << n4 << ", sol = " << sol.uniquePaths(m4, n4) << endl;

  return 0;
}
