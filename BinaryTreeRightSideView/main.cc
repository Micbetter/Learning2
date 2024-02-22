/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 22:23:08
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 23:46:02
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
      int n = nodes.size();
      vector<int> tmp;
      for (int i = 0; i < n; i++) {
        TreeNode *node = nodes.front();
        nodes.pop();
        if (node != nullptr) {
          tmp.push_back(node->val);
          if (node->left) {
            nodes.push(node->left);
          }
          if (node->right) {
            nodes.push(node->right);
          }
        }
      }
      res.push_back(tmp);
    }
    return res;
  }

  vector<int> rightSideView(TreeNode *root) {
    vector<vector<int>> res = levelOrder(root);
    vector<int> ans;
    for (auto &row : res) {
      ans.push_back(row[row.size() - 1]);
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(4, new TreeNode(5), new TreeNode(6)));
  Solution s;
  auto ans = s.rightSideView(&root);

  for (auto num : ans) {
    std::cout << num << " " << std::endl;
  }
  std::cout << std::endl;

  return 1;
}