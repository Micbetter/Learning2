#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// void test() {
//   int n = s.size();
//   if (n < 2) {
//     return s;
//   }

//   int maxLen = 1;
//   int begin = 0;
//   // dp[i][j] 表示 s[i..j] 是否是回文串
//   vector<vector<int>> dp(n, vector<int>(n));
//   // 初始化：所有长度为 1 的子串都是回文串
//   for (int i = 0; i < n; i++) {
//     dp[i][i] = true;
//   }
//   // 递推开始
//   // 先枚举子串长度
//   for (int L = 2; L <= n; L++) {
//     // 枚举左边界，左边界的上限设置可以宽松一些
//     for (int i = 0; i < n; i++) {
//       // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
//       int j = L + i - 1;
//       // 如果右边界越界，就可以退出当前循环
//       if (j >= n) {
//         break;
//       }

//       if (s[i] != s[j]) {
//         dp[i][j] = false;
//       } else {
//         if (j - i < 3) {
//           dp[i][j] = true;
//         } else {
//           dp[i][j] = dp[i + 1][j - 1];
//         }
//       }

//       // 只要 dp[i][L] == true 成立，就表示子串 s[i..L]
//       // 是回文，此时记录回文长度和起始位置
//       if (dp[i][j] && j - i + 1 > maxLen) {
//         maxLen = j - i + 1;
//         begin = i;
//       }
//     }
//   }
// }

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;
    int max_size = 1;
    int begin = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (size_t i = 0; i < n; i++) {
      dp[i][i] = 1;
    }
    for (size_t L = 2; L <= n; L++) {
      for (int left = 0; left < n; left++) {
        int right = left + L - 1;
        if (right >= n) break;
        if (s[left] != s[right]) {
          dp[left][right] = 0;
        } else {
          if (right - left < 3) {
            dp[left][right] = true;
          } else {
            dp[left][right] = dp[left + 1][right - 1];
          }
        }
        if (dp[left][right] && L > max_size) {
          max_size = L;
          begin = left;
        }
      }
    }
    return s.substr(begin, max_size);
  }
};

int main(int argc, char** argv) {
  string str = "bb";

  Solution s;
  cout << s.longestPalindrome(str) << endl;

  return 1;
}