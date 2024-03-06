/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-06 14:38:10
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

/*
text1.size() = m text2.size() = n
dp[i][j] 表示 text1中长度为i，text2中长度为j的字符串的最长公共子序列的长度，
因此初始条件 dp[i][0] = 0, dp[0][j] = 0，i < m+1, j < n+1

若 text1[i] == text2[j]，那么 dp[i+1][j+1] = 1 + dp[i][j]
若 text1[i] != text2[j]，那么 dp[i+1][j+1] = max(dp[i][j + 1], dp[i+1][j])

*/

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m + 1; i++) {
      dp[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++) {
      dp[0][j] = 0;
    }
    for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char** argv) {
  string test1 = "abce";
  string test2 = "dafbcde";
  Solution s;
  auto ans = s.longestCommonSubsequence(test1, test2);
  cout << ans << endl;

  return 1;
}