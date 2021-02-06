#include <bits/stdc++.h>

using namespace std;

vector <int> adj[32];
int type[32], t, w[32], ans = (1 << 20), mark[32][128][128];

int dfs(int u, int a, int b){
  int v;
  mark[u][a][b] = 1;
  ans = min(ans, abs(a - b) + (a + b == 0)*(1 << 20));
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!mark[v][a][b])
      dfs(v, a, b);
  }
  for(int i = 1; 1; ++i){
    if(a + b + i*w[u] > t)  break;
    if(type[u] == 0){
      if(!mark[u][a + i*w[u]][b])
        dfs(u, a + i*w[u], b);
    }
    else{
      if(!mark[u][a][b + i*w[u]])
        dfs(u, a, b + i*w[u]);
    }
  }
  return ans;
}

int main(){
  char tp;
  int n, lixo, val, id, k, u;
  scanf("%d %d", &n, &t);
  for(int i = 0; i < n; ++i){
    scanf("%d %d %c %d", &id, &val, &tp, &k);
    type[id] = (tp - 'A');
    w[id] = val;
    for(int i = 0; i < k; ++i){
      scanf("%d", &u);
      adj[id].push_back(u);
    }
  }
  cout << dfs(0, 0, 0) << "\n";

  return 0;
}
