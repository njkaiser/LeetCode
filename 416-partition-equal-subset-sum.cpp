// 416. Partition Equal Subset Sum
//
// Given an integer array nums, return true if you can partition the array into
// two subsets such that the sum of the elements in both subsets is equal or
// false otherwise.
//  
//
// Example 1:
//  Input: nums = [1,5,11,5]
//  Output: true
//  Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
// Example 2:
//  Input: nums = [1,2,3,5]
//  Output: false
//  Explanation: The array cannot be partitioned into equal sum subsets.
//   
//
// Constraints:
// * 1 <= nums.length <= 200
// * 1 <= nums[i] <= 100

#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>


template <typename T>
void printVector(const std::string& prefix, const std::vector<T>& v) {
  std::cout << prefix << "[";
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    if (it == v.cend() - 1) {
      std::cout << *it;
    } else {
      std::cout << *it << ", ";
    }
  }
  std::cout << "]" << std::endl;
}


class Solution {
  public:
    bool canPartition(std::vector<int>& nums) {
      // Early exit if the number is odd.
      const int sum = std::accumulate(nums.begin(), nums.end(), 0);
      std::cout << "sum: " << sum << std::endl;
      if (sum % 2 != 0) {
        std::cout << "ODD!" << std::endl;
        return false;
      }

      const int target = sum / 2;
      
      std::vector<bool> possible(target + 1, false);
      possible[0] = true;

      for (const auto n : nums) {
        for (int x = target; x >= n; --x) {
          if (possible[x - n]) {
            possible[x] = true;
          }
        }
        std::cout << "after processing: " << n << std::endl;
        printVector("POSSIBLE: ", possible);
      }
      
      //printVector("POSSIBLE: ", possible);
      return possible.back();
    }
};


int main(int argc, char** argv) {
  //std::vector<int> nums{1,5,11,5};
  //std::vector<int> nums{1,2,3,5};
  //std::vector<int> nums{1,3,4,6};
  //std::vector<int> nums{7,2,6,5};
  //std::vector<int> nums{42,6,11,5};
  std::vector<int> nums{3,3,3,4,5};

  printVector("INPUT: ", nums);

  Solution s;
  const auto answer = s.canPartition(nums);
  std::cout << "ANSWER: " << answer << std::endl;

  return EXIT_SUCCESS;
}
