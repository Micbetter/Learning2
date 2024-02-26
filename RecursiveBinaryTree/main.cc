/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-25 17:12:38
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
  void preorder(TreeNode* root, vector<int>& res) {
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (!stk.empty() || node != nullptr) {
      while (node != nullptr) {
        stk.push(node);
        res.push_back(node->val);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      node = node->right;
    }
  }
  void inorder(TreeNode* root, vector<int>& res) {
    TreeNode* node = root;
    stack<TreeNode*> stk;
    while (!stk.empty() || node != nullptr) {
      while (node != nullptr) {
        stk.push(node);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      res.push_back(node->val);
      node = node->right;
    }
  }
  void postorder(TreeNode* root, vector<int>& res) {
    stack<TreeNode*> stk;
    TreeNode* prev = nullptr;
    TreeNode* node = root;
    while (!stk.empty() || node != nullptr) {
      while (node != nullptr) {
        stk.push(node);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      if (node->right == nullptr || node->right == prev) {
        res.push_back(node->val);
        prev = node;
        node = nullptr;
      } else {
        stk.push(node);
        node = node->right;
      }
    }
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