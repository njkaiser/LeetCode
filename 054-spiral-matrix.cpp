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
    int top = 0;
    int bot = matrix.size()-1;
    if(bot == -1) { return {}; }
    if(bot == 0) { return matrix[0]; }
    int left = 0;
    int right = matrix[0].size()-1;
    // if(right == 0) { return matrix[0]; }
    vector<int> limits {left, top, right, bot};
    vector< pair<int, int> > delta { pair<int, int>(1, 0), pair<int, int>(0, 1), pair<int, int>(-1, 0), pair<int, int>(0, -1) };

    vector<int> output((bot+1)*(right+1));
    // cout << "output.size(): " << output.size() << endl;

    cout << "top, bot, left, right: " << top << ", " << bot << ", " << left << ", " << right << endl;

    int count = 0;
    int idx = 0;
    int x = 0, y = 0;
    while(idx < output.size()-1) {
      cout << "[" << idx << "] going from " << limits[count%4] << " to " << limits[(count+2)%4] << endl;
      for(int i = limits[count%4]; i <= limits[(count+2)%4]; i++) {
        cout << "i: " << i << endl;
        cout << "[" << idx << "] \tx, y: " << x << ", " << y << endl;
        x += delta[count%4].first;
        y += delta[count%4].second;
        idx++;
      }
      // cout << "[" << idx << "] \tx, y: " << x << ", " << y << endl;
      count++;
      if(count%2) { limits[count%4] += delta[count%4].second; }
      else        { limits[count%4] += delta[count%4].first; }
      if(count > idx) { break; } // SAFETY
    }
    return output;
  }
};


int main(int argc, char** argv)
{
  vector<vector<int> > input { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  // vector<vector<int> > input;
  // vector<vector<int> > input { {6, 9, 7} };
  // vector<vector<int> > input { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };
  // vector<vector<int> > input { {2, 5, 8}, {4, 0, -1} };
  // vector<vector<int> > input { {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10} };

  Solution sol;
  vector<int> answer = sol.spiralOrder(input);

  cout << "ANSWER:" << endl;
  cout << "{ ";
  for(int i = 0; i < answer.size(); i++) {
    cout << answer[i] << ", ";
  }
  cout << "}" << endl;
  // cout << "answer.size(): " << answer.size() << endl;

  return 0;
}
