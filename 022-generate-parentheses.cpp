// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
// 
// For example, given n = 3, a solution set is:
// 
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//
// EXTRA ANSWER FOR n = 4:
// [
//   "(((())))",
//   "((()()))",
//   "((())())",
//   "((()))()",
//   "(()(()))",
//   "(()()())",
//   "(()())()",
//   "(())(())",
//   "(())()()",
//   "()((()))",
//   "()(()())",
//   "()(())()",
//   "()()(())",
//   "()()()()"
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  void addNextParen(string s, vector<string>& output, const int i, int num_lefts) {
    //cout << "entered addNextParen with params: " << s << ", " << i << ", " << num_lefts << endl;
    // Exit condition.
    if (i == s.size() - 1) {
      output.emplace_back(s);
      //cout << "adding: " << s << " to output" << endl;
      return;
    }

    //if (i > s.size() - 1) {
    //  cout << "WTF, BUG" << endl;
    //  return;
    //}

    if (num_lefts < s.size() / 2) {
      //cout << "adding left" << endl;
      //s[i] = '(';
      addNextParen(s, output, i + 1, num_lefts + 1);
    }
    const int num_rights = i - num_lefts;
    if (num_lefts > num_rights) {
      //cout << "adding right" << endl;
      s[i] = ')';
      addNextParen(s, output, i + 1, num_lefts);
    }

    return;
  }

  vector<string> generateParenthesis(int n) {
    vector<string> output;
    if (n == 0) {
      return output;
    }

    const int N = 2 * n;

    string s(N, '(');
    //string s(N, 'x');
    //s[0] = '(';
    s[s.size() - 1] = ')';

    //cout << "s for n = " << n << " [" << N << "] before entering: " << s << endl;

    addNextParen(s, output, 1, 1);

    //for (int i = 0; i < n; ++i) {
    //  s[i] = '(';
    //}
    //output.emplace_back(s);

    //int num_lefts = 1;
    //int num_rights = 0;
    //for (int i = 1; i < N - 1 ; ++i) {
    //  blah
    //}

    //for (int i = 1; i < N / 2; ++i) {
    //  for (int j = N - 2; j >= N / 2; --j) {
    //    //if (i == j) {
    //    //  continue;
    //    //}
    //    swap(s[i], s[j]);
    //    cout << "s for [i, j]: " << s << "  [" << i << ", " << j << "]" << endl;
    //    output.emplace_back(s);
    //    swap(s[j], s[i]);
    //  }
    //}

    return output;
  }
};

int main(int argc, char** argv) {
  Solution s;

  for (const int n : {0, 1, 2, 3, 4}) {
    const auto answer = s.generateParenthesis(n);
    cout << "answer for n = " << n << ":" << endl;
    for (const auto& a : answer) {
      cout << a << endl;
    }
    cout << endl;

  }

  cout << "DONE" << endl;
  return 0;
}
