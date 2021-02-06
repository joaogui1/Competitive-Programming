#include <bits/stdc++.h>

using namespace std;

int mark[1010], friends[1010];
vector <int> adj[1010];

int dfs(int x){
  mark[x] = 1;
  int ret = 1;
  for(int i = 0; i < adj[x].size(); ++i)
    if(!mark[adj[x][i]])  ret += dfs(adj[x][i]);
  return ret;
}

void initialize(){
  memset(mark, 0, sizeof mark);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, d, aux, auy, ans = 1100;
  cin >> n >> d;
  for(int i = 0; i < d; ++i){
    cin >> aux >> auy;
    friends[aux] = friends[auy] = 1;
    adj[aux].push_back(auy);
  }

  for(int i = 1; i <= 1000; ++i)
    if(friends[i]){
      initialize();
      ans = min(ans, dfs(i));
    }
  cout << ans << "\n";


  return 0;
}
