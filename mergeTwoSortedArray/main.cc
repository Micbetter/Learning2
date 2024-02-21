/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:38:46
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 12:32:54
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int tail = m + n - 1;
    int cur = 0;
    int p1 = m - 1, p2 = n - 1;
    while (p1 >= 0 || p2 >= 0) {
      if (p1 < 0) {
        cur = nums2[p2--];
      } else if (p2 < 0) {
        cur = nums1[p1--];
      } else if (nums1[p1] > nums2[p2]) {
        cur = nums1[p1--];
      } else {
        cur = nums2[p2--];
      }
      nums1[tail--] = cur;
    }
  };
};

int main(int argc, char** argv) {
  vector<int> nums1 = {1, 3, 4, 0, 0, 0};
  vector<int> nums2 = {2, 4, 7};
  Solution s;
  s.merge(nums1, 3, nums2, 3);
  for (auto num : nums1) {
    std::cout << num << " " << std::endl;
  }
  return 1;
}