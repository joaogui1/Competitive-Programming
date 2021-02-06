/*
ID: joaogui1
LANG: C++
TASK: heritage
*/
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int head[100], to[100], nxt[100], lst;

void _init() {
 memset(head, -1, sizeof head);
 lst = 0;
}

void addEdge(int f, int t) {
 nxt[lst] = head[f];
 to[lst] = t;
 head[f] = lst++;
}

void dfs(int node){
 for(int i=head[node];i!=-1;i=nxt[i]){
  dfs(to[i]);
 }
 cout<<char(node + 'A') ;
}

bool vis[30];
int ides[30];
int main() {
 freopen("heritage.in", "r" ,stdin);
 freopen("heritage.out","w",stdout);
 string s1, s2;
 cin >> s1 >> s2;
 for (int i = 0; i < int(s2.size()); i++) {
  ides[s2[i] - 'A'] = i;
 }

 queue<int> Q;
 _init();
 Q.push(s2[0] - 'A');
 while (Q.size()) {
  int cur = Q.front();
  Q.pop();

  int id = -1;
  for (int i = 0; i < int(s1.size()); i++) {
   if (s1[i]-'A' == cur)
    id = i;
  }
  if (id == -1)
   continue;
  vis[id] = 1;
  int mn = 1 << 30;
  for (int i = id + 1; i < int(s1.size()) && !vis[i]; i++) {
   if (ides[s1[i] - 'A'] < mn) {
    mn = ides[s1[i] - 'A'];
   }
  }
  if (mn != (1 << 30)) {
   //cout<<s2[mn];
   addEdge(cur, s2[mn] - 'A');
   Q.push(s2[mn] - 'A');
  }

  mn = 1 << 30;
  for (int i = id - 1; i >= 0 && !vis[i]; i--) {
   if (ides[s1[i] - 'A'] < mn) {
    mn = ides[s1[i] - 'A'];
   }
  }
  if (mn != (1 << 30)) {
   //cout<<s2[mn];
   addEdge(cur, s2[mn] - 'A');
   Q.push(s2[mn] - 'A');
  }
 }
 dfs(s2[0]-'A');
 cout<<endl;
}
