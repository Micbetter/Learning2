/*
 * @Author: renwen.wang renwen.wang@tusen.ai
 * @Date: 2024-02-27 21:12:55
 * @LastEditors: renwen.wang renwen.wang@tusen.ai
 * @LastEditTime: 2024-02-27 21:31:49
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

class Trie {
 private:
  vector<Trie*> children;
  bool isEnd;
  Trie* searchPrefix(string prefix) {
    Trie* node = this;
    for (auto ch : prefix) {
      ch -= 'a';
      if (node->children[ch] == nullptr) {
        return nullptr;
      }
      node = node->children[ch];
    }
    return node;
  }

 public:
  Trie() : children(26, nullptr), isEnd(false) {}

  void insert(string word) {
    Trie* node = this;
    for (auto ch : word) {
      ch -= 'a';
      if (node->children[ch] == nullptr) {
        node->children[ch] = new Trie();
      }
      node = node->children[ch];
    }
    node->isEnd = true;
  };

  bool search(string word) {
    Trie* node = searchPrefix(word);
    return node != nullptr && node->isEnd;
  }

  bool startsWith(string prefix) {
    Trie* node = searchPrefix(prefix);
    return node != nullptr;
  }
};

int main(int argc, char** argv) {
  Trie t;
  t.insert("abcd");
  t.insert("efsaf");

  cout << t.startsWith("abc") << endl;
  cout << t.search("abc") << endl;
  cout << t.search("efsaf") << endl;

  return 1;
}