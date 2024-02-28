/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-28 09:12:28
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-28 09:57:00
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  unordered_map<int, int> visited;

 public:
  // bool dfs(int index, vector<int>& nums, int size) {
  //   if (nums[index] >= size - 1 - index) return true;
  //   for (int i = 1; i <= nums[index]; ++i) {
  //     if (visited[index] == 1) continue;
  //     if (dfs(index + i, nums, size)) {
  //       return true;
  //     }
  //   }
  //   visited[index] = 1;
  //   return false;
  // }

  // bool canJump(vector<int>& nums) {
  //   int n = nums.size();
  //   return dfs(0, nums, n);
  // }
  bool canJump(vector<int>& nums) {
    int k = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i > k) return false;
      k = max(k, nums[i] + i);
    }
    return true;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 1, 1, 0};
  Solution s;
  std::cout << s.canJump(test) << std::endl;

  return 1;
}