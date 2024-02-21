/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 21:53:53
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
  bool binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int middle = (left + right) / 2;
      if (nums[middle] == target) return true;
      if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
    return false;
  }
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    for (int i = 0; i < m; i++) {
      if (binarySearch(matrix[i], target)) return true;
    }
    return false;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  cout << s.searchMatrix(test, 9) << endl;

  return 1;
}