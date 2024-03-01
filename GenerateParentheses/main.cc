/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-01 16:18:18
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  string res;

 public:
  void dfs(vector<string>& output, int left, int right, int number) {
    if (res.size() == number * 2) {
      output.push_back(res);
      return;
    }
    if (left < number) {
      res.push_back('(');
      cout << "add left res:" << res << endl;
      dfs(output, left + 1, right, number);
      res.pop_back();
      cout << "pop left res:" << res << endl;
    }
    if (right < left) {
      res.push_back(')');
      cout << "add right res:" << res << endl;
      dfs(output, left, right + 1, number);
      res.pop_back();
      cout << "pop right res:" << res << endl;
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> output;
    string res;
    int left = 0, right = 0;
    dfs(output, left, right, n);
    return output;
  }
};

int main(int argc, char** argv) {
  Solution s;
  auto res = s.generateParenthesis(2);
  for (auto& str : res) {
    cout << str << " ";
  }
  cout << endl;

  return 1;
}