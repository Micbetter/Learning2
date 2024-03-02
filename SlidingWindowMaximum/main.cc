/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-02 17:27:54
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // first for nums[index], second for index
    priority_queue<pair<int, int>> pri_q;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      pri_q.emplace(nums[i], i);
    }
    res.push_back(pri_q.top().first);
    for (int i = k; i < n; i++) {
      pri_q.emplace(nums[i], i);
      while (pri_q.top().second <= i - k) {
        pri_q.pop();
      }
      res.push_back(pri_q.top().first);
    }
    return res;
  }
};

int main(int argc, char** argv) {
  // vector<int> test = {1, 3, 1, 4, 3, 5, 5};
  vector<int> test = {9, 10, 9, -7, -4, -8, 2, -6};
  Solution s;
  s.maxSlidingWindow(test, 5);

  return 1;
}