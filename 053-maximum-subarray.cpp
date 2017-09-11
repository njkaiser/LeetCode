// Find the contiguous subarray within an array (containing at least one number)
// which has the largest sum.
//
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray
// [4,-1,2,1] has the largest sum = 6.

#include <iostream>
#include <vector>
#include <algorithm> // max_element()
#include <limits.h> // INT_MIN

using namespace std;


class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int curr_sum = 0;
    int max_sum = INT_MIN;
    bool all_negative = 1;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] > 0) { all_negative = 0; }
      curr_sum = (curr_sum + nums[i]) > 0 ? curr_sum + nums[i] : 0;
      max_sum = (curr_sum > max_sum) ? curr_sum : max_sum;
    }
    if(all_negative) { return *max_element(nums.begin(), nums.end()); }
    else { return max_sum; }
  }
};


int main(int argc, char* argv[])
{
  vector<int> input {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // vector<int> input {-1};

  Solution sol;

  int max_sum = sol.maxSubArray(input);

  cout << "ANSWER: " << max_sum << endl;
  return 0;
}
