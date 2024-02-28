/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:18:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-28 16:08:11
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  unordered_map<char, int> tmp;

 public:
  vector<int> partitionLabels(string s) {
    vector<int> res;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (tmp.count(s[i]) == 0) {
        tmp[s[i]] = i;
      }
    }
    for (auto& [ch, index] : tmp) {
      cout << ch << ":" << index << endl;
    }
    vector<int> partition;
    int start = 0, end = 0;
    for (int i = 0; i < length; i++) {
      end = max(end, tmp[s[i]]);
      if (i == end) {
        partition.push_back(end - start + 1);
        start = end + 1;
      }
    }
    return partition;
  }
};

int main(int argc, char** argv) {
  string test = "abcbe";
  Solution s;
  auto ans = s.partitionLabels("abcbe");
  for (auto& num : ans) {
    cout << num << endl;
  }

  return 1;
}