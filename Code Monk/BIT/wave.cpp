#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll ft[2][100100], ft_freq[100100] ,dp[2][100100];

void update(ll *ft_, ll x, ll val){
  for(; x <= 100100; x += x&(-x)){
    ft_[x] += val;
    ft_[x] %= MOD;
  }
  return;
}

ll query(ll *ft_, ll x){
  ll ret = 0;
  for(; x > 0; x -= x&(-x)){
    ret += ft_[x];
    ret %= MOD;
  }
  return ret;
}

ll query(ll *ft_, ll a, ll b){
  return (query(ft_, b) - query(ft_, a) + MOD)%MOD;
}

void init(){
  memset(ft, 0, sizeof ft);
  memset(ft_freq, 0, sizeof ft_freq);
  memset(dp, 0, sizeof dp);
}

int main(){
  ios_base::sync_with_stdio(0);
  ll n, aux;
  cin >> n;
  init();
  for(int i = 1; i <= n; ++i){
    cin >> aux;
    dp[0][i] = query(ft_freq, aux - 1)%MOD + query(ft[1], aux - 1)%MOD;
    dp[0][i] += MOD;
    dp[0][i] %= MOD;
    //cout << dp[0][i] << " ";
    dp[1][i] = query(ft_freq, aux, 100099)%MOD + query(ft[0], aux, 100099)%MOD;
    dp[1][i] += MOD;
    dp[1][i] %= MOD;
    //cout << dp[1][i] << endl;
    update(ft_freq, aux, 1);
    update(ft[0], aux, dp[0][i]);
    update(ft[1], aux, dp[1][i]);
    //cout << dp[0][n] << " " << dp[1][n] << endl;
  }
  //cout << dp[0][n] << " " << dp[1][n] << endl;
  cout << (query(ft[0], 100099) + query(ft[1], 100099))%MOD << "\n";
  return 0;
}
