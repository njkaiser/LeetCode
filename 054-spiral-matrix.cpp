// Given a matrix of m x n elements (m rows, n columns), return all elements of the
// matrix in spiral order.
//
// For example, Given the following matrix:
//
// [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ] You should return [1,2,3,6,9,8,7,4,5].


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.empty()) { return {}; }
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> output(m*n);
    vector<long unsigned int> limits {matrix[0].size(), matrix.size()-1};
    vector< pair<int, int> > delta { pair<int, int>(1, 0), pair<int, int>(0, 1), pair<int, int>(-1, 0), pair<int, int>(0, -1) };

    int count = 0;
    int idx = 0;
    int x = -1, y = 0;
    while(idx < m*n) {
      for(int i = 0; i < limits[count%2]; i++) {
        x += delta[count%4].first;
        y += delta[count%4].second;
        output[idx] = matrix[y][x];
        idx++;
      }
      limits[count%2]--;
      count++;
    }
    return output;
  }
};


int main(int argc, char** argv)
{
  vector<vector<int> > input { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  // vector<vector<int> > input;
  // vector<vector<int> > input { {2, 5, 8}, {4, 0, -1} };
  // vector<vector<int> > input { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };
  // vector<vector<int> > input { {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10} };

  Solution sol;
  vector<int> answer = sol.spiralOrder(input);

  cout << "ANSWER:" << endl;
  cout << "{ ";
  for(int i = 0; i < answer.size(); i++) {
    cout << answer[i] << ", ";
  }
  cout << "}" << endl;

  return 0;
}
