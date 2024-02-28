/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-27 23:00:11
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
  int binarySearch(vector<int>& nums, int target, bool lower) {
    int left = 0, right = nums.size() - 1;
    int ans = nums.size();
    while (left <= right) {
      int middle = (right - left) / 2 + left;
      if (nums[middle] > target || (lower && nums[middle] >= target)) {
        right = middle - 1;
        ans = middle;
      } else {
        left = middle + 1;
      }
    }
    return ans;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    int left = binarySearch(nums, target, true);
    int right = binarySearch(nums, target, false) - 1;
    if (left <= right && right < nums.size() && nums[left] == target &&
        nums[right] == target) {
      return {left, right};
    }
    return {-1, -1};
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, 4, 4, 6};
  Solution s;
  s.searchRange(test, 4);

  return 1;
}