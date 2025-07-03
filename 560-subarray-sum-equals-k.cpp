// 560. Subarray Sum Equals K
//
// Given an array of integers nums and an integer k, return the total number of
// subarrays whose sum equals to k.
//
// A subarray is a contiguous non-empty sequence of elements within an array.
//
// 
// Example 1:
//  Input: nums = [1,1,1], k = 2
//  Output: 2
//
//
// Example 2:
//  Input: nums = [1,2,3], k = 3
//  Output: 2
//  
//
// Constraints:
// * 1 <= nums.length <= 2 * 104
// * -1000 <= nums[i] <= 1000
// * -107 <= k <= 107

#include <iostream>
//#include <numeric>
#include <string>
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
    int subarraySum(std::vector<int>& nums, int k) {
      std::unordered_map<int, int> prefix_counts{{0, 1}};

      int cum_sum = 0;
      int output = 0;

      for (const auto num : nums) {
        cum_sum += num;
        const int diff = cum_sum - k;
        if (prefix_counts.count(diff)) {
          output += prefix_counts[diff];
        }
        if (!prefix_counts.count(cum_sum)) {
          prefix_counts[cum_sum] = 0;
        }
        prefix_counts[cum_sum] += 1;
      }


      //// Pre-calculate a cumulative sum vector.
      //std::vector<int> sums(nums.size());
      //std::partial_sum(nums.begin(), nums.end(), sums.begin());
      //printVector(" SUMS: ", sums);

      //auto a = sums.cbegin();
      //auto b = sums.cbegin() + 1;

      //int output = 0;
      //while (a != sums.cend() -1 && b != sums.cend()) {
      //  //if (*a == k) {
      //  //  std::cout << "special! " << k << std::endl;
      //  //  ++output;
      //  //}

      //  const auto sum = *b - *a;
      //  std::cout << "sum: " << sum << std::endl;
      //  if (sum > k) {
      //    std::cout << "too large" << std::endl;
      //    ++a;
      //  } else if (sum < k) {
      //    std::cout << "too small" << std::endl;
      //    *(a + 1) > *(b + 1) ? ++a : ++b;
      //    //if (b + 1 == sums.cend()) {
      //    //  ++a;
      //    //  continue;
      //    //}
      //    //++b;
      //  } else {
      //    std::cout << "goldilocks!" << std::endl;
      //    ++output;
      //    ++b;
      //  }

      //  //if (b == sums.cend()) {
      //  //  break;
      //  //}
      //  if (a == b && b == sums.cend()) {
      //    break;
      //  }
      //}

      return output;
    }
};


int main(int argc, char** argv) {
  //int k = 2;
  //std::vector<int> nums = {1, 1, 1};

  //int k = 2;
  //std::vector<int> nums = {1, -2, 1};

  int k = 6;
  std::vector<int> nums = {100,1,2,3,4};

  printVector("INPUT: ", nums);

  Solution s;
  const auto answer = s.subarraySum(nums, k);
  std::cout << "ANSWER: " << answer << std::endl;

  return 0;
}
