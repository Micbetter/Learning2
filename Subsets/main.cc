/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-01 14:05:46
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

class Solution {
 public:
  void dfs(vector<vector<int>>& res, vector<int>& output, vector<int>& nums,
           int index) {
    if (index >= nums.size()) {
      res.push_back(output);
      return;
    }
    // add current node
    output.push_back(nums[index]);
    // dfs next node with current node
    dfs(res, output, nums, index + 1);
    // do not add the current node
    output.pop_back();
    // dfs next node without current node
    dfs(res, output, nums, index + 1);
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> output;
    dfs(res, output, nums, 0);
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, 3};
  Solution s;
  auto res = s.subsets(test);
  for (auto& nums : res) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }
  return 1;
}