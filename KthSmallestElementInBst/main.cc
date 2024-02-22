/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 22:21:07
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
  void innode(TreeNode* node, vector<int>& nums, int k) {
    int n = nums.size();
    if (n > k) {
      return;
    }
    if (node == nullptr) return;
    innode(node->left, nums, k);
    if (n > k) {
      return;
    }
    nums.push_back(node->val);
    if (n > k) {
      return;
    }
    innode(node->right, nums, k);
    return;
  }

  int kthSmallest(TreeNode* root, int k) {
    vector<int> nums;
    innode(root, nums, k);
    return nums[k - 1];
  }
};

int main(int argc, char** argv) {
  TreeNode* test = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)),
                                new TreeNode(5));
  Solution s;
  auto ans = s.kthSmallest(test, 2);
  cout << ans << endl;

  return 1;
}