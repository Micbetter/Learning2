/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 09:29:08
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
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n; j++) {
        swap(matrix[i][j], matrix[n - 1 - i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  s.rotate(test);

  for (auto& nums : test) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }

  return 1;
}