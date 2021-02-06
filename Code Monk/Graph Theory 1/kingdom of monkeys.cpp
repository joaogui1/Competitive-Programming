#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int mark[100100];
ll ban[100100], a[100100], best;
vector <int> adj[100100];

ll dfs(int x){
  mark[x] = 1;
  ban[x] = a[x];
  for(int i = 0; i < adj[x].size(); ++i)
    if(!mark[adj[x][i]])  ban[x] += dfs(adj[x][i]);
  return ban[x];
}

void initialize(){
  best = -1;
  memset(a, 0, sizeof a);
  memset(ban, 0, sizeof ban);
  memset(mark, 0, sizeof mark);
  for(int i = 0; i < 100100; ++i) adj[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, t, m, aux, auy;
  cin >> t;
  while(t--){
    initialize();
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
      cin >> aux >> auy;
      adj[aux].push_back(auy);
      adj[auy].push_back(aux);
    }

    for(int i = 1; i <= n; ++i)  cin >> a[i];
    for(int i = 1; i <= n; ++i){
      if(!mark[i])  best = max(dfs(i), best);
    }
    cout << best << "\n";
  }


  return 0;
}
