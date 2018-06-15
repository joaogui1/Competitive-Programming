#include <bits/stdc++.h>

int v[1010];

int main(){
  int n, mai = 0, ans;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  for(int i = 2; i < n; ++i)
      if(v[i - 1] + v[i] + v[i + 1] > mai){
        mai = v[i - 1] + v[i] + v[i + 1];
        ans = i;
      }



  printf("%d %d\n", mai, ans);
  return 0;
}
