/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 11:19:49
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-06 18:29:59
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class MedianFinder {
  multiset<int> nums;
  multiset<int>::iterator left, right;

 public:
  MedianFinder() {}

  void addNum(int num) {
    int n = nums.size();
    nums.insert(num);
    if (n == 0) {
      left = right = nums.begin();
    } else if (n % 2 == 0) {
      if (num >= *right) {
        left++;
      } else if (num < *right && num >= *left) {
        --right;
        ++left;
      } else {
        --right;
      }
    } else {
      if (num >= *right) {
        ++right;
      } else {
        --left;
      }
    }
  }

  double findMedian() { return (*left + *right) / 2.0; }
};

int main(int argc, char** argv) {
  MedianFinder s;
  s.addNum(2);
  s.addNum(4);
  cout << s.findMedian() << endl;
  s.addNum(3);
  cout << s.findMedian() << endl;

  return 1;
}