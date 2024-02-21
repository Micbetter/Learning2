/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 17:10:08
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
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (row[i] || col[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> test = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  Solution s;
  s.setZeroes(test);

  for (auto& nums : test) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  return 1;
}