#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

ll dp[128][128], k;

ll f(ll n, ll d){
  if(n < d) return 0;
  if(n == 0)  return 1;
  if(dp[n][d] != -1) return dp[n][d];
  dp[n][d] = 0;
  for(int i = 1; i <= k && i <= n; ++i){
    if(i < d) dp[n][d] += f(n - i, d);
    else  dp[n][d] += f(n - i, 0);
    dp[n][d] %= MOD;
  }
  return dp[n][d];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, d;
  cin >> n >> k >> d;
  memset(dp, -1, sizeof dp);

  cout << f(n, d) << "\n";
  return 0;
}
