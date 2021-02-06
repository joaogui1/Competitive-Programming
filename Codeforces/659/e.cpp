#include <bits/stdc++.h>

using namespace std;

int mark[100100];
vector <int> adj[100100];
pair <int, int> edges[100100];

void dfs(int x, int c){
  mark[x] = 1;
  ++edges[c].first;
  edges[c].second += adj[x].size();
  for(int const &v: adj[x])
    if(!mark[v])  dfs(v, c);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int a, b, n, m, ans = 0, colors = 0;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <=  n; ++i)
    if(!mark[i])  dfs(i, ++colors);
  for(int i = 1; i <= colors; ++i)
    if(edges[i].second == 2*(edges[i].first - 1)) ++ans;
  cout << ans << "\n";
  return 0;
}
