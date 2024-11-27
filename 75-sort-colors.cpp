// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in
// the order red, white, and blue.
// 
// We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.
// 
// You must solve this problem without using the library's sort function.
// 
// 
// Example 1:
// 
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:
// 
// Input: nums = [2,0,1]
// Output: [0,1,2]
//  
// 
// Constraints:
// 
// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
//  
// 
// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

#include <vector>
#include <iostream>

using namespace std;


class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int reds = 0;
    int blues = 0;
    for (auto it : nums) {
      if (it == 0) {
        ++reds;
      }
      if (it == 2) {
        ++blues;
      }
    }
    for (auto i = 0; i < nums.size(); ++i) {
      if (i < reds) {
        nums[i] = 0;
      } else if (i >= nums.size() - blues) {
        nums[i] = 2;
      } else {
        nums[i] = 1;
      }
    }
  }
};


int main(int argc, char** argv)
{
  vector<int> nums{{1, 2, 0, 0, 2, 1, 1}};
  Solution s;
  s.sortColors(nums);
  cout << "after partition: [";
  for (auto it : nums) {
    cout << it << ", ";
  }
  cout << "]" << endl;
}
