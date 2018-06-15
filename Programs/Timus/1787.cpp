#include <bits/stdc++.h>

int main(){
  int n, k, tot = 0, a;
  scanf("%d %d", &k, &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a);
    tot += a;
    tot -= k;
    if(tot < 0) tot = 0;
  }
  printf("%d\n", tot);


  return 0;
}
