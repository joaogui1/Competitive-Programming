#include <bits/stdc++.h>

using namespace std;

vector<int> adj[324];
int mk[324], iss[324];

int dfs(int u){
  mk[u] = 1;
  int v, d = 0, aux;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!mk[v]){
      aux = dfs(v);
      if(aux > 0 || iss[v]) d += (2 + aux);
    }
  }
  return d;
}

void initialize(){
  memset(mk, 0, sizeof mk);
  memset(iss, 0, sizeof iss);
  for(int i = 0; i < 324; ++i)  adj[i].clear();
  return;
}

int main(){
  int c, v, x, y;
  for(int t = 1; scanf("%d %d", &c, &v); ++t){
    initialize();
    if(c + v == 0)  return 0;
    for(int i = 0; i < c - 1; ++i){
      scanf("%d %d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for(int i = 0; i < v; ++i){
      scanf("%d", &x);
      iss[x] = 1;
    }

    printf("Teste %d\n%d\n\n", t, dfs(1));
  }


  return 0;
}
