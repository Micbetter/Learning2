/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 17:42:22
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
  bool dfs(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
      return true;
    } else if (left != nullptr && right != nullptr) {
      if (left->val != right->val) return false;
      return dfs(left->left, right->right) && dfs(left->right, right->left);
    } else {
      return false;
    }
  }
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
      return false;
    }
    return dfs(root->left, root->right);
  }
};

int main(int argc, char** argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(1, new TreeNode(3), new TreeNode(2)));
  Solution s;
  cout << s.isSymmetric(&root) << endl;
  return 1;
}