// TO COMPILE: g++ 322-coin-change.cpp --std=c++11

// You are given coins of different denominations and a total amount of money
// amount. Write a function to compute the fewest number of coins that you need to
// make up that amount. If that amount of money cannot be made up by any
// combination of the coins, return -1.
//
// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)
//
// Example 2:
// coins = [2], amount = 3
// return -1.
//
// Note:
// You may assume that you have an infinite number of each kind of coin.

#include <iostream>
#include <vector>
#include <algorithm> // std::sort()

using namespace std;


class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) { return 0; }
    vector<int> prev(amount, amount+1); // initialize to zero
    vector<int> curr(amount, amount+1);
    sort(coins.begin(), coins.end());

    for(int j = 0; j < coins.size(); ++j) {
      for(int i = 0; i < prev.size(); ++i) {
        if((i+1) % coins[j] == 0) { curr[i] = (i+1) / coins[j]; }
        else if(i < coins[j]) { curr[i] = prev[i]; }
        else if(curr[i-coins[j]] == 0) { curr[i] = prev[i]; }
        else {
          curr[i] = (prev[i] > 0) ? min(prev[i], 1 + curr[i-coins[j]]) : 0;
        }

        cout << curr[i] << ", ";
      }
      cout << endl;
      prev = curr;
    }

    return (prev.back() > amount) ? -1 : prev.back();
    // return (prev.back() > 0) ? prev.back() : -1;
  }
};


int main(int argc, char** argv)
{
  // int amount = 11;
  // int amount = 1;
  // int amount = 27;
  int amount = 6249;
  // vector<int> coins {1, 2, 5};
  // vector<int> coins {2, 5, 10};
  // vector<int> coins {1};
  // vector<int> coins {2, 5, 10, 1};
  // vector<int> coins {1, 2, 5, 10};
  vector<int> coins {186, 419, 83, 408};

  Solution sol;
  int answer = sol.coinChange(coins, amount);
  cout << "answer = " << answer << endl;

  return 0;
}
