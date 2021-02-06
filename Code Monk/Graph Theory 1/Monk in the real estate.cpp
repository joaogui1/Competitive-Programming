#include <bits/stdc++.h>

using namespace std;

int mark[10010], cities[10010], ans;
vector <int>  adj[10010];

int dfs(int x){
  int ret = 1;
  mark[x] = 1;
  for(int i = 0; i < adj[x].size(); ++i)
    if(!mark[adj[x][i]])  ret += dfs(adj[x][i]);
  return ret;
}

void initialize(){
  ans = 0;
  memset(mark, 0, sizeof mark);
  memset(cities, 0, sizeof cities);
  for(int i = 0; i < 10010; ++i)  adj[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, e, aux, auy;
  cin >> t;
  while(t--){
    initialize();
    cin >> e;
    for(int i = 0; i < e; ++i){
      cin >> aux >> auy;
      adj[aux].push_back(auy);
      adj[auy].push_back(aux);
      cities[aux] = cities[auy] = 1;
    }
    for(int i = 0; i < 10001; ++i)
      if(!mark[i] && cities[i])  ans += dfs(i);
    cout << ans << "\n";
  }



  return 0;
}
