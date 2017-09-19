// Given a digit string, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below.
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
// Note: Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  void recursive_part(string S, vector<string>& output) {

    // cout << "input: " << endl;
    // for(int i = 0; i < output.size(); ++i) {
    //   cout << output[i] << " ";
    // }
    // cout << endl;

    if(S.size()) {
      string letters;
      switch (S[0]) {
        case '2': letters =  "abc"; break;
        case '3': letters =  "def"; break;
        case '4': letters =  "ghi"; break;
        case '5': letters =  "jkl"; break;
        case '6': letters =  "mno"; break;
        case '7': letters = "pqrs"; break;
        case '8': letters =  "tuv"; break;
        case '9': letters = "wxyz"; break;
      }

      int N = letters.size();
      // cout << "letters size: " << N << endl;

      vector<string> tmp = output;
      output.reserve(output.size() * N);
      for(int i = 1; i < N; ++i) {
        output.insert(output.end(), tmp.begin(), tmp.end());
      }

      // cout << "size: " << output[0].size() << endl;
      for(int i = 0; i < output.size(); ++i) {
        output[i] += letters[i/tmp.size()];
      }

      recursive_part(S.substr(1, S.size()), output);
    }
  }

  vector<string> letterCombinations(string S) {
    vector<string> output;
    if(!S.size()) { return output; }
    output.push_back("");
    recursive_part(S, output);
    return output;
  }
};


int main(int argc, char** argv)
{
  string S = "222";

  Solution sol;
  vector<string> answer = sol.letterCombinations(S);

  cout << "answer = " << endl;
  for(int i = 0; i < answer.size(); ++i) {
    cout << answer[i] << " ";
  }
  cout << endl;
}
