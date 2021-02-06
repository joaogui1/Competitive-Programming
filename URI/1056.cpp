#include <bits/stdc++.h>

using namespace std;

int cor[128], ma[128];
vector <int> a, b, adj[128];

int arg(int u){
  int v;
  if(cor[u])  return 0;
  cor[u] = 1;

  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(ma[v] == -1 || arg(ma[v])){
      ma[v] = u;
      return 1;
    }
  }
  return 0;
}

void initialize(){
  memset(ma, -1, sizeof ma);
  for(int i = 0; i < 128; ++i)  adj[i].clear();
}

int main(){
  int T, t, n, m, ans;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    ans = 0;
    cin >> n;
    initialize();
    a.assign(n, 0);
    for(int i = 0; i < n; ++i)  cin >> a[i];
    cin >> m;
    b.assign(m, 0);
    for(int i = 0; i < m; ++i)  cin >> b[i];
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        if((a[i] != 0 && b[j]%a[i] == 0) || b[j] == 0)  adj[i].push_back(j);

    for(int i = 0; i < n; ++i){
      ans += arg(i);
      memset(cor, 0, sizeof cor);
    }
    cout << "Case " << t << ": " << ans << "\n";
  }




  return 0;
}
