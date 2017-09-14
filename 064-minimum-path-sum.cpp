// Given a m x n grid filled with non-negative numbers, find a path from top left
// to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


class Solution {
public:
  int minPathSum(vector< vector<int> >& grid) {
    int ymax = grid.size()-1;
    int xmax = grid[0].size()-1;
    long rval, dval;

    for(int y = ymax; y >= 0; y--) {
      for(int x = xmax; x >= 0; x--) {
        if(x < xmax && y < ymax) { grid[y][x] += min(grid[y][x+1], grid[y+1][x]); }
        if(x < xmax && y == ymax) { grid[y][x] += grid[y][x+1]; }
        if(x == xmax && y < ymax) { grid[y][x] += grid[y+1][x]; }
      }
    }
    return grid[0][0];
  }
};


int main(int argc, char** argv)
{
  vector<vector<int> > grid { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

  cout << "input:" << endl;
  for(int y = 0; y < grid.size(); y++) {
    for(int x = 0; x < grid[0].size(); x++) {
      cout << grid[y][x] << ", ";
    }
    cout << endl;
  }

  Solution sol;
  int ans = sol.minPathSum(grid);

  cout << "output:" << endl;
  for(int y = 0; y < grid.size(); y++) {
    for(int x = 0; x < grid[0].size(); x++) {
      cout << grid[y][x] << ", ";
    }
    cout << endl;
  }

  cout << "min path sum = " << ans << endl;

  return 0;
}
