#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  // f[i] = f[i - 1] + f[i - 2]
  int climbStairs(int n) {
    if (n == 1) return 1;
    vector<int> f(n + 1);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
  }
};

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.climbStairs(2) << std::endl;

  return 1;
}