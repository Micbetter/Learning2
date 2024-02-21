/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 09:40:59
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-21 09:57:11
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int max_profit = std::numeric_limits<int>::min();
    int lowest_price = std::numeric_limits<int>::max();
    for (auto &price : prices) {
      if (price < lowest_price) {
        lowest_price = price;
      }
      max_profit = max(max_profit, price - lowest_price);
    }
    return max_profit;
  }
};

int main(int argc, char **argv) {
  vector<int> prices{7, 1, 5, 3, 6, 4};
  Solution s;
  cout << s.maxProfit(prices) << endl;
  return 1;
}