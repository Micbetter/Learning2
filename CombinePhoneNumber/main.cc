/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-01 14:56:46
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
  unordered_map<char, string> buttons;

 public:
  Solution() {
    buttons['2'] = "abc";
    buttons['3'] = "def";
    buttons['4'] = "ghi";
    buttons['5'] = "jkl";
    buttons['6'] = "mno";
    buttons['7'] = "pqrs";
    buttons['8'] = "tuv";
    buttons['9'] = "wxyz";
  }

  void helper(vector<string>& output, string& res, vector<string>& strs,
              int index) {
    if (index >= strs.size()) {
      output.push_back(res);
      return;
    }
    for (auto& ch : strs[index]) {
      // add a char from strs[index]
      res.push_back(ch);
      // add char from next strs, strs[index+1]
      helper(output, res, strs, index + 1);
      // remove current char
      res.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits == "") return {};
    vector<string> strs;
    for (auto& ch : digits) {
      strs.push_back(buttons[ch]);
    }
    vector<string> output;
    string res;
    helper(output, res, strs, 0);
    return output;
  }
};

int main(int argc, char** argv) {
  string digits = "24";
  Solution s;
  auto res = s.letterCombinations(digits);
  for (auto& str : res) {
    cout << str << " ";
  }
  cout << endl;

  return 1;
}