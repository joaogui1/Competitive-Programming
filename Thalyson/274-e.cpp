#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

ll dp[5010][2], sum[5010][2];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, a, b;
  cin >> n >> a >> b >> k;
  for(int i = 1; i <= n; ++i) dp[i][0] = 1, sum[i][0] = sum[i - 1][0] + dp[i][0];
  for(int j = 1; j <= k; ++j){
    for(int i = 1; i <= n; ++i){
      dp[i][j&1] = sum[min(n, i + abs(b - i) - 1)][(j - 1)&1] - sum[max(0, i - abs(b - i))][(j - 1)&1] - dp[i][(j - 1)&1]; //temos a soma dos valores do ponto mais baixo q ele pode ir até o mais alto menos o valor de ficar no mesmo lugar
      dp[i][j&1] = (dp[i][j&1] + 3*MOD)%MOD;
    }
    for(int i = 1; i <= n; ++i) sum[i][j&1] = (sum[i - 1][j&1] + dp[i][j&1] + MOD)%MOD;
  }
  cout << dp[a][k&1] << "\n";

  return 0;
}
