// Given a binary tree, flatten it to a linked list in-place.
//
// For example,
// Given
//
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// click to show hints.
//
// Hints: If you notice carefully in the flattened tree, each node's right child
// points to the next node of a pre-order traversal.

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  vector<TreeNode*> carryover; // basically a stack of carryover branches

  void flatten(TreeNode* root) {
    if(root == NULL) return; // always check for NULL
    recurse(root);
  }

  void recurse(TreeNode* N) {

    // store any carryover (right) branches, then
    // bend all left branches to be on the right
    if(N->right != NULL && N->left != NULL) {
      carryover.push_back(N->right);
    }
    if(N->left != NULL) {
      N->right = N->left;
      N->left = NULL;
    }

    // now work down the right side, since
    // we've already bent beforehand
    if(N->right != NULL) {
      recurse(N->right);
    }
    else if(!carryover.empty()) {
      N->right = carryover.back();
      carryover.pop_back();
      recurse(N->right);
    }

    // if no other conditions triggered, we're done
    return;
  }
};


int main(int argc, char** argv)
{
  // set up tree
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n6 = new TreeNode(6);
  n1->left  = n2;
  n1->right = n5;
  n2->left  = n3;
  n2->right = n4;
  n5->right = n6;

  // run algorithm
  Solution sol;
  sol.flatten(n1);

  // verify solution
  TreeNode* z = n1;
  cout << "FINAL TREE:" << endl;
  while(1) {
    cout << z->val << endl;
    if(z->right == NULL) break;
    z = z->right;
  }

  // clean up memory
  delete n1, n2, n3, n4, n5, n6;

  return 0;
}
