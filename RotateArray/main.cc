/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 16:04:51
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
  void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
      swap(nums[start++], nums[end--]);
    }
  }
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    reverse(nums, 0, n - 1);
    reverse(nums, 0, (k % n) - 1);
    reverse(nums, k % n, n - 1);
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 3, 0, 4, -3, 2};
  Solution s;
  s.rotate(test, 3);

  for (auto num : test) {
    std::cout << num << " " << std::endl;
  }
  std::cout << std::endl;

  return 1;
}