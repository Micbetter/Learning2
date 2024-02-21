/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 09:40:59
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 10:51:54
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序
//返回答案。

class Solution {
 public:
  void backtrace(vector<vector<int>>& res, vector<int>& output, int start,
                 int len) {
    if (start == len) {
      res.push_back(output);
      return;
    }
    for (int i = start; i < len; i++) {
      swap(output[i], output[start]);
      backtrace(res, output, start + 1, len);
      swap(output[i], output[start]);
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    backtrace(res, nums, 0, nums.size());
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> test{7, 1, 5};
  Solution s;
  auto ans = s.permute(test);
  for (auto& nums : ans) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }
  return 1;
}