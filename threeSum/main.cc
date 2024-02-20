#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int first = 0; first < n; first++) {
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      int target = -nums[first];
      int third = n - 1;
      for (int second = first + 1; second < n; second++) {
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }
        while (second < third && nums[second] + nums[third] > target) {
          third--;
        }
        if (second == third) {
          break;
        }
        if (nums[second] + nums[third] == target) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 3, 0, 4, -3, 2};
  Solution s;
  auto ans = s.threeSum(test);
  for (auto& nums : ans) {
    for (auto num : nums) {
      std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;
  }
  return 1;
}