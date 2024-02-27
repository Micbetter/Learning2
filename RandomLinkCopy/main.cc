/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-25 11:28:58
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-25 12:39:12
 * @Description:
 *
 * Copyright (c) 2024 by Tusimple, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    unordered_map<Node*, int> cache_for_node;
    unordered_map<int, Node*> cache_for_index;
    Node* cur = head;
    Node* new_head = new Node(head->val);
    Node* new_cur = new_head;
    int index = 0;
    while (cur != nullptr) {
      new_cur->next = cur->next == nullptr ? nullptr : new Node(cur->next->val);
      cache_for_node[cur] = index;
      cache_for_index[index] = new_cur;
      index++;
      cur = cur->next;
      new_cur = new_cur->next;
    }
    // add nullptr to cache
    cache_for_node[cur] = index;
    // reset ptr
    cur = head;
    new_cur = new_head;
    while (cur != nullptr) {
      new_cur->random = cache_for_index[cache_for_node[cur->random]];
      cur = cur->next;
      new_cur = new_cur->next;
    }
    return new_head;
  }
};
int main(int argc, char** argv) {
  Node* node2 = new Node(1);

  Solution s;
  auto res = s.copyRandomList(node2);

  return 1;
}