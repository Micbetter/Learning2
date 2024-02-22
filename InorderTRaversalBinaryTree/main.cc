/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 17:58:53
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
  void dfs(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left, ans);
    ans.push_back(root->val);
    dfs(root->right, ans);
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
  }
};

int main(int argc, char** argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(4, new TreeNode(5), new TreeNode(6)));
  Solution s;
  vector<int> ans = s.inorderTraversal(&root);
  for (auto& num : ans) {
    cout << num << " ";
  }
  cout << endl;
  return 1;
}