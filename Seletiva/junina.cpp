#include <bits/stdc++.h>

using namespace std;

int G[32], n;

int f(){
  int ans = 0, test;
  for(int mask = 0; mask < (1 << n); ++mask){
    test = 0;
    for(int i = 0; i < n; ++i){
      if((mask&(1 << i)) != 0 && (G[i]&mask)) break;
      if(i == n - 1)
        for(int shadow = mask; shadow > 0; shadow -= shadow&-shadow)++test;
    }
    ans = max(ans, test);
  }
  return ans;
}

int main(){
  int en;
  for(int t = 1; scanf("%d", &n); ++t){
    if(n == 0)  return 0;
    memset(G, 0, sizeof G);
    for(int i = 0; i < n; ++i)
      while(1){
        scanf("%d", &en);
        if(en == 0) break;
        --en;
        G[i] |= (1 << en);
      }
    printf("Teste %d\n%d\n\n", t, f());
  }


  return 0;
}
