/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:18:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-26 15:44:09
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    //从后向前找到第一个升序
    int i = n - 2, j = i + 1;
    for (; i >= -1; --i, --j) {
      if (i == -1) break;
      if (nums[i] < nums[j]) break;
    }
    if (i >= 0) {
      for (int k = n - 1; k >= j; --k) {
        if (nums[k] > nums[i]) {
          swap(nums[k], nums[i]);
          break;
        }
      }
    }
    sort(nums.begin() + j, nums.end());
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 3, 1, 4, 3, 5, 5};
  Solution s;
  s.nextPermutation(test);
  for (auto& num : test) {
    cout << num << " ";
  }
  cout << endl;
  return 1;
}