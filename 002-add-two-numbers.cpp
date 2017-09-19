// You are given two non-empty linked lists representing two
// non-negative integers. The digits are stored in reverse order
// and each of their nodes contain a single digit. Add the two
// numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero,
// except the number 0 itself.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    int carryover = 0;
    ListNode* output = new ListNode(-1);
    ListNode* next = output;
    ListNode* curr;
    while(l1 && l2) {

      curr = next;
      int sum = l1->val + l2->val + carryover;
      curr->val = sum % 10;
      carryover = sum / 10;
      // cout << "sum: " << sum << ", val: " << curr->val << ", carryover: " << carryover << endl;

      // reached the end of both numbers, rage quit
      if(l1->next == NULL && l2->next == NULL && carryover == 0) { break; }

      // else check conditions and keep going
      if(l1->next != NULL) { l1 = l1->next; }
      // else { cout << "l1 is at the end" << endl; l1->val = 0; }
      else { l1->val = 0; }
      if(l2->next != NULL) { l2 = l2->next; }
      // else { cout << "l2 is at the end" << endl; l2->val = 0; }
      else { l2->val = 0; }

      next = new ListNode(-1);
      curr->next = next;
      // cout << "got here" << endl;
    }
    return output;
  }
};


int main(int argc, char** argv)
{
  // set up inputs
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(9);
  ListNode* c = new ListNode(9);
  a->next = b;
  b->next = c;

  ListNode* d = new ListNode(9);
  ListNode* e = new ListNode(6);
  ListNode* f = new ListNode(4);
  // d->next = e;
  // e->next = f;

  // calculate solution
  Solution sol;
  ListNode* answer = sol.addTwoNumbers(a, d);
  cout << "answer: " << endl;
  while(answer) {
    cout << answer->val;
    if(answer->next != NULL) {
      answer = answer->next;
      cout << " -> ";
    }
    else {
      break; // we're done
    }
  }
  cout << endl;

  // clean up
  delete a; delete b; delete c; delete d; delete e; delete f;
  // should also free solution pointers here, do if time

  cout << "DONE" << endl;
  return 0;
}
