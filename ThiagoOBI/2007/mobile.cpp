#include <bits/stdc++.h>

using namespace std;

int sz[10100];
vector <int> adj[10100];

bool dfs(int u){
  sz[u] = 1;
  int v, ch_sz = -1;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!dfs(v)) return 0;
    sz[u] += sz[v];
    if(ch_sz == -1) ch_sz = sz[v];
    if(sz[v] != ch_sz)  return 0;
  }
  return 1;
}

int main(){
  int n, a, b;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d %d", &a, &b);
    adj[b].push_back(a);
  }
  printf("%s\n", (dfs(0))?"bem":"mal");

  return 0;
}
