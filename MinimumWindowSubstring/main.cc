/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:38:46
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-03 01:03:30
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<int, int> needed;
    int need_count = t.size();

    for (auto c : t) {
      needed[c]++;
    }
    string res;
    for (int left = 0, right = 0; right < s.size(); right++) {
      if (needed[s[right]] > 0) need_count--;
      needed[s[right]]--;
      // 表明当前已经包含了所有t中的字符

      if (need_count == 0) {
        // 此时需要移动左边界，这里移动的都是不在t中的元素，所以needcount不用减少
        while (needed[s[left]] < 0) {
          cout << "remove:" << s[left] << endl;
          // 因为要将左边界移出，因此该边界的needed值+1
          needed[s[left]]++;
          left++;
        }
        int len = right - left + 1;
        if (res.empty() || res.size() > len) {
          res = s.substr(left, len);
        }
        // 为使得遍历可以继续下去，需要将left再右移一位，needcout++
        needed[s[left]]++;
        left++;
        need_count++;
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
  Solution s;
  cout << s.minWindow("123", "23") << endl;
  return 1;
}