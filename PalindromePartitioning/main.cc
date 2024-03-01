/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:18:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-01 18:01:29
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
  vector<vector<int>> f;

 public:
  vector<vector<string>> partition(string s) {
    for (int i = 0; i < s.size(); i++) {
    }
  }
};

int main(int argc, char** argv) {
  string test = "abaf";
  Solution s;
  s.nextPermutation(test);
  for (auto& num : test) {
    cout << num << " ";
  }
  cout << endl;
  return 1;
}