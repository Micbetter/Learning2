/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-02 00:04:22
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

/*
  设 dp[i] 表示包括nums[i]这个节点的递增子序列的最大长度，则：
    dp[i] = max(dp[j]) + 1 && nums[i] > nums[j] (0<=j<i)

*/

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int max_val = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
      int max_of_dp_j = 0;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          max_of_dp_j = max(dp[j], max_of_dp_j);
        }
      }
      // max_of_dp_j 为 0 时，表示没有满足 nums[i] > nums[j] 的条件
      dp[i] = max_of_dp_j == 0 ? 1 : max_of_dp_j + 1;
      max_val = max(max_val, dp[i]);
    }
    return max_val;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, 3};
  Solution s;
  auto ans = s.lengthOfLIS(test, 2);
  cout << ans << endl;

  return 1;
}