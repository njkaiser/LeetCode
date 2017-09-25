// Write an efficient algorithm that searches for a value in an m x n matrix. This
// matrix has the following properties:
//
// Integers in each row are sorted from left to right. The first integer of each
// row is greater than the last integer of the previous row. For example,
//
// Consider the following matrix:
//
// [ [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50] ]
//
// Given target = 3, return true.

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int nrows = matrix.size()-1;
    if(nrows == -1) { return false; } // no data = no match possible
    int ncols = matrix[0].size()-1;
    if(ncols == -1) { return false; } // no data = no match possible
    if(target < matrix[0][0] || target > matrix[nrows][ncols]) { return false; }

    int min = 0, max = nrows+1;
    int idx = (min + max)/2;
    int last = idx+1;
    while(1) {
      cout << "row [min, max]: " << idx << " [" << min << ", " << max << "]" << endl;
      if(target < matrix[idx][0]) { max = idx; }
      else if(target > matrix[idx][ncols]) { min = idx; }
      else if(last == idx) { return false; }
      else { break; }
      cout << "last, idx: " << last << ", " << idx << endl;
      last = idx;
      idx = (min+max)/2;
    }
    int row = idx;
    cout << "final row: " << row << endl;

    min = 0; max = ncols+1;
    idx = (min + max)/2;
    last = idx+1;
    while(1) {
      cout << "col [min, max]: " << idx << " [" << min << ", " << max << "]" << endl;
      if(target == matrix[row][idx]) { return true; }
      else if(last == idx) { return false; }
      else if(target < matrix[row][idx]) { max = idx; }
      else if(target > matrix[row][idx]) { min = idx; }
      else { break; }
      last = idx;
      idx = (min+max)/2;
    }
    cout << "final col: " << idx << endl;
    return false;
  }
};


int main(int argc, char** argv)
{
  int target = 2;
  // vector< vector<int> > matrix {  {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} };
  vector< vector<int> > matrix {  {1}, {3} };

  Solution sol;
  int answer = sol.searchMatrix(matrix, target);
  cout << "answer: " << answer << endl;

  return 0;
}
