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
    vector<int> limits {top, left, bot, right}
    vector< pair<int, int> > delta { pair<int, int>(1, 0), pair<int, int>(0, 1), pair<int, int>(-1, 0), pair<int, int>(0, -1) };

    vector<int> output((bot+1)*(right+1));
    // cout << "output.size(): " << output.size() << endl;

    // cout << "[BEFORE] top, bot, left, right: " << top << bot << left << right << endl;

    int count = 0;
    int idx = 0;
    int x = 0, y = 0;
    while(idx < output.size()) {
      for(int i = limits[idx%2]; i < limits[idx%2+2]; i++) {
        cout << "x, y: " << x << ", " << y << endl;
        x += delta[idx%4].first;
        y += delta[idx%4].second;
        idx++;
      }
      count++;
    }




    // while(idx < output.size()) {
    //   int old = idx;
    //
    //   for(int i = left; i <= right; i++) {
    //     cout << "left to right" << endl;
    //     output[idx++] = matrix[top][i];
    //     // cout << output[idx-1] << endl;
    //   }
    //   top++;
    //   cout << "top, bot, left, right: " << top << bot << left << right << endl;
    //
    //   for(int i = top; i <= bot; i++) {
    //     cout << "top to bot" << endl;
    //     output[idx++] = matrix[i][right];
    //     // cout << output[idx-1] << endl;
    //   }
    //   right--;
    //   cout << "top, bot, left, right: " << top << bot << left << right << endl;
    //
    //   for(int i = right; i >= left; i--) {
    //     cout << "left to right" << endl;
    //     output[idx++] = matrix[bot][i];
    //     // cout << output[idx-1] << endl;
    //   }
    //   bot--;
    //   cout << "top, bot, left, right: " << top << bot << left << right << endl;
    //
    //   for(int i = bot; i >= top; i--) {
    //     cout << "bot to top" << endl;
    //     output[idx++] = matrix[i][left];
    //     // cout << output[idx-1] << endl;
    //   }
    //   left++;
    //   cout << "top, bot, left, right: " << top << bot << left << right << endl;
    //
    //   if(idx == old) { break; } // done
    //
    // }

    return output;
  }
};


int main(int argc, char** argv)
{
  // vector<vector<int> > input { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  // vector<vector<int> > input;
  // vector<vector<int> > input { {6, 9, 7} };
  // vector<vector<int> > input { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };
  // vector<vector<int> > input { {2, 5, 8}, {4, 0, -1} };
  vector<vector<int> > input { {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10} };

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
