#include <bits/stdc++.h>

using namespace std;

int dp[110][110], tower[2][110];

int main(){
  int n[4], cont = 0;
  while(1){
    scanf("%d %d", &n[0], &n[1]);
    if(n[0] == 0 && n[1] == 0)  break;
    ++cont;
    memset(dp, 0, sizeof dp);
    memset(tower, 0, sizeof tower);

    for(int j = 0; j < 2; ++j)
      for(int i = 0; i < n[j]; ++i) scanf("%d", &tower[j][i]);

    for(int i = 0; i < n[1]; ++i) dp[0][i] = (tower[0][0] == tower[1][i]);
    for(int i = 0; i < n[0]; ++i) dp[i][0] = (tower[1][0] == tower[0][i]);

    for(int i = 1; i < n[0]; ++i)
      for(int j = 1; j < n[1]; ++j){
        if(tower[0][i] == tower[1][j])  dp[i][j] = 1 + dp[i - 1][j - 1];
        else  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }

      printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cont, dp[n[0] - 1][n[1] - 1]);
  }


  return 0;
}
