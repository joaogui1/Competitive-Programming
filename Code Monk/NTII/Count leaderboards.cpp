#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll bin[1010][1010], dp[1010], fac[1010];

void initialize(){
  for(int i = 0; i < 1010; ++i) bin[i][0] = 1, bin[i][1] = i, bin[i][i] = 1;
  for(int i = 2; i < 1010; ++i)
    for(int j = 2; j < i; ++j){
      bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
      if(bin[i][j] >= MOD)  bin[i][j] %= MOD;
    }
  fac[0] = 1LL;
  for(ll i = 1LL; i < 1010; ++i){
    fac[i] = i*fac[i - 1];
    if(fac[i] >= MOD) fac[i] %= MOD;
  }
  return;

}

ll f(ll n){
  if(dp[n] != -1)  return dp[n];
  ll aux;
  dp[n] = 0;
  for(int i = 0; i < n + 1; ++i){
    aux = bin[n - 1][i]*fac[i + 1];
    if(aux >= MOD)  aux %= MOD;
    dp[n] += aux*f(n - i - 1);
    if(dp[n] >= MOD)  dp[n] %= MOD;
  }
  return dp[n];
}

ll f(ll n, ll k){
  dp[0] = dp[1] = 1, dp[2] = 3;
  for(int i = 3; i < 1010; ++i) dp[i] = -1;
  return (f(n)*bin[n][k] % MOD);
}

int main(){
  ios_base::sync_with_stdio(0);
  ll n, k;
  cin >> n >> k;
  initialize();
  cout << f(n, k) << "\n";

  return 0;
}
