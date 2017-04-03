// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
  string intToRoman(int num) {
    string current;
    string output;
    string numerals[7] = {"I", "V", "X", "L", "C", "D", "M"};

    int idx = 0;
    while(num) {
      // int val = num % 10;
      string ones = numerals[idx];
      string fives = numerals[idx+1];
      // string tens = numerals[idx+2];
      switch(num % 10) {
        case 0 : current = ""; break;
        case 1 : current = ones; break;
        case 2 : current = ones + ones; break;
        case 3 : current = ones + ones + ones; break;
        case 4 : current = ones + fives; break;
        case 5 : current = fives; break;
        case 6 : current = fives + ones; break;
        case 7 : current = fives + ones + ones; break;
        case 8 : current = fives + ones + ones + ones; break;
        case 9 : current = ones + numerals[idx+2]; break;
        // case 0 : current = ""; break;
        // case 1 : current = numerals[idx]; break;
        // case 2 : current = (numerals[idx] + numerals[idx]); break;
        // case 3 : current = (numerals[idx] + numerals[idx] + numerals[idx]); break;
        // case 4 : current = (numerals[idx] + numerals[idx+1]); break;
        // case 5 : current = numerals[idx+1]; break;
        // case 6 : current = (numerals[idx+1] + numerals[idx]); break;
        // case 7 : current = (numerals[idx+1] + numerals[idx] + numerals[idx]); break;
        // case 8 : current = (numerals[idx+1] + numerals[idx] + numerals[idx] + numerals[idx]); break;
        // case 9 : current = (numerals[idx] + numerals[idx+2]); break;
        default : cout << "I SHOULD NEVER REACH HERE!!!" << endl; break;
      }
      num /= 10;
      idx += 2;
      output = current + output;
      cout << "building blocks: " << output << endl;
      // if(idx > 99) { break; } // devel
    }
    return output;
  }
};


// from LeetCode submissions, runs faster than mine:
class BetterSolution {
public:
  string intToRoman(int num) {
    string romanPieces[]={"","I","II","III","IV","V","VI","VII","VIII","IX",
    "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
    "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
    "","M","MM","MMM","MMMM"};
    return romanPieces[num/1000+30]+romanPieces[(num/100)%10+20]
    +romanPieces[(num/10)%10+10]+romanPieces[num%10];
  }
};


int main(int argc, char** argv) {
  Solution sol;
  // for(int i = 1; i < 3999; i*=2) {
  //   cout << "number: " << i << '\t' << sol.intToRoman(i) << endl;
  // }
  cout << sol.intToRoman(1024) << endl;
  return 0;
}
