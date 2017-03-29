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
    vector<Pair> local_maxes;
    Pair tmp;

    vector<int>::iterator global_max_f = max_element(height.begin(), height.end());
    cout << "max element, index:" << endl;
    cout << *global_max_f << endl;
    cout << distance(height.begin(), global_max_f) << endl;


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
    const vector<Pair>::iterator insert_loc = local_maxes.end();
    index = height.size()-1;
    lowest = -1;
    for(vector<int>::iterator rit = height.end()-1; rit != global_max_f; --rit)
    {
      if(*rit > lowest)
        {
          tmp.index = index;
          tmp.height = *rit;
          local_maxes.insert(insert_loc, tmp);
          lowest = *rit;
        }
      --index;
    }

    // debug print
    // cout << "local_maxes:" << endl;
    // for(vector<Pair>::iterator it = local_maxes.begin(); it != local_maxes.end(); ++it)
    // {
    //   cout << it->height << ", " << it->index << endl;
    // }

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
  vector<int> height;
  height.push_back(3);
  height.push_back(2);
  height.push_back(5);
  height.push_back(4);
  height.push_back(7);
  height.push_back(1);
  height.push_back(3);
  height.push_back(4);
  height.push_back(2);
  height.push_back(6);
  height.push_back(3);
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
