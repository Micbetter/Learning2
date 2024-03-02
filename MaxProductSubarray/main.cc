/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-02 00:24:18
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
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp_max(n);
    vector<int> dp_min(n);
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    int max_product = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] < 0) {
        dp_max[i] = max(nums[i], nums[i] * dp_min[i - 1]);
        dp_min[i] = min(nums[i], nums[i] * dp_max[i - 1]);
      } else {
        dp_max[i] = max(nums[i], nums[i] * dp_max[i - 1]);
        dp_min[i] = min(nums[i], nums[i] * dp_min[i - 1]);
      }
      max_product = max(max_product, dp_max[i]);
    }
    return max_product;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, -1, 3, -2};
  Solution s;
  cout << s.maxProduct(test) << endl;
}