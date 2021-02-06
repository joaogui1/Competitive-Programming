#include <bits/stdc++.h>

using namespace std;

int dist[2048];
vector<int> adj[2048];

void dfs(int u){
  int v;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(dist[v] == -1){
      dist[v] = 1 + dist[u];
      dfs(v);
    }
  }
  return;
}

int ans(int n){
  int u = 0;
  memset(dist, -1, sizeof dist);
  dist[0] = 0;
  dfs(0);
  for(int i = 1; i <= n; ++i)
    if(dist[i] > dist[u]) u = i;
  return dist[u];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a;
    if(a == -1) ++a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  cout << ans(n) << "\n";
  return 0;
}
