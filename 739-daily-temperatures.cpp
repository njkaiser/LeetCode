// 739. Daily Temperatures
//
// Given an array of integers temperatures represents the daily temperatures,
// return an array answer such that answer[i] is the number of days you have
// to wait after the ith day to get a warmer temperature. If there is no future
// day for which this is possible, keep answer[i] == 0 instead.
//
//  
// Example 1:
//  Input: temperatures = [73,74,75,71,69,72,76,73]
//  Output: [1,1,4,2,1,1,0,0]
//
//
// Example 2:
//  Input: temperatures = [30,40,50,60]
//  Output: [1,1,1,0]
//  
//
// Example 3:
//  Input: temperatures = [30,60,90]
//  Output: [1,1,0]
//   
//
// Constraints:
// * 1 <= temperatures.length <= 105
// * 30 <= temperatures[i] <= 100

#include <iostream>
#include <stack>
#include <vector>


template <typename T>
void printVector(const std::string& prefix, const std::vector<T>& v) {
  std::cout << prefix << ": [";
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
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
      std::vector<int> output(temperatures.size(), 0);

      std::stack<int> stack;
      for (int i_curr = 0; i_curr < temperatures.size(); ++i_curr) {
        const auto& t = temperatures[i_curr];
        while (!stack.empty() && (t > temperatures[stack.top()])) {
          const auto i_prev = stack.top();
          stack.pop();
          output[i_prev] = i_curr - i_prev;
        }
        stack.push(i_curr);
      }

      return output;
    }
};


int main(int argc, char** argv) {
  std::vector<int> input{73,74,75,71,69,72,76,73};
  //std::vector<int> input{30,40,50,60};
  //std::vector<int> input{30,60,90};
  printVector(" INPUT", input);

  Solution s{};
  const auto answer = s.dailyTemperatures(input);
  printVector("ANSWER", answer);
  printVector("EXPECT", std::vector<int>{1,1,4,2,1,1,0,0});

  return 0;
}
