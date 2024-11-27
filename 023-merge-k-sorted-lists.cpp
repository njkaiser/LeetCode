// 23. Merge k Sorted Lists
//
// You are given an array of k linked-lists lists, each linked-list is sorted
// in ascending order. Merge all the linked-lists into one sorted linked-list
// and return it.
//
// Example 1:
//   Input: lists = [[1,4,5],[1,3,4],[2,6]]
//   Output: [1,1,2,3,4,4,5,6]
//   Explanation: The linked-lists are:
//   [
//     1->4->5,
//     1->3->4,
//     2->6
//   ]
//   merging them into one sorted list:
//   1->1->2->3->4->4->5->6
//
// Example 2:
// 
//   Input: lists = []
//   Output: []
//
// Example 3:
// 
//   Input: lists = [[]]
//   Output: []
// 
// Constraints:
//  * k == lists.length
//  * 0 <= k <= 10^4
//  * 0 <= lists[i].length <= 500
//  * -10^4 <= lists[i][j] <= 10^4
//  * lists[i] is sorted in ascending order.
//  * The sum of lists[i].length will not exceed 10^4.

#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct NodeLessThan {
  bool operator()(const ListNode* a, const ListNode* b) {
    if (a == nullptr) {
      return true;
    }
    if (b == nullptr) {
      return false;
    }
    return a->val > b->val;
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, vector<ListNode*>, NodeLessThan> q{};
    for (const auto l : lists) {
      auto it = l;
      while (it != nullptr) {
        cout << "here 0: " << it->val << endl;
        q.emplace(it);
        it = it->next;
      }
    }

    cout << "here 1: " << q.size() << endl;
    if (q.empty()) {
      return nullptr;
    }

    if (q.top() == nullptr) {
      return nullptr;
    }

    cout << "here 2: " << q.top()->val << endl;
    ListNode* output = q.top();
    q.pop();

    auto it = output;
    while (!q.empty() && q.top() != nullptr) {
      cout << "here 4: " << q.top()->val << endl;
      it->next = q.top();
      it = it->next;
      q.pop();
    }
    it->next = nullptr;

    return output;
  }
};

int main(int argc, char** argv) {
  // ListNode l1_3{5};
  // ListNode l1_2{4, &l1_3};
  // ListNode l1_1{1, &l1_2};

  // ListNode l2_3{4};
  // ListNode l2_2{3, &l2_3};
  // ListNode l2_1{1, &l2_2};

  // ListNode l3_2{6};
  // ListNode l3_1{2, &l3_2};

  // ListNode l4_1{};

  // vector<ListNode*> input{&l1_1, &l2_1, &l3_1, &l4_1, nullptr};

  // [[-1,-1,-1],[-2,-2,-1]]

  ListNode l1_3{-1};
  ListNode l1_2{-1, &l1_3};
  ListNode l1_1{-1, &l1_2};

  ListNode l2_3{-1};
  ListNode l2_2{-2, &l2_3};
  ListNode l2_1{-2, &l2_2};

  vector<ListNode*> input{&l1_1, &l2_1};

  // vector<ListNode*> input{nullptr};

  cout << "derp" << endl;
  Solution s;
  auto node = s.mergeKLists(input);

  cout << "answer = [";
  while (node != nullptr) {
    cout << node->val << ", ";
    node = node->next;
  }
  cout << "]" << endl;

  return EXIT_SUCCESS;
}
