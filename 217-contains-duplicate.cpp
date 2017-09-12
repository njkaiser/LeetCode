// Given an array of integers, find if the array contains any duplicates. Your
// function should return true if any value appears at least twice in the array,
// and it should return false if every element is distinct.

#include <iostream>
#include <vector>
#include <unordered_set> // std::unordered_set

using namespace std;


class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for(int i = 0; i < nums.size(); ++i) {
      if(s.find(nums[i]) != s.end()) { return true; }
      s.insert(nums[i]);
    }
    return false;
  }
};


int main(int argc, char** argv)
{
  // vector<int> nums {1, 2, 3};
  vector<int> nums {1, 2, 2};

  Solution sol;
  bool answer = sol.containsDuplicate(nums);

  cout << "ANSWER: " << answer << endl;
  return 0;
}
