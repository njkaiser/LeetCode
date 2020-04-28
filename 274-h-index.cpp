// TO COMPILE: g++ 274-h-index.cpp --std=c++11

// Given an array of citations (each citation is a non-negative integer) of a
// researcher, write a function to compute the researcher's h-index.
//
// According to the definition of h-index on Wikipedia: "A scientist has index
// h if h of his/her N papers have at least h citations each, and the other
// N − h papers have no more than h citations each."
//
// Example:
//
// Input: citations = [3,0,6,1,5]
// Output: 3 
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
// of them had received 3, 0, 6, 1, 5 citations respectively. Since the
// researcher has 3 papers with at least 3 citations each and the remaining two
// with no more than 3 citations each, her h-index is 3.
//
// Note: If there are several possible values for h, the maximum one is taken as the h-index.

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


class Solution {
 public:
  int hIndex(vector<int>& citations) {
    // Exit early for corner case.
    if (!citations.size()) {
      return 0;
    }

    // Set up data structure for keeping track of counts.
    const size_t N = *std::max_element(citations.begin(), citations.end());
    std::vector<int> counts(N + 1, 0); // +1 to include zero

    // Fill the number of citations for each paper.
    for (const auto& c : citations) {
      counts[c] += 1;
    }

    //cout << "COUNTS:" << endl;
    //for (const auto& c : counts) {
    //  cout << "  " << c << endl;
    //}

    int total = 0;
    for (int i = N; i >= 0; --i) {
      total += counts[i];
      if (total >= i) {
        return i;
      }
    }

    return 0;
  }
};


int main(int argc, char** argv) {
  vector<vector<int>> list = {
    {3, 0, 6, 1, 5},
    {3, 0, 6, 1, 5},
    {0, 0, 0, 0, 1},
    {5, 5, 5, 4, 0},
    {1, 1},
    {0},
    {},
  };

  for (auto& input : list) {
    Solution sol;
    const int answer = sol.hIndex(input);
    cout << "answer = " << answer << endl;
  }

  return 0;
}
