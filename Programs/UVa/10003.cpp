#include <bits/stdc++.h>

using namespace std;

int dp[64][64], A[64];

int f(int left, int right){
  if(left >= right - 1) return dp[left][right] = 0;
  if(dp[left][right] != -1) return dp[left][right];
  int ret = 1 << 29;
  for(int i = left + 1; i < right; ++i)
      ret = min(ret, f(left, i) + f(i, right) + A[right] - A[left]);
  return dp[left][right] = ret;
}

void initialize(){
  memset(A, 0, sizeof A);
  memset(dp, -1, sizeof dp);
  return;
}

int main(){
  int l, n;
  while(1){
    scanf("%d", &l);
    if(l == 0)  return 0;
    initialize();
    scanf("%d", &n);
    A[0] = 0;
    for(int i = 1; i <= n; ++i)  scanf("%d", &A[i]);
    A[n + 1] = l;
    printf("The minimum cutting is %d.\n", f(0, n + 1));

  }

  return 0;
}
