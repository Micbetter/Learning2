#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct DLinkNode {
  DLinkNode* prev;
  DLinkNode* next;
  int key;
  int value;
  DLinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DLinkNode(int key, int value)
      : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  int capacity;
  int size;
  DLinkNode* head;
  DLinkNode* tail;
  unordered_map<int, DLinkNode*> cache;

 public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new DLinkNode();
    tail = new DLinkNode();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (cache.count(key) > 0) {
      DLinkNode* node = cache[key];
      moveToHead(node);
      return node->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cache.count(key) > 0) {
      DLinkNode* node = cache[key];
      node->value = value;
      moveToHead(node);
    } else {
      DLinkNode* node = new DLinkNode(key, value);
      addToHead(node);
      cache[key] = node;
      size++;
      if (size > capacity) {
        DLinkNode* tail_node = removeTail();
        cache.erase(tail_node->key);
        delete tail_node;
        size--;
      }
    }
  }

  void removeNode(DLinkNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addToHead(DLinkNode* node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void moveToHead(DLinkNode* node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkNode* removeTail() {
    DLinkNode* tail_node = tail->prev;
    removeNode(tail_node);
    return tail_node;
  }
};

int main(int argc, char** argv) {
  //   string test = "abdabffef";
  LRUCache s(2);

  s.put(1, 1);
  s.put(2, 2);
  std::cout << s.get(1) << std::endl;
  s.put(3, 3);
  std::cout << s.get(2) << std::endl;
  s.put(4, 4);
  std::cout << s.get(1) << std::endl;
  std::cout << s.get(3) << std::endl;
  std::cout << s.get(4) << std::endl;

  return 1;
}