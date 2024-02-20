#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// class Solution {
//  public:
//   list<int> mergeTwoSortedList(list<int>& list1, list<int>& list2) {
//     auto it1 = list1.begin(), it2 = list2.begin();
//     list<int> res;
//     while (it1 != list1.end() || it2 != list2.end()) {
//       if (*it1 < *it2 || it2 == list2.end()) {
//         res.push_back(*it1);
//         it1++;
//       }
//       if (*it1 > *it2 || it1 == list1.end()) {
//         res.push_back(*it2);
//         it2++;
//       }
//       if (*it1 == *it2) {
//         res.push_back(*it1);
//         res.push_back(*it2);
//         it1++;
//         it2++;
//       }
//     }
//     return res;
//   }
// };

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* res = new ListNode();
    ListNode* head = res;

    ListNode *it1 = list1, *it2 = list2;
    while (it1 != nullptr && it2 != nullptr) {
      if (it1->val < it2->val) {
        head->next = it1;
        it1 = it1->next;
      } else {
        head->next = it2;
        it2 = it2->next;
      }
      head = head->next;
    }
    head->next = it1 == nullptr ? it2 : it1;
    return res->next;
  }
};

int main(int argc, char** argv) {
  list<int> list1 = {1, 4, 5, 7, 10};
  list<int> list2 = {3, 5, 5, 8, 10};
  ListNode* node1 = new ListNode(1, new ListNode(2, new ListNode(3)));
  ListNode* node2 = new ListNode(3, new ListNode(5, new ListNode(6)));

  Solution s;
  auto res = s.mergeTwoLists(node1, node2);
  // for (auto& num : res) {
  //   cout << num << " ";
  // }
  // cout << endl;
  while (res != nullptr) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;

  return 1;
}