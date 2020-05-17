// Given an array of citations sorted in ascending order (each citation is a
// non-negative integer) of a researcher, write a function to compute the
// researcher's h-index.
//
// According to the definition of h-index on Wikipedia: "A scientist has index
// h if h of his/her N papers have at least h citations each, and the other
// N − h papers have no more than h citations each."
//
// Example:
// Input: citations = [0,1,3,5,6]
// Output: 3 
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each
// of them had received 0, 1, 3, 5, 6 citations respectively. Since the
// researcher has 3 papers with at least 3 citations each and the remaining two
// with no more than 3 citations each, her h-index is 3.
//
// Note: If there are several possible values for h, the maximum one is taken
// as the h-index.
//
// Follow up: This is a follow up problem to H-Index, where citations is now
// guaranteed to be sorted in ascending order. Could you solve it in
// logarithmic time complexity?

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


class Solution {
 public:
  // Recursive version:
  // void binarySearch(const vector<int>& v, const int a, const int b, int& answer) {
  //   // Recursion termination. These are not the droids you're looking for.
  //   if (a == b) {
  //     //cout << "binarySearch exiting early!" << endl;
  //     return;
  //   }

  //   // Success exit condition.
  //   const int curr_index = (a + b) / 2;
  //   // cout << "binarySearch with: " << a << ", " << b << ", " << curr_index << ", " << answer << ", " << endl;

  //   const int to_end = v.size() - curr_index;
  //   if (v[curr_index] == (v.size() - curr_index)) {
  //     //answer = v[curr_index];
  //     answer = to_end;
  //     // cout << "FOUND ANSWER: " << answer << " [at index: " << curr_index << "]" << endl;
  //     return;
  //   } else if (curr_index == a) {
  //     answer = v[curr_index] < to_end ? to_end - 1 : to_end;
  //     return;
  //   }

  //   // Not found, keep recursing.
  //   if (v[curr_index] > (v.size() - curr_index)) {
  //     binarySearch(v, a, curr_index, answer);
  //   } else {
  //     binarySearch(v, curr_index, b, answer);
  //   }
  // }

  // int hIndex(vector<int>& citations) {
  //   int answer = 0;
  //   binarySearch(citations, 0, citations.size(), answer);
  //   return answer;
  // }

  // Non recursive version:
  int hIndex(vector<int>& citations) {
    // Early exit condition.
    if (citations.size() == 0) {
      return 0;
    }

    // Binary search.
    int a = 0;
    int b = citations.size();
    while (a < b) {
      const int current_index = (a + b) / 2;
      const int dist = citations.size() - current_index;

      // Exit condition 1:
      if (citations[current_index] == dist) {
        return dist;
      }
      // Exit condition 1:
      else if (current_index == a) {
        return citations[current_index] < dist ? dist - 1 : dist;
      }

      // Not found, keep looking.
      if (citations[current_index] > dist) {
        b = current_index;
      } else {
        a = current_index;
      }
    }
    return -1; // only needed to suppress compiler warning
  }
};


int main(int argc, char** argv) {
  vector<vector<int>> list = {
    {0, 1, 3, 5, 6},
    {0, 0, 0, 0, 1},
    {0, 4, 5, 5, 5},
    {0, 3, 5, 5, 5},
    {1, 1},
    {99},
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
