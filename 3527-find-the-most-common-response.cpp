// 3527. Find the Most Common Response
//
// You are given a 2D string array responses where each responses[i] is an
// array of strings representing survey responses from the ith day. Return the
// most common response across all days after removing duplicate responses
// within each responses[i]. If there is a tie, return the lexicographically
// smallest response.
// 
// 
// Example 1:
// 
// Input: responses = [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]
// 
// Output: "good"
// 
// Explanation:
// 
// After removing duplicates within each list,
// responses = [["good", "ok"], ["ok", "bad", "good"], ["good"], ["bad"]].
// "good" appears 3 times, "ok" appears 2 times, and "bad" appears 2 times.
// Return "good" because it has the highest frequency.
//
//
// Example 2:
// 
// Input: responses = [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]
// 
// Output: "bad"
// 
// Explanation:
// 
// After removing duplicates within each list we have
// responses = [["good", "ok"], ["ok", "bad"], ["bad", "notsure"], ["great", "good"]].
// "bad", "good", and "ok" each occur 2 times.
// The output is "bad" because it is the lexicographically smallest amongst the
// words with the highest frequency.
//  
// 
// Constraints:
// - 1 <= responses.length <= 1000
// - 1 <= responses[i].length <= 1000
// - 1 <= responses[i][j].length <= 10
// - responses[i][j] consists of only lowercase English letters

#include <cstring>
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
#include <string>
#include <vector>


class Solution {
  public:
    std::string findCommonResponse(std::vector<std::vector<std::string>>& responses) {
      std::unordered_map<std::string, int> m;
      for (const auto& rs : responses) {
        std::unordered_set<std::string> s{rs.cbegin(), rs.cend()};
        for (const auto& r : s) {
          if (!m.count(r)) {
            m[r] = 1;
            continue;
          }

          m[r] += 1;
        }
      }

      // Find most common, including tie-breaking logic.
      int max_count = 0;
      std::string winner;
      for (const auto& p : m) {
        const auto& r = p.first;
        const auto& count = p.second;
        std::cout << "final count for " << r << ": " << count << std::endl;
        if (count > max_count) {
          winner = r;
          max_count = count;
        } else if (count == max_count && r < winner) {
          winner = r;
        }
      }

      return winner;
    };
};


int main(int argc, char** argv) {
  //std::vector<std::vector<std::string>> test{{"good","ok","good","ok"}, {"ok","bad","good","ok","ok"}, {"good"}, {"bad"}};
  std::vector<std::vector<std::string>> test{{"good","ok","good"}, {"ok","bad"}, {"bad","notsure"}, {"great","good"}};

  Solution s{};
  const auto answer = s.findCommonResponse(test);
  std::cout << "ANSWER: " << answer << std::endl;
  return 0;
}
