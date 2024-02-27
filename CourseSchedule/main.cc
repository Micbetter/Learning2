/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-27 17:18:39
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    set<int> tmp;
    for (auto& prerequisite : prerequisites) {
      if (tmp.count(prerequisite[0]) == 0) {
        tmp.insert(prerequisite[0]);
      }
      if (tmp.count(prerequisite[1]) > 0) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> test = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
  Solution s;
  cout << s.canFinish(2, test) << endl;

  return 1;
}