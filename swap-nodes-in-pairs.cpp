// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the
// values in the list, only nodes itself can be changed.

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) { }
};


class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if(head == NULL) { return head; } // nothing to swap here
    if(head->next == NULL) { return head; } // nothing to swap here
    ListNode* temp;
    ListNode* A = head;
    ListNode* B = head->next;
    head = B;
    while(1) {
      temp = B->next;
      B->next = A;
      if(temp == NULL) {
        // cout << "case 1:" << endl;
        // cout << "linking " << B << " (" << B->val << ") to " << A << " (" << A->val << ")" << endl;
        A->next = NULL;
        break;
      }
      else if (temp->next == NULL) {
        // cout << "case 2:" << endl;
        // cout << "linking " << A << " (" << A->val << ") to " << A->next->next->next << " (" << temp->next->val << ")" << endl;
        A->next = temp;
        break;
      }
      else {
        // cout << "case 3:" << endl;
        // cout << "linking " << A << " (" << A->val << ") to " << A->next->next->next << " (" << temp->next->val << ")" << endl;
        A->next = temp->next;
        A = temp;
        B = A->next;
      }
    }
    return head;
  }
};


int main(int argc, char** argv)
{
  ListNode A(1);
  ListNode B(2);
  ListNode C(3);
  ListNode D(4);
  // ListNode E(5);
  A.next = &B;
  B.next = &C;
  C.next = &D;
  // D.next = &E;

  cout << "ORIGINAL:" << endl;
  ListNode* curr = &A;
  while(1) {
    cout << curr->val << endl;
    if(curr->next == NULL) { break; }
    curr = curr->next;
  }

  Solution sol;
  ListNode * answer = sol.swapPairs(&A);

  cout << "answer = " << endl;
  curr = answer;
  while(1) {
    cout << curr->val << endl;
    if(curr->next == NULL) { break; }
    curr = curr->next;
  }

  cout << "DONE" << endl;
  return 0;
}
