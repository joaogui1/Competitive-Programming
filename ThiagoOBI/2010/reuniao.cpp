#include <bits/stdc++.h>
#define INF (1 << 28)

using namespace std;

int G[128][128];

void fw(int n){
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
  return;
}

int main(){
  int n, m, u, v, w, test = 0, best = INF;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      G[i][j] = INF;
  for(int i = 0; i < m; ++i){
    scanf("%d %d %d", &u, &v, &w);
    G[u][v] = G[v][u] = min(G[u][v], w);
  }
  fw(n);

  for(int i = 0; i < n; ++i){
    test = -1;
    for(int j = 0; j < n; ++j)  test = max(test, G[i][j]);
    if(test < best) best = test;
  }
  printf("%d\n", best);
  return 0;
}
