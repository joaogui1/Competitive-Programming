#include <bits/stdc++.h>

typedef long long int ll;

int v[110];
ll dp[110][110];

ll f(int n, int k){
  if(k - 2 > n) return dp[n][k] = 0;
  if(k == 1)  return dp[n][k] = 1;
  if(dp[n][k] != -1)  return dp[n][k];

  ll ret = 0LL;
  for(int i = 0; i < n; ++i)
    if(v[i] < v[n]) ret += f(i, k - 1);
  return dp[n][k] = ret;
}

ll f(int n, int k, int dummy){
  ll ret = 0LL;
  for(int i = 0; i < n; ++i)  ret += f(i, k);
  return ret;
}

int main(){
  int n, k;
  while(1){
    scanf("%d %d", &n, &k);
    if(n == 0 && k == 0)  break;

    memset(v, 0, sizeof v);
    for(int i = 0; i < n; ++i)  scanf("%d", &v[i]);
    for(int i = 0; i < 110; ++i)  for(int j = 0; j < 110; ++j)  dp[i][j] = -1LL;
    printf("%lld\n", f(n, k, 0));

  }


  return 0;
}
