#include <bits/stdc++.h>

using namespace std;

int g[128][128];

int main(){
  int n, m, u, v, w, s;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i){
    scanf("%d %d %d", &u, &v, &w);
    g[u][v] = g[v][u] = w;
  }
  u = 1, v = 2, s = 3, w = g[1][2] + g[2][3] + g[1][3];
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      for(int k = 1; k <= n; ++k)
        if(i != j && j != k && k != i && (g[i][j] + g[j][k] + g[i][k] > w))
          u = i, v = j, s = k, w = g[i][j] + g[j][k] + g[i][k];

  printf("%d %d %d\n", u, v, s);



  return 0;
}
