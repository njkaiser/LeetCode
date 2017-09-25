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
  int sz, ans, global_amount;

  int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    ans = amount + 1;
    global_amount = amount;
    sz = coins.size();
    sort(coins.begin(), coins.end(), greater<int>());

    DFS(coins, amount, 0);

    cout << "ans, amount: " << ans << ", " << amount << endl;
    return (ans < amount+1) ? ans : -1;
  }

  void DFS(vector<int>& coins, int amount, int lvl) {
    cout << "entering level: " << lvl << " with amount: " << amount << endl;
    if(lvl == global_amount+1) return; // base case

    // int n = amount / coins[lvl];
    int leftover;
    for(int i = 0; i < sz; ++i) {
      leftover = amount - coins[i];
      cout << "[" << lvl << "][" << i << "] " << leftover << ", (" << ans << ")" << endl;
      if(leftover > 0) DFS(coins, leftover, lvl+1);
      // else if(leftover < 0) break;
      else if(leftover == 0) {
        ans = lvl+1;
        cout << "answer is: " << ans << endl;
        sz = 0; // break out of all recursive loops
        return;
      }
      cout << "here" << endl;
    }

  }
};


int main(int argc, char** argv)
{
  // int amount = 11;
  // int amount = 1;
  // int amount = 27;
  int amount = 6249;
  // int amount = 2;
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


// if(amount == 0) { return 0; }
// vector<int> prev(amount, amount+1); // initialize to zero
// vector<int> curr(amount, amount+1);
// sort(coins.begin(), coins.end());
//
// for(int j = 0; j < coins.size(); ++j) {
//   for(int i = 0; i < prev.size(); ++i) {
//     if((i+1) % coins[j] == 0) { curr[i] = (i+1) / coins[j]; }
//     else if(i < coins[j]) { curr[i] = prev[i]; }
//     else if(curr[i-coins[j]] == 0) { curr[i] = prev[i]; }
//     else {
//       curr[i] = (prev[i] > 0) ? min(prev[i], 1 + curr[i-coins[j]]) : 0;
//     }
//
//     cout << curr[i] << ", ";
//   }
//   cout << endl;
//   prev = curr;
// }
