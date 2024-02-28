/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-28 09:12:28
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-28 15:08:19
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
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int end = 0, max_pos = 0;
    int steps = 0;
    for (int i = 0; i < n - 1; i++) {
      max_pos = max(max_pos, i + nums[i]);
      if (i == end) {
        end = max_pos;
        steps++;
      }
    }
    return steps;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 1, 1, 0};
  Solution s;
  std::cout << s.canJump(test) << std::endl;

  return 1;
}