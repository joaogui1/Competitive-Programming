#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

struct node {
  map<char, node> children;
  int many;
  char last;
  node(): many(0), last('\0') {}
  void add(const char *s) {
    if (s[0] == '\0') {
      ++many;
    } else {
      children[s[0]].add(s+1);
    }
  }
  void set_last(string &s, int i = 0) {
    if (i == s.size()) {
    } else {
      last = s[i];
      children[s[i]].set_last(s, i+1);
    }
  }
  void solve() {
    for (int i = 0; i < many; ++i) printf("[enter]\n");
    for (map<char, node>::iterator it = children.begin(); it != children.end(); ++it) {
      char c = (*it).first;
      if (c == last) continue;
      node &child = it -> second;
      printf("%c\n", c);
      child.solve();
      printf("[backspace]\n");
    }

    if (last != '\0') {
      printf("%c\n", last);
      children[last].solve();
    }
  }

};

int main() {
  int n;
  cin >> n;

  string last;
  
  node root;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    root.add(s.c_str());
    if (s.size() > last.size()) last = s;
  }

  root.set_last(last);
  root.solve();

  return 0;
}



