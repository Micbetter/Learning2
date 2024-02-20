#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int left = 0;
    int max_size = 0;
    unordered_set<char> window;
    for (int i = 0; i < s.size(); i++) {
      while (window.find(s[i]) != window.end()) {
        window.erase(s[left]);
        left++;
      }
      window.insert(s[i]);
      max_size = max(max_size, i - left + 1);
    }
    return max_size;
  }
};

int main(int argc, char** argv) {
  string test = "abdabffef";
  Solution s;
  auto len = s.lengthOfLongestSubstring(test);
  std::cout << len << std::endl;
  return 1;
}