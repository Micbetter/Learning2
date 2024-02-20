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
          if (node->left != nullptr) {
            nodes.push(node->left);
          }
          if (node->right != nullptr) {
            nodes.push(node->right);
          }
        }
      }
      res.push_back(tmp);
    }
    return res;
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