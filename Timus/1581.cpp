#include <bits/stdc++.h>

int v[1010];

int main(){
  int n, rep, k;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)  scanf("%d", &v[i]);
  k = v[0], rep = 1;
  for(int i = 1; i < n; ++i){
    if(k != v[i]){
      printf("%d %d ",rep, k);
      rep = 1;
      k = v[i];
    }
    else  ++rep;
  }

  printf("%d %d\n", rep, k);
  return 0;
}
