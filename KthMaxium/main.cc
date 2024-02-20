#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  void maxHeapify(vector<int>& nums, int index, int heapSize) {
    int largest_index = index;
    int left = 2 * index + 1, right = left + 1;
    if (left < heapSize && nums[left] > nums[largest_index])
      largest_index = left;
    if (right < heapSize && nums[right] > nums[largest_index])
      largest_index = right;
    if (largest_index != index) {
      swap(nums[index], nums[largest_index]);
      maxHeapify(nums, largest_index, heapSize);
    }
  }

  void buildMaxHeap(vector<int>& nums, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
      maxHeapify(nums, i, heapSize);
    }
  }
  int findKthLargest(vector<int>& nums, int k) {
    int heapSize = nums.size(), n = nums.size() - 1;
    buildMaxHeap(nums, heapSize);
    for (int i = 0; i < k - 1; i++) {
      swap(nums[0], nums[n - i]);
      maxHeapify(nums, 0, --heapSize);
    }
    return nums[0];
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 3, 0, 4, -3, 2};
  Solution s;
  std::cout << s.findKthLargest(test, 5) << std::endl;

  return 1;
}