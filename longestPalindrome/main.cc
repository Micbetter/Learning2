#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

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
