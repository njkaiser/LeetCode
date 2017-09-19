// Given an array and a value, remove all instances of that value
// in place and return the new length.
//
// Do not allocate extra space for another array, you must do this
// in place with constant memory.
//
// The order of elements can be changed. It doesn't matter what you
// leave beyond the new length.
//
// Example:
// Given input array nums = [3,2,2,3], val = 3
//
// Your function should return length = 2, with the first two elements of nums being 2.

#include <vector>
#include <iostream>
#include <algorithm> // iter_swap

using namespace std;


class Solution {
public:
  int removeElement(vector<int>& nums, int val) {

    int output = nums.size();
    if(!output) { return 0; }
    vector<int>::iterator cur = nums.begin();
    vector<int>::iterator end = nums.end()-1;

    // for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    //   cout << *it << endl;

    while(cur <= end) {
      if(*cur == val) {
        iter_swap(cur, end);
        --end;
        --output;
      }
      else {
        ++cur;
      }
    }
    return output;
  }
};


int main(int argc, char** argv)
{
  int val = 3;
  int input[] = {3, 2, 2, 3};
  vector<int> nums(input, input + sizeof(input) / sizeof(input[0]));

  Solution sol;
  int answer = sol.removeElement(nums, val);

  cout << "answer =" << endl;
  for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    cout << *it << endl;
}
