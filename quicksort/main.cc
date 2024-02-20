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
  int partition(vector<int>& nums, int start, int end) {
    int l = start, r = end;
    int pivot = nums[start];
    while (l < r) {
      while (l < r && nums[r] >= pivot) r--;
      while (l < r && nums[l] <= pivot) l++;
      swap(nums[l], nums[r]);
    }
    swap(nums[start], nums[l]);
    return l;
  }
  vector<int> quicksort(vector<int>& nums, int start, int end) {
    vector<int> res(nums.begin(), nums.end());
    if (start >= end) return res;
    int j = partition(res, start, end);
    auto res1 = quicksort(res, start, j - 1);
    res.assign(res1.begin(), res1.end());
    auto res2 = quicksort(res, j + 1, end);
    res.assign(res2.begin(), res2.end());
    return res;
  }

  vector<int> sortArray(vector<int>& nums) {
    return quicksort(nums, 0, nums.size() - 1);
  }
};

int main(int argc, char** argv) {
  vector<int> nums = {10, 6, 1, 17, 13, 5, 7, 10};

  Solution s;
  auto res = s.quicksort(nums, 0, nums.size() - 1);
  for (auto& num : res) {
    cout << num << " ";
  }
  cout << endl;

  return 1;
}