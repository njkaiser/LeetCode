// Given a m x n grid filled with non-negative numbers, find a path from top left
// to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>
#include <numeric> // accumulate()
#include <limits.h>

using namespace std;


class Solution {
public:
  int minPathSum(vector< vector<int> >& grid) {
    int ymax = grid.size();
    int xmax = grid[0].size();
    if(ymax == 1) { return accumulate(grid[0].begin(), grid[0].end(), 0); }

    vector<int> curr_row(xmax);
    vector<int> last_row(grid[0]);
    for(int x = 1; x < xmax; ++x) { last_row[x] += last_row[x-1]; }
    for(int y = 1; y < ymax; y++) {
      curr_row[0] = grid[y][0] + last_row[0];
      for(int x = 1; x < xmax; x++) {
        curr_row[x] = grid[y][x] + min(curr_row[x-1], last_row[x]);
      }
      last_row = curr_row;
    }

    return curr_row.back();
  }
};


int main(int argc, char** argv)
{
  // vector<vector<int> > grid { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  // vector<vector<int> > grid { {1} };
  // vector<vector<int> > grid { };
  // vector<vector<int> > grid { {9, 1, 4, 8} };
  vector<vector<int> > grid { {9}, {1}, {4}, {8} };

  cout << "input:" << endl;
  for(int y = 0; y < grid.size(); y++) {
    for(int x = 0; x < grid[0].size(); x++) {
      cout << grid[y][x] << ", ";
    }
    cout << endl;
  }

  Solution sol;
  int ans = sol.minPathSum(grid);

  cout << "min path sum = " << ans << endl;

  return 0;
}
