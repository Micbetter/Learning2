/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 15:45:00
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 14:24:31
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
  void removeNode(ListNode* head) {}

  ListNode* remove(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* dummpy = new ListNode(0, head);
    ListNode* slow = dummpy;
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode* ans = slow->next;
    slow->next = slow->next->next;
    delete ans;
    return dummpy->next;
  }
};

int main(int argc, char** argv) {
  ListNode* node1 = new ListNode(1, new ListNode(2, new ListNode(3)));
  // ListNode* node1 = new ListNode(1);
  Solution s;

  ListNode* res = s.remove(node1, 2);

  return 1;
}