/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 16:31:07
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
  int dfs(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    return max(left, right) + 1;
  }
  int maxDepth(TreeNode* root) { return dfs(root); }
};

int main(int argc, char** argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(4, new TreeNode(5), new TreeNode(6)));
  Solution s;
  cout << s.maxDepth(&root) << endl;
}