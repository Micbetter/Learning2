/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-27 20:39:39
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  bool finished = true;
  unordered_map<int, int> visited;
  unordered_map<int, vector<int>> edges;

 public:
  void dfs(int index) {
    visited[index] = 1;
    if (edges.count(index) > 0) {
      for (auto& i : edges[index]) {
        if (visited[i] == 0) {
          dfs(i);
        } else if (visited[i] == 1) {
          finished = false;
          break;
        } else {
          // nothing
        }
      }
    }
    visited[index] = 2;
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for (int i = 0; i < numCourses; ++i) {
      visited[i] = 0;
    }
    for (auto& prerequisite : prerequisites) {
      edges[prerequisite[1]].push_back(prerequisite[0]);
    }
    for (auto& node : visited) {
      if (!finished) break;
      if (node.second == 0) {
        dfs(node.first);
      }
    }
    return finished;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> test = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
  Solution s;
  cout << s.canFinish(2, test) << endl;

  return 1;
}