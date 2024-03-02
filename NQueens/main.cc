/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:38:46
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-03 02:37:41
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  void backtrace(int index, vector<vector<string>>& res, vector<string>& grid,
                 int n) {
    if (index == n) {
      res.push_back(grid);
      return;
    }
    for (int j = 0; j < n; j++) {
      if (isValid(grid, index, j)) {
        grid[index][j] = 'Q';
        backtrace(index + 1, res, grid, n);
        grid[index][j] = '.';
      }
    }
  }

  bool isValid(vector<string>& grid, int i, int j) {
    int n = grid.size();
    // 上方
    for (int a = 0; a < i; a++) {
      if (grid[a][j] == 'Q') {
        return false;
      }
    }
    // 左上
    for (int a = i, b = j; a >= 0 && b >= 0; a--, b--) {
      if (grid[a][b] == 'Q') {
        return false;
      }
    }
    // 右上
    for (int a = i, b = j; a >= 0 && b < n; a--, b++) {
      if (grid[a][b] == 'Q') {
        return false;
      }
    }
    return true;
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> grid(n, string(n, '.'));
    backtrace(0, res, grid, n);
    cout << res.size() << endl;
    return res;
  }
};

int main(int argc, char** argv) {
  Solution s;
  auto res = s.solveNQueens(4);
  for (auto& nums : res) {
    for (auto& num : nums) {
      cout << num << endl;
    }
    cout << "________" << endl;
  }
  return 1;
}