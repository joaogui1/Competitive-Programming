#include <bits/stdc++.h>

using namespace std;

int g[256][256];

void fw(int n){
  int test, best = (1 << 28);
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for(int i = 1; i <= n; ++i){
    test = -1;
    for(int j = 1; j <= n; ++j) test = max(test, g[i][j]);
    best = min(best, test);
  }
  printf("%d\n", best);
  return;
}

int main(){
  int s, c, a, b, d;
  scanf("%d %d", &s, &c);

  for(int i = 0; i <= s; ++i)
    for(int j = 0; j <= s; ++j)
      if(i != j)
        g[i][j] = (1 << 28);

  for(int i = 0; i < c; ++i){
    scanf("%d %d %d", &a, &b, &d);
    g[a][b] = g[b][a] = d;
  }
  fw(s);


  return 0;
}
