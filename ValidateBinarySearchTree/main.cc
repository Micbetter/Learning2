/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 22:02:03
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
  bool innode(TreeNode* node, vector<int>& nums) {
    if (node == nullptr) return true;
    if (!innode(node->left, nums)) return false;
    nums.push_back(node->val);
    int n = nums.size();
    if (n > 1 && nums[n - 1] < nums[n - 2]) return false;
    if (!innode(node->right, nums)) return false;
    return true;
  }

  bool helper(TreeNode* node, int min, int max) {
    if (node == nullptr) return true;
    if (node->val <= min || node->val >= max) {
      return false;
    }
    return helper(node->left, min, node->val) &&
           helper(node->right, node->val, max);
  }

  bool isValidBST(TreeNode* root) {
    // innode traversal
    vector<int> nums;
    innode(root, nums);
    // prenode traversal
    int min = numeric_limits<int>::min();
    int max = numeric_limits<int>::max();
    return helper(root, min, max);
  }
};

int main(int argc, char** argv) {
  TreeNode* test = new TreeNode(1, nullptr, new TreeNode(2));
  Solution s;
  auto ans = s.isValidBST(test);
  cout << ans << endl;

  return 1;
}