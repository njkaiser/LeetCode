// 200. Number of Islands
//
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands.
// 
// An island is surrounded by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four edges of the grid are
// all surrounded by water.
// 
//  
// Example 1:
//   Input: grid =
//    [['1','1','1','1','0'],
//     ['1','1','0','1','0'],
//     ['1','1','0','0','0'],
//     ['0','0','0','0','0']]
//
//   Output: 1
//
//
// Example 2:
//   Input: grid =
//    [['1','1','0','0','0'],
//     ['1','1','0','0','0'],
//     ['0','0','1','0','0'],
//     ['0','0','0','1','1']]
//
//   Output: 3
//  
// 
// Constraints:
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 300
//  * grid[i][j] is '0' or '1'.

#include <iostream>
#include <array>
#include <unordered_set>
#include <string>
#include <vector>


void printGrid(const std::vector<std::vector<char>>& grid) {
  const int m = grid.size();
  const int n = grid[0].size();

  for (int i = 0; i < m; ++i) {
    std::cout << "[";
    for (int j = 0; j < n; ++j) {
      std::cout << grid[i][j] << ", ";
    }
    std::cout << "]" << std::endl;
  }
}

class Solution {
  public:

    void bfs(
        const int i,
        const int j,
        std::vector<std::vector<char>>& grid) {
      const int m = grid.size();
      const int n = grid[0].size();

      const std::array<int, 8> neighboring_indices{i-1, j, i+1, j, i, j-1, i, j+1};
      for (int k = 0; k < 4; ++k) {
        const int a = neighboring_indices[2 * k];
        const int b = neighboring_indices[2 * k + 1];

        // Check we don't go out of bounds.
        if (a < 0 || a > m - 1 || b < 0 || b > n - 1) {
          continue;
        }

        if (grid[a][b] == '1') {
          grid[a][b] = 'x';
          //std::cout << "BFS processing: " << a << ", " << b << std::endl;
          //printGrid(grid);
          bfs(a, b, grid);
        }
      }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
      const int m = grid.size();
      const int n = grid[0].size();

      int num_islands = 0;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 'x') {
            continue;
          }

          if (grid[i][j] == '1') {
            //std::cout << "found a 1 at: " << i << ", " << j << std::endl;
            grid[i][j] = 'x'; // special case when island size is 1
            bfs(i, j, grid);
            num_islands++;
          }
        }
      }

      return num_islands;
    }
};


int main(int argc, char** argv) {
  //std::vector<std::vector<char>> grid{{'1','1','1','1','0'},
  //                                    {'1','1','0','1','0'},
  //                                    {'1','1','0','0','0'},
  //                                    {'0','0','0','0','0'}};

  std::vector<std::vector<char>> grid{{'1','1','0','0','0'},
                                      {'1','1','0','0','0'},
                                      {'0','0','1','0','0'},
                                      {'0','0','0','1','1'}};

  std::cout << "=== ORIGINAL ===:" << std::endl;
  printGrid(grid);
  std::cout << "================" << std::endl << std::endl;

  Solution s;
  const auto answer = s.numIslands(grid);
  std::cout << "===== DONE =====:" << std::endl;
  printGrid(grid);
  std::cout << "================" << std::endl << std::endl;
  std::cout << "ANSWER: " << answer << std::endl;

  return EXIT_SUCCESS;
}
