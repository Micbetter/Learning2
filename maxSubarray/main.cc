#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int max_sum = nums[0];
    vector<int> f(n, 0);
    f[0] = nums[0];
    for (int i = 1; i < n; i++) {
      f[i] = max(f[i - 1] + nums[i], nums[i]);
      max_sum = max(max_sum, f[i]);
    }
    return max_sum;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {2, 3, -4, 2, 5};
  Solution s;
  std::cout << s.maxSubArray(test) << std::endl;

  return 1;
}