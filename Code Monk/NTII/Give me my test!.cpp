#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

ll bin[128][128], fac[128], inv_fac[128];

ll inverse(ll a, ll b){
  ll t = 0, nt = 1, q, aux;
  while(b != 0){
    q = a/b;
    aux = nt;
    nt = t - q*nt;
    t = aux;
    aux = b;
    b = a - q*b;
    a = aux;
  }
  return t;
}


void precalc(){
  for(int i = 0; i < 128; ++i)  bin[i][0] = bin[i][i] = 1;
  for(int i = 0; i < 128; ++i)  bin[i][1] = i;

  for(int i = 2; i < 128; ++i)
    for(int j = 2; j < i; ++j){
      bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
      if(bin[i][j] >= MOD)  bin[i][j] %= MOD;
    }
  fac[0] = 1;
  for(int i = 1; i < 128; ++i){
    fac[i] = i*fac[i - 1];
    if(fac[i] >= MOD) fac[i] %= MOD;
  }
  for(int i = 0; i < 128; ++i){
    inv_fac[i] = inverse(MOD, fac[i]);
    if(inv_fac[i] < 0)  inv_fac[i] += MOD;
  }

  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  ll n, l, r, ans = 0, aux, fat;
  cin >> n >> l >> r;
  precalc();
  for(int i = l; i <= r; ++i){
    aux = 0;

    for(int j = 0; j <= i; ++j){
      if(j % 2 == 0)  aux += (fac[i - j]*bin[i][j])%MOD;
      else  aux -= (fac[i - j]*bin[i][j])%MOD;
      aux %= MOD;
    }

    ans += bin[n][i]*aux;
    ans %= MOD;
  }
  ans *= inv_fac[n];
  ans %= MOD;
  if(ans < 0) ans += 10LL*MOD;
  cout << ans%MOD << "\n";

  return 0;
}
