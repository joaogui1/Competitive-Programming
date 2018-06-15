#include <bits/stdc++.h>

using namespace std;

int G[512][1024];

int main(){
  int ans = 0, n, x, y;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d %d", &x, &y);
    ++G[x][y];
    if(G[x][y] > 1) ans = 1;
  }

  printf("%d\n", ans);
  return 0;
}
