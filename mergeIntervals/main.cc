/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:38:46
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 15:09:45
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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    int m = intervals.size();
    res.push_back(intervals[0]);
    for (int i = 1; i < m; i++) {
      int n = res.size() - 1;
      if (intervals[i][0] <= res[n][1]) {
        res[n][1] = max(intervals[i][1], res[n][1]);
      } else {
        res.push_back(intervals[i]);
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> intervals = {{4, 5}, {3, 6}, {2, 3}};
  Solution s;
  vector<vector<int>> ans = s.merge(intervals);

  for (auto& nums : ans) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }
  return 1;
}