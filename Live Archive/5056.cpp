#include <bits/stdc++.h>

using namespace std;

int d[100100];
vector <int> adj[100100];

void dfs(int u){
  int v;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(d[v] == -1){
      d[v] = d[u] + 1;
      dfs(v);
    }
  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, cpt, j, c, ans;
  while(1){
    ans = 0;
    cpt = 1;
    cin >> n;
    if(n == 0)  break;
    memset(d, -1, sizeof d);
    for(int i = 0; i < 100100; ++i) adj[i].clear();
    for(int i = 2; i <= n; ++i){
      cin >> j >> c;
      adj[i].push_back(j);
      adj[j].push_back(i);
      if(c != 0)  cpt = i;
    }
    d[cpt] = 0;
    dfs(cpt);
    for(int i = 1; i <= n; ++i) ans += d[i];
    cout << ans << "\n";
  }

  return 0;
}
