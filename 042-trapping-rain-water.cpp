// Given n non-negative integers representing an elevation map where the width of
// each bar is 1, compute how much water it is able to trap after raining.
//
// For example,  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

#include <iostream>
#include <vector>
#include <algorithm> // std::min()
#include <numeric> // std::accumulate()

using namespace std;


class Solution {
public:
  int trap(vector<int>& height) {
    int size = height.size()-1;
    if(size <= 0) { return 0; }
    int i = 0, j = size;
    int ii = i, jj = j;

    int water = 0;
    while(1) {
      // cout << "i, ii, j, jj: " << i << ", " << ii << ", " << j << ", " << jj << endl;
      if((height[ii] >= height[i]) && (ii <= size)) {
        // cout << "i index " << ii << " > " << i << " [" << height[ii] << ", " << height[ii] << "]" << endl;
        // cout << "got here 1" << endl;
        if((ii - i) > 1) {
          water += min(height[i], height[ii]) * (ii-i-1) - accumulate(height.begin()+i+1, height.begin()+ii, 0);
          // cout << "water added: " << min(height[i], height[ii]) * (ii-i-1) << " - " << accumulate(height.begin()+i+1, height.begin()+ii, 0) << endl;
          // cout << "got here 2" << endl;
        }
        i = ii;
      }
      ++ii;
      if(ii > size) { break; }
    }

    while(1) {
      if(jj < i) { break; }
      if((height[jj] >= height[j]) && (jj >= 0)) {
        // cout << "j index " << jj << " > " << j << " [" << height[jj] << ", " << height[j] << "]" << endl;
        if((j - jj) > 1) {
          water += min(height[j], height[jj]) * (j-jj-1) - accumulate(height.begin()+jj+1, height.begin()+j, 0);
          // cout << "water added: " << min(height[j], height[jj]) * (j-jj-1) << " - " << accumulate(height.begin()+jj+1, height.begin()+j, 0) << endl;
        }
        j = jj;
      }
      --jj;
    }
    return water;
  }
};


int main(int argc, char** argv)
{
  // vector<int> heights {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> heights {2, 0, 2};
  // vector<int> heights;
  vector<int> heights {4, 2, 3};

  Solution sol;
  int answer = sol.trap(heights);

  cout << "ANSWER: " << answer << endl;
  return 0;
}
