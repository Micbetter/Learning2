/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 16:43:09
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
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> L(n, 0);
    vector<int> R(n, 0);
    vector<int> res;
    L[0] = 1;
    for (int i = 1; i < n; i++) {
      L[i] = L[i - 1] * nums[i - 1];
    }
    R[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--) {
      R[j] = R[j + 1] * nums[j + 1];
    }
    for (int m = 0; m < n; m++) {
      res.push_back(L[m] * R[m]);
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 2, 3, 4};
  Solution s;
  auto res = s.productExceptSelf(test);

  for (auto num : res) {
    std::cout << num << " " << std::endl;
  }
  std::cout << std::endl;

  return 1;
}