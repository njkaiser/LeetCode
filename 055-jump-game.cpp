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
    vector<int>::iterator start = nums.begin();
    // if(*start <= 0) { return false; } // pointless wasting any more time on this one
    vector<int>::iterator end = nums.begin() + *(nums.begin());
    return go(nums, start, end);
  }

  bool go(vector<int>& nums, vector<int>::iterator start, vector<int>::iterator end) {
    // cout << "entered go()" << endl;
    if(end + *end >= nums.end()-1) { return true; } // we know we can reach the goal
    for(vector<int>::iterator it = end; it != start; --it) {
      if(it + *it > end) {
        if(go(nums, end, it + *it)) {
          return true;
        }
      }
    }
    return false;
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
