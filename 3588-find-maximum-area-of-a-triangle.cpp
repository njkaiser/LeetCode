// 3527. Find the Most Common Response
//
// You are given a 2D array coords of size n x 2, representing the coordinates
// of n points in an infinite Cartesian plane.
//
// Find twice the maximum area of a triangle with its corners at any three
// elements from coords, such that at least one side of this triangle is
// parallel to the x-axis or y-axis. Formally, if the maximum area of such a
// triangle is A, return 2 * A.
//
// If no such triangle exists, return -1.
//
// Note that a triangle cannot have zero area.
//
// Example 1:
//
// Input: coords = [[1,1],[1,2],[3,2],[3,3]]
//
// Output: 2
//
// Explanation:
//
//
//
// The triangle shown in the image has a base 1 and height 2. Hence its area is 1/2 * base * height = 1.
//
// Example 2:
//
// Input: coords = [[1,1],[2,2],[3,3]]
//
// Output: -1
//
// Explanation:
//
// The only possible triangle has corners (1, 1), (2, 2), and (3, 3). None of its sides are parallel to the x-axis or the y-axis.
//
//  
//
// Constraints:
//  - 1 <= n == coords.length <= 105
//  - 1 <= coords[i][0], coords[i][1] <= 106
//  - All coords[i] are unique.

//#include <cstring>
#include <iostream>
#include <unordered_map>
#include <unordered_map>
//#include <tuple>
#include <set>
#include <unordered_set>
//#include <set>
//#include <string>
#include <vector>
#include <limits>


class Solution {
  public:
    long long maxArea(std::vector<std::vector<int>>& coords) {
      auto x_min = std::numeric_limits<int>::max();
      auto x_max = 0;
      auto y_min = std::numeric_limits<int>::max();
      auto y_max = 0;

      std::unordered_map<int, std::set<int>> xs;
      std::unordered_map<int, std::set<int>> ys;
      for (const auto& c : coords) {
        const auto& x = c[0];
        const auto& y = c[1];

        xs[x].insert(y);
        ys[y].insert(x);

        if (x < x_min) {
          x_min = x;
        }
        if (x > x_max) {
          x_max = x;
        }
        if (y < y_min) {
          y_min = y;
        }
        if (y > y_max) {
          y_max = y;
        }
      }

      long long max_area_x2 = -1;

      for (const auto& [x, y_vals] : xs) {
        //std::cout << "x, y_vals: " << x;
        //for (const auto& derp : y_vals) {
        //  std::cout << ", " << derp;
        //}
        //std::cout << std::endl;

        if (y_vals.size() < 2) {
          continue;
        }
        const auto y1 = *y_vals.begin();
        const auto y2 = *y_vals.rbegin();
        const auto dx = x - x_min > x_max - x ? x - x_min : x_max - x;
        const long long area = (y2 - y1) * dx;
        if (area != 0 && area > max_area_x2) {
          max_area_x2 = area;
        }
      }

      for (const auto& [y, x_vals] : ys) {
        //std::cout << "y, x_vals: " << y;
        //for (const auto& derp : x_vals) {
        //  std::cout << ", " << derp;
        //}
        //std::cout << std::endl;

        if (x_vals.size() < 2) {
          continue;
        }
        const auto x1 = *x_vals.begin();
        const auto x2 = *x_vals.rbegin();
        const auto dy = y - y_min > y_max - y ? y - y_min : y_max - y;
        const auto area = (x2 - x1) * dy;
        if (area != 0 && area > max_area_x2) {
          max_area_x2 = area;
        }
      }

      return max_area_x2;
    }
};


int main(int argc, char** argv) {
  //std::vector<std::vector<int>> coords{{1, 1}, {1, 2}, {3, 2}, {3, 3}};
  //std::vector<std::vector<int>> coords{{1, 1}, {2, 2}, {3, 3}};
  //std::vector<std::vector<int>> coords{{2, 9}, {2, 6}, {2, 5}};
  //std::vector<std::vector<int>> coords{{5, 3}, {7, 4}, {8, 4}};
  std::vector<std::vector<int>> coords{{20978,57299},{71594,5338},{62296,48595},{61515,79777},{58039,57824},{68650,42862},{89465,11229},{76776,19065},{54604,58311},{35103,41673},{76825,3402},{95512,76348},{32620,2466},{34720,5160},{22151,95150},{70130,82408},{45185,21113},{88760,89054},{73397,58912},{82164,12343},{704,27715},{17175,46320},{3562,85097},{51112,36971},{22408,49},{68376,138},{90572,57168},{80926,958},{60317,84319},{52974,77727},{29067,47634},{37611,16396},{13841,38643},{17618,46044},{44370,28917},{21951,50011},{31665,20306},{22427,80299},{33555,33270},{77313,88531},{30989,93832},{336,92228},{9437,29203},{77046,53102},{9410,36056},{40558,9257},{12360,39902},{921,77920},{17147,5409},{50040,86046},{50040,32353}};

  Solution s{};
  const auto answer = s.maxArea(coords);
  std::cout << "ANSWER: " << answer << std::endl;
  return 0;
}
