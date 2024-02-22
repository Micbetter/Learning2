/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 20:59:36
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
  TreeNode* helper(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int middle = l + (r - l) / 2;
    TreeNode* node = new TreeNode(nums[middle]);
    node->left = helper(nums, l, middle - 1);
    node->right = helper(nums, middle + 1, r);
    return node;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, 3, 4, 5};
  Solution s;
  TreeNode* ans = s.sortedArrayToBST(test);

  return 1;
}