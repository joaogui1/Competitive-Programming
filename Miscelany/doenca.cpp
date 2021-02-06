#include <bits/stdc++.h>

using namespace std;

int dp[100100][4], mark[100100];
vector <int> adj[100100], child[100100];

void dfs(int u){
  mark[u] = 1;
  for(int i = 0; i < adj[u].size(); ++i){
    if(!mark[adj[u][i]]){
      child[u].push_back(adj[u][i]);
      dfs(adj[u][i]);
    }
  }
}

/*int vc(int u, int use){
  if(dp[u][use] != -1)  return dp[u][use];
  if(child[u].size() == 0)  return use;

  dp[u][use] = use;
  if(use)
    for(int i = 0; i < child[u].size(); ++i)
      dp[u][use] += min(vc(child[u][i], 0), vc(child[u][i], 1));
  else  for(int i = 0; i < child[u].size(); ++i)
      dp[u][use] += vc(child[u][i], 1);
  return dp[u][use];
}*/

int vc(int u, int ft_use){
  if(dp[u][ft_use] != -1)  return dp[u][ft_use];
  if(child[u].size() == 0)  return 1 - (ft_use > 1);

  int used = 1, not_used = 0;
  for(int i = 0; i < child[u].size(); ++i)
    used += vc(child[u][i], 2);
  if(ft_use == 0)
    return used;

  else if(ft_use == 1){

  }
  for(int i = 0; i < child[u].size(); ++i)
    used += vc(child[u][i], 1);
  else

}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, tr, a, b;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> tr >> tr;
  for(int i = 1; i < n; ++i){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 0; i <= n ; ++i)
    for(int j = 0; j < 4; ++j)
      dp[i][j] = -1;
  dfs(1);
  cout << n - min(vc(1, 0), vc(1, 1)) << "\n";





  return 0;
}
