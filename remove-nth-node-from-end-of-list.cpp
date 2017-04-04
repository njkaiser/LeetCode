// Given a linked list, remove the nth node from the end of list and return its head.
// For example,
//    Given linked list: 1->2->3->4->5, and n = 2.
//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.

#include <iostream>
#include <limits>


using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* currnode = head;
    ListNode* nodetochange = head;
    ListNode* nodetojoin = head;
    int index = 0;
    while(1) {
      // cout << currnode->val << endl;
      if(index >= n+1) {
        nodetochange = nodetochange->next;
      }
      if(index >= n-1) {
        if(nodetojoin->next) {
          nodetojoin = nodetojoin->next;
        }
      }
      // cout << "nodetochange->val: " << nodetochange->val << endl;
      // cout << "nodetojoin->val: " << nodetojoin->val << endl;
      if(!currnode->next) { break; }
      currnode = currnode->next;
      ++index;
    }
    // cout << "nodetochange: " << nodetochange << endl;
    // cout << "nodetojoin: " << nodetojoin << endl;
    // cout << "nodetochange->val: " << nodetochange->val << endl;
    // cout << "nodetojoin->val: " << nodetojoin->val << endl;
    // cout << "n, index: " << n << ", " << index << endl;
    if(nodetochange == nodetojoin) {
      ListNode** x = &head;
      *x = (*x)->next;
    }
    else if(n == 1) {
      nodetochange->next = NULL;
    }
    else if(index == n-1) {
      head = head->next;
    }
    else {
      nodetochange->next = nodetojoin;
    }

    return head;
  }
};


int main(int argc, char** argv)
{
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);
  // ListNode a(5);
  // ListNode b(10);
  // ListNode c(15);
  // ListNode d(20);
  a.next = &b;
  b.next = &c;
  // c.next = &d;

  // ListNode single(1);

  cout << "INITIAL VALUES:" << endl;
  ListNode *foo = &a;
  while(1) {
    cout << foo->val << endl;
    if(!foo->next) { break; }
    foo = foo->next;
  }

  Solution sol;
  ListNode *bar = sol.removeNthFromEnd(&a, 1);
  cout << "FINAL SOLUTION:" << endl;
  while(1) {
    cout << bar->val << endl;
    if(!bar->next) { break; }
    bar = bar->next;
  }
}
