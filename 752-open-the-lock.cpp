// TO COMPILE: g++ 752-open-the-lock.cpp --std=c++11

// You have a lock in front of you with 4 circular wheels. Each wheel has 10
// slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can
// rotate freely and wrap around: for example we can turn '9' to be '0', or '0'
// to be '9'. Each move consists of turning one wheel one slot.
//
// The lock initially starts at '0000', a string representing the state of the
// 4 wheels.
// 
// You are given a list of deadends dead ends, meaning if the lock displays any
// of these codes, the wheels of the lock will stop turning and you will be
// unable to open it.
// 
// Given a target representing the value of the wheels that will unlock the
// lock, return the minimum total number of turns required to open the lock, or
// -1 if it is impossible.
// 
// Example 1:
// Input:
//   deadends = ["0201","0101","0102","1212","2002"],
//   target = "0202"
// Output: 6
// Explanation:
// A sequence of valid moves would be:
//   "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like:
//   "0000" -> "0001" -> "0002" -> "0102" -> "0202"
// would be invalid, because the wheels of the lock become stuck after the
// display becomes the dead end "0102".
//
// Example 2:
// Input:
//   deadends = ["8888"],
//   target = "0009"
// Output: 1
// Explanation:
// We can turn the last wheel in reverse to move from "0000" -> "0009".
//
// Example 3:
// Input:
//   deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
//   target = "8888"
// Output: -1
// Explanation:
// We can't reach the target without getting stuck.
//
// Example 4:
// Input:
//   deadends = ["0000"],
//   target = "8888"
// Output: -1
//
// Note:
// The length of deadends will be in the range [1, 500].
// target will not be in the list deadends.
// Every string in deadends and the string target will be a string of 4 digits
// from the 10,000 possibilities '0000' to '9999'.

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;


class Solution {
 public:
  // Helper function for adding neighbor states to our data structures.
  void addState(const int new_state, queue<int>& to_explore, vector<bool>& expanded) {
    if (!expanded[new_state]) {
      to_explore.emplace(new_state);
      expanded[new_state] = true;
    }
  }

  int openLock(vector<string>& deadends, string target) {
    // Convert string to int.
    const int goal = stoi(target);
    cout << "goal: " << goal << endl;

    // Return immediately if we're already at the target.
    if (goal == 0) { return 0; }

    // Set up a memoization structure and mark off the deadends.
    vector<bool> expanded(10000, false);
    for (const auto& deadend_string : deadends) {
      expanded[std::stoi(deadend_string)] = true;
    }

    // Exit early if we start in an invalid state.
    if (expanded[goal] == true || expanded[0] == true) {
      cout << "exiting early, goal is trivially blocked!" << endl;
      return -1;
    }

    // Add the initial state after checking if it's blocked first.
    expanded[0] = true;

    // Data structures for expanding our DFS frontier. `currently_exploring`
    // contains the current leaf nodes, and `to_explore` is where we add new
    // leafs we'll expand to next step (we basically use them as a double
    // buffer).
    queue<int> to_explore;
    queue<int> currently_exploring;
    currently_exploring.emplace(0); // seed the first round

    int num_turns = 1; // the output value
    while (!currently_exploring.empty()) {
      const int current_state = std::move(currently_exploring.front());
      currently_exploring.pop();

      cout << "state=" << current_state << endl;

      // Process ones digit.
      const int ones_digit = current_state % 10;
      if (ones_digit == 0) {
        addState(current_state + 1, to_explore, expanded);
        addState(current_state + 9, to_explore, expanded);
      } else if (ones_digit  == 9) {
        addState(current_state - 9, to_explore, expanded);
        addState(current_state - 1, to_explore, expanded);
      } else {
        addState(current_state + 1, to_explore, expanded);
        addState(current_state - 1, to_explore, expanded);
      }

      // Process tens digit.
      const int tens_digit = (current_state % 100) / 10;
      if (tens_digit == 0) {
        addState(current_state + 10, to_explore, expanded);
        addState(current_state + 90, to_explore, expanded);
      } else if (tens_digit == 9) {
        addState(current_state - 90, to_explore, expanded);
        addState(current_state - 10, to_explore, expanded);
      } else {
        addState(current_state + 10, to_explore, expanded);
        addState(current_state - 10, to_explore, expanded);
      }

      // Process hundreds digit.
      const int hundreds_digit = (current_state % 1000) / 100;
      if (hundreds_digit == 0) {
        addState(current_state + 100, to_explore, expanded);
        addState(current_state + 900, to_explore, expanded);
      } else if (hundreds_digit == 9) {
        addState(current_state - 900, to_explore, expanded);
        addState(current_state - 100, to_explore, expanded);
      } else {
        addState(current_state + 100, to_explore, expanded);
        addState(current_state - 100, to_explore, expanded);
      }

      // Process thousands digit.
      const int thousands_digit = current_state / 1000;
      if (thousands_digit == 0) {
        addState(current_state + 1000, to_explore, expanded);
        addState(current_state + 9000, to_explore, expanded);
      } else if (thousands_digit == 9) {
        addState(current_state - 9000, to_explore, expanded);
        addState(current_state - 1000, to_explore, expanded);
      } else {
        addState(current_state + 1000, to_explore, expanded);
        addState(current_state - 1000, to_explore, expanded);
      }

      // Return the current count if we've reached the goal.
      if (expanded[goal] == true) {
        return num_turns;
      }

      // If we reach the end of this level, load the data for the next.
      if (currently_exploring.empty()) {
        // Load the next set of data to check, effectively resetting 
        // `to_explore` to be populated next round.
        std::swap(currently_exploring, to_explore);

        // Increment the count for next loop.
        ++num_turns;
      }
    }

    return -1;
  }
};


int main(int argc, char** argv) {
  vector<string> deadends{"0201","0101","0102","1212","2002"};
  const string target = "0202";

  //vector<string> deadends{"8888"};
  //const string target = "0009";

  //vector<string> deadends{"8887","8889","8878","8898","8788","8988","7888","9888"};
  //const string target = "8888";

  //vector<string> deadends{"0000"};
  //const string target = "8888";

  //vector<string> deadends{"4","6"};
  //const string target = "5";

  Solution sol;
  const int answer = sol.openLock(deadends, target);
  cout << "answer = " << answer << endl;

  return 0;
}
