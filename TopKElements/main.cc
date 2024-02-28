/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-27 21:12:55
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-28 09:08:50
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  static bool cmp(const pair<int, int>& e1, const pair<int, int>& e2) {
    return e1.second > e2.second;
  }

  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> counts;
    for (auto& num : nums) {
      counts[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   function<bool(pair<int, int>, pair<int, int>)>>
        tmp(cmp);
    for (auto& count : counts) {
      if (tmp.size() < k) {
        tmp.push({count.first, count.second});
      } else if (tmp.size() == k && count.second > tmp.top().second) {
        tmp.pop();
        tmp.push({count.first, count.second});
      } else {
      }
    }
    while (!tmp.empty()) {
      res.emplace_back(tmp.top().first);
      tmp.pop();
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 1, 1, 2, 2, 2, 3};
  Solution s;
  s.topKFrequent(test, 2);

  return 1;
}