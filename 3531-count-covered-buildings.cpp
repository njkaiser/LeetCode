// 3531. Count Covered Buildings
//
// You are given a positive integer n, representing an n x n city. You are also
// given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique
// building located at coordinates [x, y].
//
// A building is covered if there is at least one building in all four
// directions: left, right, above, and below.
//
// Return the number of covered buildings.
//
//
// Example 1:
//  Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
//
//  Output: 1
//
//  Explanation:
//
//  Only building [2,2] is covered as it has at least one building:
//  above ([1,2])
//  below ([3,2])
//  left ([2,1])
//  right ([2,3])
//  Thus, the count of covered buildings is 1.
//
//
// Example 2:
//  Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]
//
//  Output: 0
//
//  Explanation:
//
//  No building has at least one building in all four directions.
//
//
// Example 3:
//  Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]
//
//  Output: 1
//
//  Explanation:
//
//  Only building [3,3] is covered as it has at least one building:
//  above ([1,3])
//  below ([5,3])
//  left ([3,2])
//  right ([3,5])
//  Thus, the count of covered buildings is 1.
//   
//
// Constraints:
//  - 2 <= n <= 105
//  - 1 <= buildings.length <= 105 
//  - buildings[i] = [x, y]
//  - 1 <= x, y <= n
//  - All coordinates of buildings are unique.

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>


class Solution {
  public:
    int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings) {
      std::unordered_map<int, std::array<int, 2>> x_to_ys_map;
      std::unordered_map<int, std::array<int, 2>> y_to_xs_map;

      for (const auto& coord : buildings) {
        const auto x = coord[0];
        if (!x_to_ys_map.count(x)) {
          x_to_ys_map[x] = {n, 0};
        }

        const auto y = coord[1];
        if (!y_to_xs_map.count(y)) {
          y_to_xs_map[y] = {n, 0};
        }

        x_to_ys_map[x][0] = std::min(y, x_to_ys_map[x][0]);
        x_to_ys_map[x][1] = std::max(y, x_to_ys_map[x][1]);
        y_to_xs_map[y][0] = std::min(x, y_to_xs_map[y][0]);
        y_to_xs_map[y][1] = std::max(x, y_to_xs_map[y][1]);
      }

      int count = 0;
      for (const auto& coord : buildings) {
        const auto x = coord[0];
        const auto y = coord[1];
        if (y > x_to_ys_map[x][0] && y < x_to_ys_map[x][1] && x > y_to_xs_map[y][0] && x < y_to_xs_map[y][1]) {
          ++count;
        }
      }

      return count;
    }
};


int main(int argc, char** argv) {
  //const int n = 3;
  //std::vector<std::vector<int>> buildings{{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};

  //const int n = 3;
  //std::vector<std::vector<int>> buildings{{1, 1}, {1, 2}, {2, 1}, {2, 2}};
  
  const int n = 5;
  std::vector<std::vector<int>> buildings{{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};

  Solution s{};
  const auto answer = s.countCoveredBuildings(n, buildings);
  std::cout << "ANSWER: " << answer << std::endl;
  return 0;
}
