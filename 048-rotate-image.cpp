// You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
// Follow up: Could you do this in-place?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    // int m = matrix.size();
    // int n = matrix[0].size();
    // vector<vector<int>> output(m, vector<int>(n));

    // for(int u = 0; u < m; ++u) {
    //   for(int v = 0; v < n; ++v) {
    //     // cout << "(u, v): " << u << ' ' << v << endl;
    //     output[u][v] = matrix[m-1-v][u];
    //   }
    // }
    // matrix = output;

    int a = 0, b = matrix.size()-1;
    while(a < b) {
      swap(matrix[a++], matrix[b--]);
    }

    for(int i = 0; i < matrix.size(); ++i) {
      for(int j = i; j < matrix.size(); ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};


int main(int argc, char** argv)
{
  int size = 10;
  int val = 0;
  vector<vector<int>> A(size, vector<int>(size));
  cout << "ORIGINAL//" << endl;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      A[i][j] = val++;
      cout << A[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "//END ORIGINAL" << endl;

  Solution sol;
  sol.rotate(A);

  cout << "ROTATED//" << endl;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      cout << A[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "//END ROTATED" << endl;


  return 0;
}
