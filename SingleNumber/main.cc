/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-26 15:16:24
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
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto& num : nums) {
      res ^= num;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 3, 1, 4, 3, 5, 5};
  Solution s;
  cout << s.singleNumber(test) << endl;

  return 1;
}