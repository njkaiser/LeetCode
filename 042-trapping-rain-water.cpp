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
    int water = 0;
    int lidx = 0, ridx = height.size()-1;
    int lmax = 0, rmax = 0;

    while(lidx < ridx) {
      if(height[lidx] < height[ridx]) {
        if(height[lidx] > lmax) { lmax = height[lidx]; }
        else { water += lmax - height[lidx]; }
        ++lidx;
      }
      else {
        if(height[ridx] > rmax) { rmax = height[ridx]; }
        else { water += rmax - height[ridx]; }
        --ridx;
      }
    }

    return water;
  }
};


int main(int argc, char** argv)
{
  vector<int> heights {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> heights {2, 0, 2};
  // vector<int> heights;
  // vector<int> heights {4, 2, 3};

  Solution sol;
  int answer = sol.trap(heights);

  cout << "ANSWER: " << answer << endl;
  return 0;
}
