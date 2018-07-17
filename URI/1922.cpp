#include <bits/stdc++.h>

using namespace std;

int G[1010][1010], c[1010], k[1010];

void debug(int n){
  for(int i = 1; i <= 32; ++i){
    for(int j = 0; j <= n; ++j)
      printf("%d ", G[i][j]);
    printf("\n");
  }

  printf("\n\n\n\n");
  return;
}

int main(){
  int n, m, aux, auk, max_day, max_val, ans = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf("%d %d", &aux, &auk);
    c[i + 1] = aux;
    k[i + 1] = auk/aux;
    for(int j = 1; j <= k[i + 1]; ++j) ++G[aux*j][i + 1], ++G[aux*j][0];
  }

  for(int i = 0; i < m; ++i){
    max_day = 0, max_val = 0;
    //debug(n);
    for(int j = 1; j <= 1001; ++j)
      if(G[j][0] > max_val){
        max_day = j;
        max_val = G[j][0];
      }
    ans += max_val;

    for(int j = 1; j <= n; ++j)
      if(G[max_day][j] == 1){
        G[max_day][j] = 0;
        for(int q = 1; q <= k[j]; ++q)  G[q*c[j]][j] = 0, --G[q*c[j]][0];
      }

  }

  printf("%d\n", ans);
  return 0;
}
