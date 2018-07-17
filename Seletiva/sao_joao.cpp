#include <bits/stdc++.h>

using namespace std;
int distx[100100], disty[100100], dist[100100], distpo;
vector <int> adj[100100];

void dfs(int x){

  for(int i = 0; i < adj[x].size(); ++i){
    if(dist[adj[x][i]] == 0){
        dist[adj[x][i]] = dist[x] + 1;
        dfs(adj[x][i]);
    }
  }

  return;
}

void init(int pox){
  memset(dist, 0, sizeof dist);
  dist[pox] = 1;
  distpo = 0;
  dfs(pox);
  return;
}

int main(){
  //ios_base::sync_with_stdio(0);
  int n, aux, auy, pox, poy, q, a, m, ans;
  scanf("%d", &n);
  for(int i = 1; i < n; ++i){
    scanf("%d %d", &aux, &auy);
    adj[aux].push_back(auy);
    adj[auy].push_back(aux);
  }

  init(1);

  for(int i = 1; i <= n; ++i){
    if(dist[i] > distpo){
      distpo = dist[i];
      pox = i;
    }
  }

  init(pox);

  for(int i = 1; i <= n; ++i){
     distx[i] = dist[i] - 1;
     if(dist[i] > distpo){
       distpo = dist[i];
       poy = i;
     }
     
  }

  init(poy);
  for(int i = 1; i <= n; ++i) disty[i] = dist[i] - 1;

  scanf("%d", &q);
  while(q--){
    scanf("%d %d", &a, &m);
    if(m <= max(distx[a], disty[a])) printf("%d\n", m + 1);
    else{
      ans = max(distx[a], disty[a]) + 1;
      m -= (ans - 1);
      ans += (m/2);
      ans = min(ans, n);
      printf("%d\n", ans);
    }
  }

  return 0;
}
