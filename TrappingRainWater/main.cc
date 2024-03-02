/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-27 21:12:55
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-02 17:04:45
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    stack<int> tmp;
    int n = height.size();
    int ans = 0, h = 0, w = 0;
    for (int i = 0; i < n; i++) {
      // 只有栈不为空，且height[i]栈顶索引对应的元素小时，才能够形成槽
      while (!tmp.empty() && height[i] > height[tmp.top()]) {
        auto top = tmp.top();
        tmp.pop();
        if (tmp.empty()) {
          // 弹出一个元素后当前栈为空，也就是一开始栈中元素不足2，不能够形成槽
          break;
        }
        auto left = tmp.top();
        h = min(height[i], height[left]) - height[top];
        w = i - left - 1;
        ans += h * w;
      }
      // 栈为空或下一个height比height(top)要小，直接入栈
      tmp.push(i);
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  // vector<int> test = {4, 2, 0, 3, 2, 5};
  vector<int> test = {4, 2, 0, 3};
  // vector<int> test = {0, 1, 0, 3};
  Solution s;
  cout << s.trap(test) << endl;

  return 1;
}