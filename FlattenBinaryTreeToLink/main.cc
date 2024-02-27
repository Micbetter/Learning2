/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-25 15:39:05
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
  pair<TreeNode*, TreeNode*> dfs(TreeNode* node) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (!node->left && !node->right) {
      return {node, node};
    } else if (!node->left && node->right) {
      auto res = dfs(node->right);
      node->right = res.first;
      return {node, res.second};
    } else if (node->left && !node->right) {
      auto res = dfs(node->left);
      node->right = res.first;
      node->left = nullptr;
      return {node, res.second};
    } else {
      auto res1 = dfs(node->left);
      auto res2 = dfs(node->right);
      node->right = res1.first;
      node->left = nullptr;
      res1.second->right = res2.first;
      return {node, res2.second};
    }
  }
  void flatten(TreeNode* root) { dfs(root); }
};

int main(int argc, char** argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(4, new TreeNode(5), new TreeNode(6)));
  Solution s;
  s.flatten(&root);

  return 1;
}