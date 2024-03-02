/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-02 18:25:20
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 && inorder.size() == 0) {
      return nullptr;
    }
    int root_node = preorder[0];
    TreeNode* root = new TreeNode(root_node);
    for (int i = 0; i < inorder.size(); i++) {
      // find root node in inorder array
      if (inorder[i] == root_node) {
        // left tree
        vector<int> new_pre_left =
            vector<int>(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> new_pre_right =
            vector<int>(preorder.begin() + i + 1, preorder.end());
        vector<int> new_in_left =
            vector<int>(inorder.begin(), inorder.begin() + i);
        vector<int> new_in_right =
            vector<int>(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(new_pre_left, new_in_left);
        root->right = buildTree(new_pre_right, new_in_right);
      }
    }
    return root;
  }
};

int main(int argc, char** argv) {
  vector<int> left = {3, 9, 20, 15, 7};
  vector<int> right = {9, 3, 15, 20, 7};
  Solution s;
  TreeNode* ans = s.buildTree(left, right);
  return 1;
}