// Given a triangle, find the minimum path sum from top to bottom. Each step you
// may move to adjacent numbers on the row below.
//
// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note: Bonus point if you are able to do this using only O(n) extra space, where
// n is the total number of rows in the triangle.

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  int minimumTotal(vector< vector<int> >& triangle) {

    if(triangle.empty() || triangle[0].empty()) return 0;
    vector<int> curr_row(triangle.back());

    for(int i = triangle.size()-2; i >= 0; --i) {
      for(int j = 0; j <= i; ++j) {
        curr_row[j] = triangle[i][j] + min(curr_row[j], curr_row[j+1]);
      }
    }
    return curr_row[0];
  }
};


int main(int argc, char** argv)
{
  // set up input
  vector< vector<int> > triangle(4);
  triangle[0] = {2};
  triangle[1] = {3, 4};
  triangle[2] = {6, 5, 7};
  triangle[3] = {4, 1, 8, 3};
  // vector< vector<int> > triangle(1);
  // triangle[0] = {-10};
  // vector< vector<int> > triangle(3);
  // triangle[0] = {-1};
  // triangle[1] = {2, 3};
  // triangle[2] = {1, -1, -3};

  // run algorithm
  Solution sol;
  int ans = sol.minimumTotal(triangle);
  cout << "answer: " << ans << endl;

  return 0;
}
