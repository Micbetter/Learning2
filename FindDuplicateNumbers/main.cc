/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-02 15:22:14
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

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    int ans = -1;
    while (left <= right) {
      int middle = (left + right) / 2;
      int cnt = 0;
      // cnt表示小于等于middle数字的个数
      for (int i = 0; i < n; i++) {
        if (nums[i] <= middle) {
          cnt++;
        }
      }
      if (cnt <= middle) {
        left = middle + 1;
      } else {
        right = middle - 1;
        ans = middle;
      }
    }
    cout << ans << endl;
    return ans;
  }
};

int main(int argc, char** argv) {
  // vector<int> test = {1, 3, 5, 4, 4, 2};
  vector<int> test = {4, 2, 3, 1, 4};
  Solution s;
  cout << s.findDuplicate(test) << endl;

  return 1;
}