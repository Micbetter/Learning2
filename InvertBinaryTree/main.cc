/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 17:19:05
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
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
  TreeNode* dfs(TreeNode* root) {
    if (root == nullptr) return root;
    TreeNode* left = dfs(root->left);
    TreeNode* right = dfs(root->right);
    root->left = right;
    root->right = left;
    return root;
  }

  TreeNode* invertTree(TreeNode* root) { return dfs(root); }
};

int main(int argc, char** argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(4, new TreeNode(5), new TreeNode(6)));
  Solution s;
  TreeNode* node = s.dfs(&root);
  return 1;
}