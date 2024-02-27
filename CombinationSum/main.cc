/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-25 11:04:10
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

class Solution {
 public:
  void backtrace(vector<int>& candidates, vector<vector<int>>& res,
                 vector<int>& output, int start, int target) {
    if (target == 0) {
      res.push_back(output);
      return;
    }
    if (start >= candidates.size()) {
      return;
    }
    backtrace(candidates, res, output, start + 1, target);
    if (target - candidates[start] >= 0) {
      output.push_back(candidates[start]);
      backtrace(candidates, res, output, start, target - candidates[start]);
      output.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> output;
    backtrace(candidates, res, output, 0, target);
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {2, 3, 6, 7};
  Solution s;
  auto res = s.combinationSum(test, 7);
  for (auto& nums : res) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }

  return 1;
}