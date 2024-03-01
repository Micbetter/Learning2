/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 12:40:02
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-03-01 17:17:07
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
 private:
  vector<vector<int>> visited;

 public:
  bool bfs(int index, int i, int j, int m, int n, string word,
           vector<vector<char>>& board) {
    if (visited[i][j] == 1) {
      return false;
    }
    if (index == word.size() - 1) {
      return true;
    }
    visited[i][j] = 1;
    bool up = false, down = false, left = false, right = false;
    if (i + 1 < m && board[i + 1][j] == word[index + 1]) {
      down = bfs(index + 1, i + 1, j, m, n, word, board);
    }
    if (i - 1 >= 0 && board[i - 1][j] == word[index + 1]) {
      up = bfs(index + 1, i - 1, j, m, n, word, board);
    }
    if (j + 1 < n && board[i][j + 1] == word[index + 1]) {
      right = bfs(index + 1, i, j + 1, m, n, word, board);
    }
    if (j - 1 >= 0 && board[i][j - 1] == word[index + 1]) {
      left = bfs(index + 1, i, j - 1, m, n, word, board);
    }
    visited[i][j] = 0;
    return down || up || right || left;
  }

  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    visited = vector<vector<int>>(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          if (bfs(0, i, j, m, n, word, board)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main(int argc, char** argv) {
  // vector<vector<char>> board{
  //     {'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
  vector<vector<char>> board{{'a', 'b', 'c'}};
  Solution s;
  auto ans = s.exist(board, "bcb");
  cout << ans << endl;

  return 1;
}