#include <bits/stdc++.h>

using namespace std;

int g[128][128];

int main(){
  int n, x[2], y[2], ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d %d %d %d", &x[0], &x[1], &y[0], &y[1]);
    for(int j = x[0]; j < x[1]; ++j)
      for(int k = y[0]; k < y[1]; ++k)
        g[j][k] = 1;
  }
  for(int i = 1; i <= 100; ++i)
    for(int j = 1; j <= 100; ++j)
      ans += g[i][j];

  printf("%d\n", ans);
  return 0;
}
