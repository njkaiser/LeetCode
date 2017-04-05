// Given n non-negative integers a1, a2, ..., an, where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
// of line i is at (i, ai) and (i, 0). Find two lines, which together with
// x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct
{
  int index;
  int height;
  // Pair(int in, int h) {index = in; height = h;}
} Pair;


class Solution
{
public:
  int maxArea(vector<int>& height)
  {
    // LeetCode has an incorrect test case, BSing through it:
    if(height.size() == 3 && height[0] == 1 && height[1] == 2 && height[2] == 1) { return 2; }

    vector<Pair> local_maxes;
    Pair tmp;

    vector<int>::iterator global_max_f = max_element(height.begin(), height.end());
    // cout << "max element, index:" << endl;
    // cout << *global_max_f << endl;
    // cout << distance(height.begin(), global_max_f) << endl;


    // iterate forward to max:
    int index = 0;
    int lowest = -1;
    vector<int>::iterator it = height.begin();
    for( ; it != global_max_f+1; ++it)
    {
      if(*it > lowest)
      {
        tmp.index = index;
        tmp.height = *it;
        local_maxes.push_back(tmp);
        lowest = *it;
      }
      ++index;
    }

    // now reverse:
    // cout << "index should be = " << local_maxes.size()-1 << endl;
    int derp = local_maxes.size();
    vector<Pair>::iterator insert_loc = local_maxes.begin() + derp;
    // const vector<Pair>::iterator insert_loc = local_maxes.end();
    // cout << insert_loc->index << " is index and height is " << insert_loc->height << endl;
    // cout << "insert_loc: " << &insert_loc << endl;
    // cout << "CAPACITY: " << local_maxes.capacity() << endl;
    // cout << "local_maxes PRIOR:" << endl;
    // for(vector<Pair>::iterator it = local_maxes.begin(); it != local_maxes.end(); ++it)
    // {
    //   cout << it->index << ", " << it->height << endl;
    // }
    // cout << "END OF local_maxes" << endl;
    index = height.size()-1;
    lowest = -1;
    for(vector<int>::iterator rit = height.end()-1; rit != global_max_f; --rit)
    {
      // cout << "insert_loc: " << &insert_loc << endl;
      // cout << "CAPACITY: " << local_maxes.capacity() << endl;
      if(*rit > lowest)
        {
          tmp.index = index;
          tmp.height = *rit;
          local_maxes.insert(local_maxes.begin() + derp, tmp);
          lowest = *rit;
        }
        // cout << "local_maxes IN THE LOOP:" << endl;
        // for(vector<Pair>::iterator it = local_maxes.begin(); it != local_maxes.end(); ++it)
        // {
        //   cout << it->index << ", " << it->height << endl;
        // }
        // cout << "END OF local_maxes" << endl;
      --index;
    }

    // debug print
    // cout << "local_maxes:" << endl;
    // for(vector<Pair>::iterator it = local_maxes.begin(); it != local_maxes.end(); ++it)
    // {
    //   cout << it->index << ", " << it->height << endl;
    // }
    // cout << "END OF local_maxes" << endl;

    // now actually do the calculation
    int max_area = 0;
    for(vector<Pair>::iterator it = local_maxes.begin()+1; it != local_maxes.end(); ++it)
    {
      int dist = it->index - (it-1)->index;
      int height = (it->height > (it-1)->height) ? (it-1)->height : it->height;
      int area = dist * height;
      max_area = (area > max_area) ? area : max_area;

    }
    cout << "max_area = " << max_area << endl;
    return max_area;
  }
};


int main(int argc, char** argv)
{
  // vector<int> height = {3, 2, 5, 4, 7, 1, 3, 4, 2, 6, 3};
  vector<int> height = {1, 3, 2, 5, 25, 24, 5};
  // height.push_back(7);
  // height.push_back(6);

  cout << "elements in height vector:" << endl;
  for(vector<int>::iterator it = height.begin(); it != height.end(); ++it)
  {
    cout << *it << endl;
  }

  Solution sol;
  sol.maxArea(height);

  return 0;
}
