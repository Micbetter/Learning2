
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void print_nums(const vector<int>& nums) {
  for (auto& num : nums) {
    cout << num << " ";
  }
  cout << endl;
}
class Solution {
 public:
  // 冒泡排序，时间复杂度O(n^2)，空间复杂度O(1)，稳定排序(值相等不交换位置)
  vector<int> bubbleSort(vector<int> array) {
    vector<int> nums(array.begin(), array.end());
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
        }
      }
    }
    return nums;
  }
  // 冒泡排序改进，在后续数组有序的情况下，避免重新冒泡
  vector<int> bubbleSort_2(vector<int> array) {
    vector<int> nums(array.begin(), array.end());
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      int ordered = 1;
      for (int j = 0; j < n - 1 - i; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
          ordered = 0;
        }
      }
      if (ordered == 1) {
        break;
      }
    }
    return nums;
  }
  //选择排序，时间复杂度O(n^2)，空间复杂度O(1)，不稳定排序(每次将最小值与首位交换)
  vector<int> selectionSort(vector<int> array) {
    vector<int> nums(array.begin(), array.end());
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      int min_index = i;
      for (int j = i + 1; j < n; j++) {
        if (nums[min_index] > nums[j]) {
          min_index = j;
        }
      }
      if (min_index != i) {
        swap(nums[i], nums[min_index]);
      }
    }
    return nums;
  }
  //插入排序(交换法)，时间复杂度O(n^2)，稳定排序
  vector<int> insertSort(vector<int> array) {
    vector<int> nums(array.begin(), array.end());
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      int j = i;
      while (j > 0 && nums[j - 1] > nums[j]) {
        swap(nums[j], nums[j - 1]);
        --j;
      }
    }
    return nums;
  }
  //堆排序，时间复杂度O(nlog(n))，不稳定排序(元素会被交换到数组头部)
  void maxHeapify(vector<int>& array, int index, int heapSize) {
    // 完全二叉树的左叶子节点索引为 2 * i + 1，右叶子节点索引为 2 * i + 2
    int left = 2 * index + 1, right = left + 1;
    int max_index = index;
    if (left < heapSize && array[left] > array[max_index]) {
      max_index = left;
    }
    if (right < heapSize && array[right] > array[max_index]) {
      max_index = right;
    }
    if (max_index != index) {
      swap(array[max_index], array[index]);
      maxHeapify(array, max_index, heapSize);
    }
  }
  void buildMaxHeap(vector<int>& array, int heapSize) {
    // 从数组索引 0 开始构建的大顶堆，其最后一个非叶子节点的索引为 n / 2 - 1
    for (int index = heapSize / 2 - 1; index >= 0; index--) {
      maxHeapify(array, index, heapSize);
    }
  }
  vector<int> heapSort(vector<int> array) {
    vector<int> nums(array.begin(), array.end());
    int n = nums.size();
    //先构建一个大顶堆
    buildMaxHeap(nums, n);
    // i = 0时，不需要再进行排序
    for (int i = n - 1; i > 0; i--) {
      // 构建完大顶后，数组第一元素为最大值，但其他值的顺序不保证，将最大值交换到数组最后
      swap(nums[i], nums[0]);
      // 继续从 index =  0调整大顶堆
      maxHeapify(nums, 0, i);
    }

    return nums;
  }
  int partition(vector<int>& array, int start, int end) {
    int l = start, r = end;
    int pivot = array[start];
    while (l < r) {
      while (l < r && array[r] >= pivot) r--;
      while (l < r && array[l] <= pivot) l++;
      swap(array[l], array[r]);
    }
    swap(array[start], array[l]);
    return l;
  }

  void helper(vector<int>& array, int start, int end) {
    // 进行分区之前需要先判断是否越界
    if (start >= end) return;
    int pivot_index = partition(array, start, end);
    helper(array, start, pivot_index - 1);
    helper(array, pivot_index + 1, end);
  }

  //快速排序，时间复杂度O(nlog(n))，不稳定排序(元素会被交换)
  vector<int> quickSort(vector<int> array) {
    vector<int> nums(array.begin(), array.end());
    int n = nums.size();
    helper(nums, 0, n - 1);
    return nums;
  }
  vector<int> mergeArray(const vector<int>& array1, const vector<int>& array2) {
    int m = array1.size(), n = array2.size();
    vector<int> res;
    int i = 0, j = 0;
    while (i < m && j < n) {
      if (array1[i] < array2[j]) {
        res.push_back(array1[i++]);
      } else {
        res.push_back(array2[j++]);
      }
    }
    if (i == m) {
      res.insert(res.end(), array2.begin() + j, array2.end());
    }
    if (j == n) {
      res.insert(res.end(), array1.begin() + i, array1.end());
    }
    return res;
  }

  vector<int> merge_helper(vector<int>& array, int start, int end) {
    if (start >= end) {
      return {array[start]};
    }
    int middle = (start + end) / 2;
    return mergeArray(merge_helper(array, start, middle),
                      merge_helper(array, middle + 1, end));
  }

  //归并排序，时间复杂度O(nlog(n))，稳定排序
  vector<int> mergeSort(vector<int> array) {
    vector<int> nums(array.begin(), array.end());
    int n = nums.size();
    return merge_helper(nums, 0, n - 1);
  }
};

int main(int argc, char** argv) {
  vector<int> test = {1, 3, 1, 4, 3, 5, 5};
  Solution s;
  print_nums(s.bubbleSort(test));
  print_nums(s.bubbleSort_2(test));
  print_nums(s.selectionSort(test));
  print_nums(s.insertSort(test));
  print_nums(s.heapSort(test));
  print_nums(s.quickSort(test));
  print_nums(s.mergeSort(test));

  return 1;
}