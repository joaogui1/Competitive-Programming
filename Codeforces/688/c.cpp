#include <bits/stdc++.h>

using namespace std;

int color[100100];
vector <int> adj[100100], ans;

bool dfs(int u, int c){
  int v;
  color[u] = c;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(color[v] == color[u])  return 0;
    if(color[v] == 0 && !dfs(v, 3 - c)) return 0;
  }
  return 1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a, b, vdc = 1;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 1; i <= n; ++i)
    if(adj[i].size() > 0 && color[i] == 0) vdc &= dfs(i, 1);
  if(!vdc)  cout << -1 << "\n";
  else{
    for(int i = 1; i <= n; ++i)
      if(color[i] == 1) ans.push_back(i);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i == ans.size() - 1];
    ans.clear();
    for(int i = 1; i <= n; ++i)
      if(color[i] == 2) ans.push_back(i);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i == ans.size() - 1];
  }

  return 0;
}
