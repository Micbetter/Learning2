/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-26 17:30:32
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
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0, round = 0;
    queue<pair<int, int>> tmp;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          ++count;
        } else if (grid[i][j] == 2) {
          tmp.push({i, j});
        }
      }
    }
    while (count > 0 && !queue.empty()) {
      int size = tmp.size();
      for (int x = 0; x < size; x++) {
        auto node = tmp.front();
        int row = tmp.first, col = tmp.second;
        tmp.pop();
        if (row - 1 >= 0 && grid[row - 1][col] == 1) {
          grid[row - 1][col] = 2;
          count--;
          tmp.push(row - 1, col);
        }
        if (row + 1 < m && grid[row + 1][col] == 1) {
          grid[row + 1][col] = 2;
          count--;
          tmp.push(row + 1, col);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == 1) {
          grid[row][col - 1] = 2;
          count--;
          tmp.push(row, col - 1);
        }
        if (col + 1 < n && grid[row][col + 1] == 1) {
          grid[row][col + 1] = 2;
          count--;
          tmp.push(row, col + 1);
        }
      }
      round++;
    }
    if (count > 0) return -1;
    return round;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  s.orangesRotting(test);

  for (auto& nums : test) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  return 1;
}