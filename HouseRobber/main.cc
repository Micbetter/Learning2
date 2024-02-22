/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:51:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-23 00:31:23
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> profit(n);
    profit[0] = nums[0];
    if (n == 1) return profit[0];
    profit[1] = max(nums[0], nums[1]);
    if (n == 2) return profit[1];
    for (int i = 2; i < n; i++) {
      profit[i] = max(profit[i - 1], profit[i - 2] + nums[i]);
    }
    return profit[n - 1];
  }
};

int main(int argc, char** argv) {
  vector<int> nums = {1, 2, 3, 1};
  Solution s;
  std::cout << s.rob(nums) << std::endl;

  return 1;
}