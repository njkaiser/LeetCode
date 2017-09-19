// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
  string countAndSay(int n) {
    int num = 1;
    // string output = "1";

    // loop through each iteration
    for(int i = 0; i < n; ++i) {
      int count = 0;
      int currdig = num % 10;
      int newnum = 0;

      // grab number of digits
      int N = 0;
      int tmp = num;
      while(tmp) { ++N; tmp /= 10; }
      // cout << "N: " << N << endl;

      // while(num) {
      for(int j = 0; j < N; ++j) {
        cout << "[" << i << "][" << j << "] num: " << num << endl;
        int lastdig = currdig;
        currdig = num % 10;
        ++count;
        cout << "[" << i << "][" << j << "]   count: " << count << " currdig: " << currdig << " lastdig: " << lastdig << endl;
        if(currdig != lastdig || num < 10) {
          newnum = 100 * newnum + 10 * count + currdig;
          count = 0;
          cout << "[" << i << "][" << j << "]   newnum: " << newnum << endl;
        }
        else {
          // ++count;
          cout << "[" << i << "][" << j << "]   incrementing, count = " << count << endl;
        }
        num /= 10;
      }
      num = newnum;
    }
    return "1";
  }
};


int main(int argc, char** argv)
{
  int n = 4;
  Solution sol;
  string answer = sol.countAndSay(n);
  cout << "answer = " << answer << endl;
}
