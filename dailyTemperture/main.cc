/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 14:19:07
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> stk;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
        ans[stk.top()] = i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 3, 0, 4, 4, 2};
  Solution s;
  vector<int> ans = s.dailyTemperatures(test);

  for (auto& num : ans) {
    cout << num << " ";
  }
  cout << endl;

  return 1;
}