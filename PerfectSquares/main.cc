/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-22 23:18:22
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-23 11:38:17
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
 public:
  // f[n] 表示合为n的完全平方数的最小数量
  // 完全平方数的大小不可能超过 square(n), 那么在 j = [1, square(n)]
  // 之间遍历，则 f[n] = 1 + min(f[n-j^2])
  int numSquares(int n) {
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
      int minn = numeric_limits<int>::max();
      for (int j = 1; j * j <= i; j++) {
        minn = min(minn, f[i - j * j]);
      }
      f[i] = 1 + minn;
    }
    return f[n];
  }
};

int main(int argc, char** argv) {
  Solution s;
  auto ans = s.numSquares(4);
  cout << ans << endl;

  return 1;
}