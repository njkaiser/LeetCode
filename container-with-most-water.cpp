// Given n non-negative integers a1, a2, ..., an, where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
// of line i is at (i, ai) and (i, 0). Find two lines, which together with
// x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// typedef struct
// {
//   int index;
//   int height;
//   // Pair(int in, int h) {index = in; height = h;}
// } Pair;


class Solution {
public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size()-1;
    int area;
    int max_area = 0;
    while(i<j) {
      area = (j-i) * min(height[i], height[j]);
      max_area = (area > max_area) ? area : max_area;
      // cout << "i, j, height1, height2 (max_area): " << i << ", " << j << ", " << height[i] << ", " << height[j] << " (" << max_area << ")" <<  endl;
      if(height[i] < height[j]) {
        while(height[i+1] <= height[i++]) { ; }
      } else {
        while(height[j-1] <= height[j--]) { ; }
      }
    }
    return max_area;
  }
};


int main(int argc, char** argv)
{
  // vector<int> height = {3, 2, 5, 4, 7, 1, 3, 4, 2, 6, 3};
  // vector<int> height = {1, 3, 2, 5, 25, 24, 5};
  vector<int> height = {1, 2, 1};

  cout << "elements in height vector:" << endl;
  for(vector<int>::iterator it = height.begin(); it != height.end(); ++it)
  {
    cout << *it << endl;
  }

  Solution sol;
  cout << "ANSWER IS: " << sol.maxArea(height) << endl;

  return 0;
}
