#include <bits/stdc++.h>

using namespace std;

int mark[10100];
vector <int> adj[10100];

int dfs(int x){
  int ret = 1;
  mark[x] = 1;
  for(int v: adj[x])
    if(!mark[v])
      ret += dfs(v);
  return ret;
}

void initialize(int n){
  memset(mark, 0, sizeof mark);
  for(int i = 0; i <= n; ++i) adj[i].clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  int m, n, l, x, y, t, ans;
  cin >> t;
  while(t--){
    cin >> n >> m >> l;
    ans = 0;
    initialize(n);
    for(int i = 0; i < m; ++i){
      cin >> x >> y;
      adj[x].push_back(y);
    }
    while(l--){
      cin >> x;
      if(!mark[x])  ans += dfs(x);
    }
    cout << ans << "\n";
  }
  return 0;
}
