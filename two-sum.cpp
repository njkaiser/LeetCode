// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int i = 0;
        int j = nums.size();
        vector<int> comps(j);
        vector<int> ret;

        // while(i < j)
        // {
        //     int sum = nums[i] + nums[j];
        //     if(sum == target)
        //         return {i, j};
        //     else if(sum > target)
        //     {
        //         // comps.push_back()
        //         // --j;
        //     }
        //     else if(sum < target)
        //     {
        //         // ++i;
        //     }
        // }

        // int m = 0;
        comps[0] = nums[0];
        for(int k = 1; k < nums.size(); ++k)
        {
            for(int m = 0; m < k; ++m)
            {
              cout << "m, k = " << m << ", " << k << endl;
              if(nums[k] + comps[m] == target)
                {
                  cout << "made it in the loop: " << m << ", " << k << endl;
                  ret.push_back(m);
                  ret.push_back(k);
                  return ret;
                }
              else
                comps[k] = (nums[k]);
                cout << "comps:" << endl;
                for(vector<int>::iterator it = comps.begin(); it != comps.end(); ++it)
                  cout << *it << endl;
            }
        }
    }
};


int main(int argc, char** argv)
{
    static const int arr[] = {2, 5, 5, 11};
    vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int target = 10;

    Solution sol;
    vector<int> answer = sol.twoSum(input, target);

    cout << "answer =" << endl;
    for(vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
      cout << *it << endl;
}
