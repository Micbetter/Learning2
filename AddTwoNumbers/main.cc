/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-21 22:51:30
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-22 00:04:23
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while (l1 != nullptr || l2 != nullptr) {
      int n1 = l1 != nullptr ? l1->val : 0;
      int n2 = l2 != nullptr ? l2->val : 0;
      int sum = n1 + n2 + carry;
      if (head == nullptr) {
        head = tail = new ListNode(sum % 10);
      } else {
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
      }
      carry = sum / 10;
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }
    if (carry > 0) {
      tail->next = new ListNode(carry);
      tail = tail->next;
    }
    return head;
  }
};

int main(int argc, char** argv) {
  vector<int> test = {2, 3, -4, 2, 5};
  ListNode node1(1, new ListNode(0, new ListNode(1)));
  ListNode node2(2, new ListNode(0, new ListNode(0)));
  Solution s;
  auto res = s.addTwoNumbers(&node1, &node2);
  cout << res->val << endl;
  return 1;
}