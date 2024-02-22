/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:18:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 23:50:23
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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    if (numRows == 1) {
      return ans;
    }
    for (int i = 1; i < numRows; i++) {
      vector<int> res(i + 1, 1);
      for (int j = 0; j <= i; j++) {
        int up_left_index = j - 1, up_right_index = j;
        if (up_left_index < 0 || up_right_index > i - 1) {
          continue;
        } else {
          res[j] = ans[i - 1][up_left_index] + ans[i - 1][up_right_index];
        }
      }
      ans.push_back(res);
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  Solution s;
  auto ans = s.generate(4);
  for (auto& nums : ans) {
    for (auto& num : nums) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 1;
}