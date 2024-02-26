/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-25 18:42:55
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
 private:
  int number = 0;

 public:
  void dfs(TreeNode* root, long targetSum, int& number) {
    if (!root) return;
    if (root->val == targetSum) {
      number++;
    }
    dfs(root->left, targetSum - root->val, number);
    dfs(root->right, targetSum - root->val, number);
  }

  int pathSum(TreeNode* root, long targetSum) {
    if (root) {
      dfs(root, targetSum, number);
      pathSum(root->left, targetSum);
      pathSum(root->right, targetSum);
    }
    return number;
  }
};

int main(int argc, char** argv) {
  TreeNode root(0, new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                new TreeNode(4, new TreeNode(5), new TreeNode(6)));
  vector<int> ans;
  Solution s;
  s.preorder(&root, ans);
  cout << "Preorder: ";
  for (auto& num : ans) {
    cout << num << " ";
  }
  cout << endl;
  ans.clear();
  s.inorder(&root, ans);
  cout << "inorder: ";
  for (auto& num : ans) {
    cout << num << " ";
  }
  cout << endl;
  ans.clear();
  s.postorder(&root, ans);
  cout << "postorder: ";
  for (auto& num : ans) {
    cout << num << " ";
  }
  cout << endl;
}