/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 16:21:54
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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end) {
    ListNode* prev = nullptr;
    ListNode* cur = start;
    while (cur != end) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return make_pair(prev, start);
  }

  ListNode* swapPairs(ListNode* head) {
    ListNode* hair = new ListNode(0, head);
    ListNode* cur = head;
    ListNode* prev = hair;
    while (cur != nullptr) {
      ListNode* start = cur;
      for (int i = 0; i < 2; i++) {
        cur = cur->next;
        if (cur == nullptr && i < 1) {
          return hair->next;
        }
      }
      auto res = reverse(start, cur);
      prev->next = res.first;
      res.second->next = cur;
      prev = res.second;
    }
    return hair->next;
  }
};

int main(int argc, char** argv) {
  ListNode* node1 = new ListNode(1, new ListNode(2, new ListNode(3)));
  // ListNode* node1 = new ListNode(1);
  Solution s;
  ListNode* res = s.swapPairs(node1);

  return 1;
}