#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> point;

int mark[128];
point pt[128];
vector<int> adj[128];

void dfs(int u){
  int v;
  mark[u] = 1;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!mark[v])  dfs(v);
  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = -1;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> pt[i].ff >> pt[i].ss;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(i != j && ((pt[i].ff == pt[j].ff) || (pt[i].ss == pt[j].ss)))
        adj[i].push_back(j);
  for(int i = 0; i < n; ++i){
    if(!mark[i])  dfs(i), ++ans;
  }
  cout << ans << "\n";
  return 0;
}
