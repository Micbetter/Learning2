/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-27 23:48:11
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
 private:
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int min_val = numeric_limits<int>::max();
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[left] > nums[middle]) {
        // 右边有序，记录右边的最小值
        min_val = min(min_val, nums[middle]);
        // 进而在左边查找更小的值
        right = middle - 1;
      } else {
        // 左右有序，记录左边的最小值
        min_val = min(min_val, nums[left]);
        // 进而在右边找更小的值
        left = middle + 1;
      }
    }
    return min_val;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, 4, 4, 6};
  Solution s;
  cout << s.findMin(test) << endl;

  return 1;
}