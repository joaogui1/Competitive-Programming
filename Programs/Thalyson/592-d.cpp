#include <bits/stdc++.h>

using namespace std;

set <int> tree;
vector <int> adj[123466], level[123466];
int p[123466], dist[123466], ana[123466], imp[123466];

void dfs_enum(int u){
  int v;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(v == p[u]) continue;
    p[v] = u;
    dist[v] = 1 + dist[u];
    level[dist[v]].push_back(v);
    dfs_enum(v);
  }
}

void dfs(int u){
  int v;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(dist[v] != -1 || !tree.count(v))  continue;
    dist[v] = 1 + dist[u];
    dfs(v);
  }
}

void dfs(){
  memset(dist, -1, sizeof dist);
  int um = *tree.begin();
  dist[um] = 0;
  dfs(um);
  int u = um, w = 0;
  for(const int &v: tree){
    if(dist[v] > dist[u]) u = v;
  }
  memset(dist, -1, sizeof dist);
  dist[u] = 0;
  dfs(u);
  for(const int &v: tree)
    if(dist[v] > dist[w]) w = v;
  // cout << u << " " << w << "\n";
  cout << min(u, w) << "\n" << (2*(tree.size() - 1) - dist[w]) << "\n";
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, u, v, brk;
  cin >> n >> m;
  for(int i = 1; i < n; ++i){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dist, -1, sizeof dist);
  dist[1] = 0;
  level[0].push_back(1);
  dfs_enum(1);
  for(int i = 0; i < m; ++i){
    cin >> u;
    imp[u] = ana[u] = 1;
  }


  for(int lv = 123457; lv > -1; --lv){
    brk = 0;
    for(int i = 0; i < level[lv].size(); ++i)
      if(ana[level[lv][i]])
        ++brk;

    if(m == 0 && brk == 1){
      for(int i = 0; i < level[lv].size(); ++i)
        if(ana[level[lv][i]] > 1)
          tree.insert(level[lv][i]);
      break;
    }
    for(int i = 0; i < level[lv].size(); ++i)
      if(ana[level[lv][i]]){
        if(imp[level[lv][i]])  --m;
        ++ana[p[level[lv][i]]];
        tree.insert(level[lv][i]);
      }
  }
  // for(auto v: tree)
  //   cout << v << " ";
  // cout << "\n";
  dfs();
  return 0;
}
