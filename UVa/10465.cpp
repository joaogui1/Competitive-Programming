#include <bits/stdc++.h>

using namespace std;

int dp[10010], best;

void initialize(){
  best = -1;
  memset(dp, -1, sizeof dp);
  return;
}

int main(){
  int n, m, t;
  while(scanf("%d", &n) != EOF){
    scanf("%d %d", &m, &t);
    initialize();

    dp[0] = 0;
    for(int i = 0; i < t + 1; ++i){
      if(i >= n && dp[i - n] != -1) dp[i] = max(dp[i], dp[i - n] + 1);
      if(i >= m && dp[i - m] != -1) dp[i] = max(dp[i], dp[i - m] + 1);
      if(dp[i] != -1) best = i;
    }
    printf("%d", dp[best]);
    if(t - best > 0)  printf(" %d", t - best);
    printf("\n");
  }



  return 0;
}
