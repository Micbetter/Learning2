/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-25 12:39:36
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-25 13:54:54
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <list>
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
  ListNode* mergeList(ListNode* node1, ListNode* node2) {
    if (node1 == nullptr) {
      return node2;
    } else if (node2 == nullptr) {
      return node1;
    } else if (node1->val > node2->val) {
      node2->next = mergeList(node1, node2->next);
      return node2;
    } else if (node1->val <= node2->val) {
      node1->next = mergeList(node1->next, node2);
      return node1;
    }
  }

  ListNode* sortList(ListNode* head) { return sort(head, nullptr); }

  ListNode* sort(ListNode* start, ListNode* end) {
    if (start == nullptr) {
      return start;
    }
    if (start->next == end) {
      start->next = nullptr;
      return start;
    }
    ListNode *quick = start, *slow = start;
    while (quick != end) {
      quick = quick->next;
      slow = slow->next;
      if (quick != end) {
        quick = quick->next;
      }
    }
    ListNode* middle = slow;
    return mergeList(sort(start, middle), sort(middle, end));
  }
};

int main(int argc, char** argv) {
  ListNode* node1 =
      new ListNode(5, new ListNode(2, new ListNode(3, new ListNode(1))));

  Solution s;
  auto res = s.sortList(node1);

  while (res != nullptr) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;

  return 1;
}