// Given an array of non-negative integers, you are initially positioned
// at the first index of the array. Each element in the array represents
// your maximum jump length at that position. Determine if you are able
// to reach the last index.
//
// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  bool canJump(vector<int>& nums) {
    vector<int>::iterator it = nums.begin();
    if(it + *it >= nums.end()-1) { return true; } // we know we can reach the goal
    if(*it <= 0) { return false; } // pointless wasting any more time on this one

    vector<int>::iterator min = it;
    vector<int>::iterator max = nums.begin() + *it;
    vector<int>::iterator last_max = max;
    it = max;

    while(1) {
      for(it = max ; it >= min; --it) {
        max = (it + *it > max) ? it + *it : max;
        if(max >= nums.end()-1) { return true; } // we're done!
      }
      if(max == last_max) { return false; } // can't go any further
      min = last_max;
      last_max = max;
    }
  }
};


int main(int argc, char** argv)
{
  vector<int>A = {2,3,1,1,4};
  vector<int>B = {3,2,1,0,4};
  vector<int>C = {2,0,0};

  Solution sol;
  cout << sol.canJump(C) << endl;
  return 0;
}
