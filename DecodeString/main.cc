/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-02 20:48:39
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
  bool isDigital(const char& c) { return c - '0' >= 0 && c - '0' <= 9; }

  string decodeString(string s) {
    int multi = 0;
    string res = "";
    stack<pair<int, string>> stk;
    for (auto& c : s) {
      if (isdigit(c)) {
        multi = multi * 10 + c - '0';
      } else if (c == '[') {
        stk.emplace(multi, res);
        res = "";
        multi = 0;
      } else if (c == ']') {
        auto k_v = stk.top();
        stk.pop();
        string tmp = k_v.second;
        if (k_v.first == 0) {
          k_v.first = 1;
        }
        for (int i = 0; i < k_v.first; i++) {
          tmp += res;
        }
        res = tmp;
      } else {
        res.push_back(c);
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
  string str = "100[ab]";
  Solution s;
  cout << s.decodeString(str) << endl;

  return 1;
}