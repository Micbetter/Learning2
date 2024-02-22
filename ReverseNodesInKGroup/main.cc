/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 15:43:49
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

  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    ListNode* hair = new ListNode(0, head);
    ListNode* curr = head;
    ListNode* prev = hair;
    while (curr != nullptr) {
      ListNode* start = curr;
      for (int i = 0; i < k; i++) {
        curr = curr->next;
        if (curr == nullptr && i < k - 1) {
          return hair->next;
        }
      }
      auto res = reverse(start, curr);
      res.second->next = curr;
      prev->next = res.first;
      prev = res.second;
    }
    return hair->next;
  }
};

int main(int argc, char** argv) {
  // ListNode* node1 = new ListNode(
  //     1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode* node1 = new ListNode(1, new ListNode(2));
  Solution s;

  ListNode* res = s.reverseKGroup(node1, 2);

  return 1;
}