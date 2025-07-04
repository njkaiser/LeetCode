// 210. Course Schedule II
//
// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i]
// = [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to
// first take course 1.
//
// Return the ordering of courses you should take to finish all courses. If
// there are many valid answers, return any of them. If it is impossible to
// finish all courses, return an empty array.
//  
//
// Example 1:
//  Input: numCourses = 2, prerequisites = [[1,0]]
//  Output: [0,1]
//  Explanation: There are a total of 2 courses to take. To take course 1 you
//               should have finished course 0. So the correct course order is
//               [0,1].
//
//
// Example 2:
//  Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//  Output: [0,2,1,3]
//  Explanation: There are a total of 4 courses to take. To take course 3 you
//               should have finished both courses 1 and 2. Both courses 1 and
//               2 should be taken after you finished course 0. So one correct
//               course order is [0,1,2,3]. Another correct ordering is
//               [0,2,1,3].
//
//
// Example 3:
//  Input: numCourses = 1, prerequisites = []
//  Output: [0]
//   
//
// Constraints:
// * 1 <= numCourses <= 2000
// * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// * prerequisites[i].length == 2
// * 0 <= ai, bi < numCourses
// * ai != bi
// * All the pairs [ai, bi] are distinct.

#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <vector>


template <typename T>
void printVector(const std::string& prefix, const std::vector<T>& v) {
  std::cout << prefix << "[";
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    if (it == v.cend() - 1) {
      std::cout << *it;
    } else {
      std::cout << *it << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

void printMap(const std::string& prefix, const std::unordered_map<int, std::vector<int>>& deps) {
  std::cout << prefix << ": {";
  for (const auto pair : deps) {
    const auto& c = pair.first;
    const auto& ds = pair.second;
    std::cout << c << ": [";
    for (const auto d : ds) {
      std::cout << d << ",";
    }
    std::cout << "], ";
  }
  std::cout << "}" << std::endl;
}

class Solution {
  public:

    std::unordered_map<int, std::vector<int>> buildDepGraph(std::vector<std::vector<int>>& prereqs) {
      std::unordered_map<int, std::vector<int>> deps;
      for (const auto& p : prereqs) {
        if (deps.count(p[0])) {
          deps[p[0]].push_back(p[1]);
        } else {
          deps[p[0]] = {p[1]};
        }
      }
      printMap("DEPS", deps);
      return deps;
    }

    bool dfs(const int c,
             const std::unordered_map<int, std::vector<int>>& deps, 
             std::unordered_set<int>& visited,
             std::unordered_set<int>& visiting,
             std::vector<int>& output) {
      std::cout << "processing: " << c << std::endl;
      // Already visited, exit early.
      if (visited.count(c)) {
        std::cout << "already processed: " << c << std::endl;
        return true;
      }

      // Cycle check.
      if (visiting.count(c)) {
        std::cout << "cycle found for: " << c << std::endl;
        return false;
      }

      // Leaf node check.
      if (!deps.count(c)) {
        visiting.erase(c);
        visited.insert(c);
        output.push_back(c);
        std::cout << "leaf node: " << c << std::endl;
        return true;
      }

      // Do DFS on this course's deps.
      visiting.insert(c);
      std::cout << "processing deps for: " << c << std::endl;
      if (deps.count(c)) {
        for (const auto& d : deps.at(c)) {
          std::cout << "processing dep: " << d << std::endl;
          if (!dfs(d, deps, visited, visiting, output)) {
            return false;
          }
        }
      }

      // We've processed all of this course's deps, we can add it + return;
      visiting.erase(c);
      visited.insert(c);
      output.push_back(c);
      return true;
    }

    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
      const auto deps = buildDepGraph(prerequisites);
      std::unordered_set<int> visited;
      std::unordered_set<int> visiting;
      std::vector<int> output;

      for (int c = 0; c < numCourses; ++c) {
        if (visited.count(c)) {
          continue;
        }

        const bool success = dfs(c, deps, visited, visiting, output);
        if (!success) {
          return {};
        }
      }

      return output;
    }
};


int main(int argc, char** argv) {
  //int num_courses = 2;
  //std::vector<std::vector<int>> prerequisites = {{1, 0}};

  int num_courses = 4;
  std::vector<std::vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};

  //int num_courses = 1;
  //std::vector<std::vector<int>> prerequisites = {};

  Solution s;
  const auto answer = s.findOrder(num_courses, prerequisites);
  printVector("ANSWER: ", answer);

  return EXIT_SUCCESS;
}
