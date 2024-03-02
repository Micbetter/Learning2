/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:18:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-01 22:32:13
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
  vector<vector<int>> dp;

 public:
  void dfs(string& s, int index, vector<string>& res,
           vector<vector<string>>& output) {
    if (index == s.size()) {
      output.push_back(res);
      return;
    }
    for (int j = index; j < s.size(); j++) {
      if (dp[index][j]) {
        res.push_back(s.substr(index, j - index + 1));
        dfs(s, j + 1, res, output);
        res.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    int n = s.size();
    dp.assign(n, vector<int>(n));
    vector<vector<string>> output;
    vector<string> res;
    // for L = 0
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }
    for (int L = 1; L < n; L++) {
      for (int start = 0; start < n - L; ++start) {
        int end = start + L;
        if (s[start] == s[end]) {
          if (L <= 2) {
            dp[start][end] = 1;
          } else {
            dp[start][end] = dp[start + 1][end - 1];
          }
        } else {
          dp[start][end] = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << "dp[" << i << "]"
             << "[" << j << "]=" << dp[i][j] << endl;
      }
    }
    dfs(s, 0, res, output);
    return output;
  }
};

int main(int argc, char** argv) {
  string test = "aab";
  Solution s;
  auto res = s.partition(test);
  for (auto& str : res) {
    for (auto& val : str) {
      cout << val << " ";
      cout << endl;
    }
  }
  cout << endl;
  return 1;
}