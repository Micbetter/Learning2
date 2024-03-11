/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-03-08 10:32:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-08 10:56:43
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
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
 private:
  int max_sum = numeric_limits<int>::min();

 public:
  int maxNode(TreeNode *node) {
    if (!node) return 0;
    int left = max(0, maxNode(node->left));
    int right = max(0, maxNode(node->right));
    max_sum = max(max_sum, node->val + left + right);
    return node->val + max(left, right);
  }

  int maxPathSum(TreeNode *root) {
    maxNode(root);
    return max_sum;
  }
};

int main(int argc, char **argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(4, new TreeNode(5), new TreeNode(6)));
  Solution s;
  auto ans = s.levelOrder(&root);
  for (auto &nums : ans) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }

  return 1;
}