#include <bits/stdc++.h>

int main(){
  int n, k, ans;
  scanf("%d %d", &n, &k);
  if(n <= k)  ans = 2;
  else{
    n*=2;
    ans = n/k;
    if(n%k > 1) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
