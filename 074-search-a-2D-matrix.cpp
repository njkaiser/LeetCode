// You are given an m x n integer matrix matrix with the following two
// properties:
//  - Each row is sorted in non-decreasing order.
//  - The first integer of each row is greater than the last integer of the
//    previous row.
//
// Given an integer target, return true if target is in matrix or false
// otherwise.
// 
// You must write a solution in O(log(m * n)) time complexity.
//
// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
//
// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
//
// Constraints:
//  1. m == matrix.length
//  2. n == matrix[i].length
//  3. 1 <= m, n <= 100
//  4. -104 <= matrix[i][j], target <= 104

#include <vector>
//#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (const auto& row : matrix) {
      if (row.front() > target || row.back() < target) {
        continue;
      }

      const auto it = find(row.cbegin(), row.cend(), target);
      return it != row.cend();
    }
    return false;
  }
};


int main(int argc, char** argv) {
  vector<vector<int>> input{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  const int target = 13;

  Solution sol;
  const bool answer = sol.searchMatrix(input, target);

  cout << "answer = " << answer << endl;
}
