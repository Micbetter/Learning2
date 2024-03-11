/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:18:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-08 10:28:02
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
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return false;
    int sum = 0, max_element = nums[0];
    for (auto& num : nums) {
      sum += num;
      max_element = max(max_element, num);
    }
    if (sum & 1) return false;
    int target = sum / 2;
    if (max_element > target) return false;
    vector<vector<int>> dp(n, vector<int>(target + 1));
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }
    dp[0][nums[0]] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= target; j++) {
        if (j >= nums[i]) {
          dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n - 1][target];
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, 3};
  Solution s;
  cout << s.canPartition(test) << endl;

  return 1;
}