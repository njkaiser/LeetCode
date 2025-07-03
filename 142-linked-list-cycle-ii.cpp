// 142. Linked List Cycle II
//
// Given the head of a linked list, return the node where the cycle begins. If
// there is no cycle, return null.
// 
// There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos
// is used to denote the index of the node that tail's next pointer is
// connected to (0-indexed). It is -1 if there is no cycle. Note that pos is
// not passed as a parameter.
// 
// Do not modify the linked list.
//
// 
// Example 1:
//   Input: head = [3,2,0,-4], pos = 1
//   Output: tail connects to node index 1
//   Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//
// Example 2:
//   Input: head = [1,2], pos = 0
//   Output: tail connects to node index 0
//   Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
// Example 3:
//   Input: head = [1], pos = -1
//   Output: no cycle
//   Explanation: There is no cycle in the linked list.
//  
//
// Constraints:
// * The number of the nodes in the list is in the range [0, 104].
// * -105 <= Node.val <= 105
// * pos is -1 or a valid index in the linked-list.
//
// Follow up: Can you solve it using O(1) (i.e. constant) memory?

#include <iostream>
#include <list>
#include <vector>


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* makeList(const std::vector<int>& vals, const int pos) {
  if (vals.empty()) {
    return new ListNode{-1};
  }

  auto* output = new ListNode{vals[0]};
  auto* current_node = output;
  auto* loop_node = output;

  for (int i = 1; i < vals.size(); ++i) {
    const auto& val = vals[i];
    auto* next_node = new ListNode{val};
    current_node->next = next_node;
    current_node = next_node;

    if (pos != -1 && i == pos) {
      loop_node = current_node;
    }
  }


  if (pos != -1) {
    current_node->next = loop_node;
  }
  
  return output;
}


void printList(const ListNode* head, const int n) {
  auto* tmp = head;
  std::cout << "INPUT: [";
  for (int i = 0; i < n; ++i) {
    std::cout << "(" << tmp->val << ", ";
    if (tmp->next == NULL) {
      std::cout << "NULL)";
    } else {
      std::cout << (void*)tmp->next << "), ";
    }
    tmp = tmp->next;
  }
  std::cout << "]" << std::endl;
}


int getIndex(ListNode* head, const int val) {
  int idx = 0;
  auto* tmp = head;
  while (tmp->val != val) {
    ++idx;
    tmp = tmp->next;
  }
  return idx;
}


class Solution {
  public:
    ListNode* detectCycle(ListNode* head) {
      if (!head || !head->next) {
        return NULL;
      }

      auto* ptr1 = head;
      auto* ptr2 = head;

      while (1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr2) {
          ptr2 = ptr2->next;
        }

        // We reached the end of the list without finding a cycle.
        if (!ptr2) {
          return NULL;
        }

        // We found a cycle! Now time to exit and find the node where it starts.
        if (ptr1 == ptr2) {
          break;
        }
      }

      if (ptr2 == head) {
        return head;
      }

      // Reset ptr2, then find where the loop starts.
      ptr2 = head;
      while (1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr1 == ptr2) {
          break;
        }
      }

      return ptr1;
    }
};


int main(int argc, char** argv) {
  //const int pos = 1;
  //const std::vector<int> vals{3, 2, 0, -4};
  //const int pos = 0;
  //const std::vector<int> vals{1, 2};
  //const int pos = -1;
  //const std::vector<int> vals{1};
  //const int pos = 0;
  //const std::vector<int> vals{1, 2, 3, 4};
  const int pos = -1;
  const std::vector<int> vals{21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5};
  auto* head = makeList(vals, pos);

  printList(head, vals.size());
  
  Solution s{};
  const auto answer = s.detectCycle(head);
  if (answer == NULL) {
    std::cout << "NO CYCLE" << std::endl;
  } else {
    const auto idx = getIndex(head, answer->val);
    std::cout << "INDEX: " << idx << ", VAL: " << answer->val << std::endl;
  }

  return 0;
}
