/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 17:49:51
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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int total = m * n;
    int left = 0, right = n - 1, up = 0, down = m - 1;
    vector<int> res;
    while (total > 0) {
      // left to right
      for (int i = left; i <= right; i++) {
        res.push_back(matrix[up][i]);
        total--;
      }
      if (total == 0) break;
      up++;
      // up to down
      for (int j = up; j <= down; j++) {
        res.push_back(matrix[j][right]);
        total--;
      }
      if (total == 0) break;
      right--;
      // right to left
      for (int p = right; p >= left; p--) {
        res.push_back(matrix[down][p]);
        total--;
      }
      if (total == 0) break;
      down--;
      // down to up
      for (int q = down; q >= up; q--) {
        res.push_back(matrix[q][left]);
        total--;
      }
      if (total == 0) break;
      left++;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> test = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution s;
  auto ans = s.spiralOrder(test);

  for (auto num : ans) {
    std::cout << num << " " << std::endl;
  }
  std::cout << std::endl;

  return 1;
}