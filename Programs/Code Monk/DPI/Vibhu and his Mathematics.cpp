#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll dp[1000010];

ll f(ll x){
  if(x == 1)  return 1;
  if(x == 2)  return 2;
  if(dp[x] != -1) return dp[x];
  dp[x] = f(x - 1) + (x - 1)*f(x - 2);
  if(dp[x] >= MOD)  dp[x] %= MOD;
  return dp[x];
}

int main(){
  ios_base::sync_with_stdio(0);
  ll n;
  int t;
  cin >> t;
  dp[1] = 1, dp[2] = 2;
  for(int i = 3; i < 1000001; ++i){
    dp[i] = dp[i - 1] + (i - 1)*dp[i - 2];
    if(dp[i] >= MOD)  dp[i] %= MOD;
  }
  while(t--){
    cin >> n;
    cout << dp[n] << "\n";
  }
  return 0;
}
