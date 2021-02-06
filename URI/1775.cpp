#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010], mentos[1010];

int f(int beg, int fim){
  if(beg > fim) return 0;
  if(beg == fim)  return 1;
  if(dp[beg][fim] != 0) return dp[beg][fim];
  if(mentos[beg] == mentos[fim])  return dp[beg][fim] = 1 + f(beg + 1, fim - 1);
  return dp[beg][fim] = 1 + min(f(beg + 1, fim), f(beg, fim - 1));
}

int main(){
  int n, t;
  scanf("%d", &t);
  for(int q = 1; q <= t; ++q){
    memset(dp, 0, sizeof dp);
    memset(mentos, 0, sizeof mentos);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)  scanf("%d", &mentos[i]);
    printf("Caso #%d: %d\n",q,  f(0, n - 1));
  }


  return 0;
}
