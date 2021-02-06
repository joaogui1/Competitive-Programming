#include <bits/stdc++.h>

using namespace std;

int dp[2][100100];
vector <int> adj[100100], ch[100100];

void dfs(int x){
  int v;
  for(int i = 0; i < adj[x].size(); ++i){
    v = adj[x][i];
    if(ch[v].size() == 0){
      ch[x].push_back(v);
      dfs(v);
    }
  }
  return;
}

/*int f(int use, int x){
  int v;
  if(dp[use][x] != -1)  return dp[use][x];
  if(use == 0){
    dp[use][x] = 0;
    for(int i = 0; i < ch[x].size(); ++i){
      v = ch[x][i];
      dp[use][x] += f(1, v);
    }
  }
  if(use == 1){
    dp[use][x] = 1;
    for(int i = 0; i < ch[x].size(); ++i){
      v = ch[x][i];
      dp[use][x] += min(f(0, v), f(1, v));
    }
  }
  return dp[use][x];
}*/

int g(int use, int x){
  int v, sum = 0;
  if(dp[use][x] != -1)  return dp[use][x];
  if(use == 0){
    dp[use][x] = (1 << 28);
    for(int i = 0; i < ch[x].size(); ++i){
      v = ch[x][i];
      sum += g(0, v);
    }
    for(int i = 0; i < ch[x].size(); ++i){
      v = ch[x][i];
      dp[use][x] = min(dp[use][x], sum + g(1, v) - g(0, v));
    }
  }
  if(use == 1){
    dp[use][x] = 1;
    for(int i = 0; i < ch[x].size(); ++i){
      v = ch[x][i];
      dp[use][x] += min(g(0, v), g(1, v));
    }
  }
  return dp[use][x];
}

int main(){
  int n, u, v;
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", &u, &v);
  for(int i = 1; i < n; ++i){
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << max(g(0, 1), g(1, 1)) << "\n";
  return 0;
}
