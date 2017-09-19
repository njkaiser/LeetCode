// Given an array of integers, return indices of the two numbers such that
// they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you
// may not use the same element twice.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    unordered_map<int, int>::iterator loc;
    vector<int> output(2);
    int comp;

    for(int i = 0; i < nums.size(); ++i) {
      comp = target - nums[i];
      loc = hashmap.find(comp);
      if(loc != hashmap.end()) {
        output[0] = loc->second;
        output[1] = i;
        return output;
      } else {
        hashmap[nums[i]] = i;
      }
    }
  }
};


int main(int argc, char** argv)
{
  static const int arr[] = {2, 5, 5, 11};
  vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));

  int target = 10;

  Solution sol;
  vector<int> answer = sol.twoSum(input, target);

  cout << "answer =" << endl;
  for(vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
  cout << *it << endl;
}
