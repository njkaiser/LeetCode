// Given a binary tree, return the inorder traversal of its nodes' values.
//
// For example:
// Given binary tree [1,null,2,3],
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].
//
// Note: Recursive solution is trivial, could you do it iteratively?

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
  vector<int> sol;
  vector<int> inorderTraversal(TreeNode* root) {
    if(root == NULL) { return sol; } // handle base case of null tree
    if(root->left != NULL) { inorderTraversal(root->left); }
    sol.push_back(root->val);
    if(root->right != NULL) { inorderTraversal(root->right); }
    return sol;
  }
};


int main(int argc, char** argv)
{
  TreeNode *root = new TreeNode(1);
  TreeNode *one = new TreeNode(2);
  TreeNode *two = new TreeNode(3);
  root->right = one;
  one->left = two;

  Solution sol;
  vector<int> answer = sol.inorderTraversal(root);
  cout << "answer:" << endl;
  for(int i = 0; i < answer.size(); i++) {
    cout << answer[i] << ", ";
  }
  cout << endl;

  delete root, one, two;

  cout << "DONE" << endl;
  return 0;
}
