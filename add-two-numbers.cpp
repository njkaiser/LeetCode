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
    ListNode output(0);
    ListNode* index = &output;

    int carryover = 0;
    int sum = 0;
    int done1 = 0;
    int done2 = 0;
    while(1)
    {
      int num1, num2;

      if(!done1)
      {
        num1 = l1->val;
      }
      else
      {
        num1 = 0;
      }

      if(!done2)
      {
        num2 = l2->val;
      }
      else
      {
        num2 = 0;
      }

      cout << "sum = num1 + num2 + carryover = " << num1 << " + " << num2 << " + " << carryover << endl;
      sum = num1 + num2 + carryover;
      cout << "carryover = sum / 10 = " << sum << " / 10" << endl;
      carryover = sum / 10;
      cout << "carryover: " << carryover << endl;
      sum %= 10;
      cout << "sum: " << sum << endl;

      index->next = new ListNode(sum);
      index = index->next;
      // index->val = sum;
      cout << sum << endl;

      if(l1->next == NULL && l2->next == NULL)
      {
        cout << l1->next << " and " << l2->next << endl;
        break;
      }

      if(l1->next == NULL)
      {
        done1 = 1;
      }
      else
        l1 = l1->next;

      if(l2->next == NULL)
      {
        done2 = 1;
      }
      else
        l2 = l2->next;

      // l1 = (l1->next == NULL) ? l1 : l1->next;
      // l2 = (l2->next == NULL) ? l2 : l2->next;
    }

    return output.next;
  }
};


int main(int argc, char** argv)
{
  Solution sol;

  // sol.addTwoNumbers()

  cout << "DONE" << endl;
}
