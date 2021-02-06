#include <bits/stdc++.h>

using namespace std;

vector <int> adj[412], ans;
int num[412], low[412], cont;

int dfs(int u, int p){
  int v;
  bool art = 0;
  num[u] = low[u] = cont++;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(num[v] == 0){
      dfs(v, u);
      low[u] = min(low[u], low[v]);

      if(p == 0 && art)  ans.push_back(u), p = -1;

      if(p > 0 && low[v] >= num[u])
        ans.push_back(u), p = -1;


      art = 1;
    }
    else if(v != p)  low[u] = min(low[u], num[v]);
  }

}

void initialize(){
  cont = 1;
  ans.clear();
  memset(low, 0, sizeof low);
  memset(num, 0, sizeof num);
  for(int i = 0; i < 412; ++i)  adj[i].clear();
  return;
}

int main(){
  int n, m, x, y;
  for(int t = 1; scanf("%d %d", &n, &m); ++t){
    initialize();
    if(n + m == 0)  return 0;
    for(int i = 0; i < m; ++i){
      scanf("%d %d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
      if(num[i] == 0) dfs(i, 0);
    printf("Teste %d\n", t);
    sort(ans.begin(), ans.end());
    if(ans.size() == 0) printf("nenhum\n");
    for(int i = 0; i < ans.size(); ++i) printf("%d%s", ans[i], ((i == (int)ans.size() - 1)?"\n":" "));
    printf("\n");
  }


  return 0;
}
