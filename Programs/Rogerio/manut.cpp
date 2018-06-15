#include <bits/stdc++.h>

using namespace std;

vector<int> adj[512];
int dfs_num[512], dfs_min[512], pai[512], dfs_cnt = 0, ch, art[512];

void dfs(int u){
  int v;
  dfs_num[u] = dfs_min[u] = ++dfs_cnt;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!dfs_num[v]){
      pai[v] = u;
      dfs(v);
      if(u == 1)  ++ch;
      if(pai[u] > 0 && dfs_min[v] >= dfs_num[u])  art[u] = 1;
      dfs_min[u] = min(dfs_min[v], dfs_min[u]);
    }
    else if(v != pai[u]) dfs_min[u] = min(dfs_min[u], dfs_num[v]);
  }
}

void initialize(){
  ch = dfs_cnt = 0;
  memset(art, 0, sizeof art);
  memset(pai, 0, sizeof pai);
  memset(dfs_num, 0, sizeof dfs_num);
  memset(dfs_min, 0, sizeof dfs_min);
  for(int i = 0; i < 512; ++i) adj[i].clear();
}
int main(){
  bool vdc;
  int n, m, a, b, t = 0;
  while(1){
    vdc = 0;
    initialize();
    scanf("%d %d", &n, &m);
    if(n + m == 0)  return 0;
    for(int i = 0; i < m; ++i){
      scanf("%d %d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    dfs(1);
    if(ch > 1)  art[1] = 1;
    printf("Teste %d\n", ++t);
    for(int i = 1; i <= n; ++i){
      if(art[i]){
        printf("%d ", i);
        vdc = 1;
      }
    }
    if(!vdc)  printf("nenhum");
    printf("\n\n");
  }


  return 0;
}
