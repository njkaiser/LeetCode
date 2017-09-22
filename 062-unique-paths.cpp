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
#include <vector>

using namespace std;


class Solution {
public:
  int uniquePaths(int m, int n) {
    if(m == 1 || n == 1) { return 1; } // special case

    vector<int> last(n, 1);
    vector<int> curr(n, 1);
    for(int j = 1; j < m; ++j) {
      for(int i = 1; i < n; ++i) {
        curr[i] = curr[i-1] + last[i];
      }
      last = curr;
    }

    return curr.back();
  }
};


int main(int argc, char** argv)
{
  int m = 4,  n = 4;
  // int m = 1,  n = 10;
  // int m = 3,  n = 7;
  // int m = 23, n = 12;
  // int m = 8,  n = 6;

  Solution sol;
  cout << "m = " << m << ", n = " << n << ", sol = " << sol.uniquePaths(m, n) << endl;

  return 0;
}
