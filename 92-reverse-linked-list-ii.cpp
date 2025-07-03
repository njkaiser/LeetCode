// 92. Reverse Linked List II
//
// Given the head of a singly linked list and two integers left and right where
// left <= right, reverse the nodes of the list from position left to position
// right, and return the reversed list.
//
// 
// Example 1:
//  Input: head = [1,2,3,4,5], left = 2, right = 4
//  Output: [1,4,3,2,5]
//
//
// Example 2:
//  Input: head = [5], left = 1, right = 1
//  Output: [5]
//  
//
// Constraints:
// * The number of nodes in the list is n.
// * 1 <= n <= 500
// * -500 <= Node.val <= 500
// * 1 <= left <= right <= n
//   
// Follow up: Could you do it in one pass?

#include <iostream>
#include <list>
#include <vector>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* makeList(const std::vector<int>& vals) {
  //if (vals.empty()) {
  //  return new ListNode{-1};
  //}

  auto* output = new ListNode{vals[0]};
  auto* current_node = output;

  for (int i = 1; i < vals.size(); ++i) {
    const auto& val = vals[i];
    auto* next_node = new ListNode{val};
    current_node->next = next_node;
    current_node = next_node;
  }

  return output;
}


void printList(const std::string& prefix, const ListNode* head, const int n) {
  auto* tmp = head;
  std::cout << prefix << "[";
  for (int i = 0; i < n; ++i) {
    std::cout << tmp->val;
    if (i != n - 1) {
      std::cout << ", ";
    }
    tmp = tmp->next;
  }
  std::cout << "]" << std::endl;
}


class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      // Early exit condition.
      if (left == right) {
        return head;
      }

      auto* a = head;
      for (int i = 0; i < left - 1; ++i) {
        a = a->next;
      }

      int dist = right - left;
      while (1) {
        auto* b = a;
        for (int j = 0; j < dist; ++j) {
          b = b->next;
        }

        std::cout << "swapping " << a->val << " and " << b->val << std::endl;
        std::swap(a->val, b->val);
        a = a->next;
        dist -= 2;
        if (dist < 1) {
          break;
        }
      }

      return head;
    }
};


int main(int argc, char** argv) {
  int left = 2;
  int right = 4;
  const std::vector<int> vals{1,2,3,4,5};

  //int left = 2;
  //int right = 6;
  //const std::vector<int> vals{1,2,3,4,5,6,7,8};

  //int left = 1;
  //int right = 1;
  //const std::vector<int> vals{5};

  //int left = 1;
  //int right = 2;
  //const std::vector<int> vals{1,2};

  //int left = 1;
  //int right = 4;
  //const std::vector<int> vals{1,2,3,4};

  std::cout << "reversing between " << left << " and " << right << std::endl;
  auto* head = makeList(vals);
  printList(" INPUT: ", head, vals.size());
  
  Solution s{};
  const auto answer = s.reverseBetween(head, left, right);
  printList("ANSWER: ", answer, vals.size());

  return 0;
}
