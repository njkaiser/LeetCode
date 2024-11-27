// You have a data structure of employee information, including the employee's
// unique ID, importance value, and direct subordinates' IDs.

// You are given an array of employees employees where:

// employees[i].id is the ID of the ith employee.
// employees[i].importance is the importance value of the ith employee.
// employees[i].subordinates is a list of the IDs of the direct subordinates of
// the ith employee.
//
// Given an integer id that represents an employee's ID, return the total
// importance value of this employee and all their direct and indirect
// subordinates.
//
//
// Example 1
//
// Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
// Output: 11
// Explanation: Employee 1 has an importance value of 5 and has two direct
// subordinates: employee 2 and employee 3.
// They both have an importance value of 3.
// Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.
//
//
// Example 1
// Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
// Output: -3
// Explanation: Employee 5 has an importance value of -3 and has no direct
// subordinates.
// Thus, the total importance value of employee 5 is -3.

#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for Employee.
class Employee {
 public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
 public:
  unordered_map<int, Employee*> makeMap(vector<Employee*> employees) {
    unordered_map<int, Employee*> output;
    for (const auto& e : employees) {
      output[e->id] = e;
    }
    return output;
  }

  //int getImportanceImpl(const unordered_map<int, Employee*>& m, const int id) {
  //  const auto* e = m.find(id)->second;

  //  if (e->subordinates.empty()) {
  //    return e->importance;
  //  }

  //  int subordinate_importance = 0;
  //  for (const auto id : e->subordinates) {
  //    subordinate_importance += getImportanceImpl(m, id);
  //  }
  //  return e->importance + subordinate_importance;
  //}

  int getImportance(vector<Employee*> employees, int id) {
    const auto m = makeMap(employees);
    //return getImportanceImpl(m, id);

    queue<int> q{{id}};
    int total_importance = 0;
    while (!q.empty()) {
      const auto& curr_id = q.front();
      total_importance += m.find(curr_id)->second->importance;
      for (const auto& s_id : m.find(curr_id)->second->subordinates) {
        q.emplace(s_id);
      }
      q.pop();
    }
    return total_importance;
  }
};

int main(int argc, char** argv) {
  Employee a{};
  a.id = 1;
  a.importance = 2;
  a.subordinates = {5};

  Employee b{};
  b.id = 5;
  b.importance = -3;
  b.subordinates = {};

  vector<Employee*> employees{&a, &b};
  int id = 1;

  //Employee a{};
  //a.id = 1;
  //a.importance = 5;
  //a.subordinates = {2, 3};

  //Employee b{};
  //b.id = 2;
  //b.importance = 3;
  //b.subordinates = {};

  //Employee c{};
  //c.id = 3;
  //c.importance = 3;
  //c.subordinates = {};

  //vector<Employee*> employees{&a, &b, &c};
  //int id = 1;

  Solution s;
  const auto answer = s.getImportance(employees, id);
  cout << "Importance for employee " << id << ": " << answer << endl;
}
