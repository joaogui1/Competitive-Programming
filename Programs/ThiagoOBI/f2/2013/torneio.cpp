#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll fall_fac(ll n, ll k){
  ll ret = 1;
  for(int i = 0; i < k; ++i)
    ret = (ret*(n - i))%MOD;
  return ret;
}

ll f(ll n, ll k, ll los){
  ll ret = 1, aux;
  aux = 1 << (k - 1);
  ret *= (1 << n);
  ret *= fall_fac(los, aux - 1);
  ret %= MOD;
  ret *= fall_fac((1 << n) - aux, (1 << n) - aux);
  ret %= MOD;
  return ret;
}

int main(){
  ll n, k, los = 0, h, aux, ans = 0;
  scanf("%lld %lld", &n, &k);
  scanf("%lld", &h);
  for(int i = 1; i < (1 << n); ++i){
    scanf("%lld", &aux);
    if(aux < h) ++los;
  }
  ans = f(n, k, los) - f(n, k + 1, los);
  ans = ((ans%MOD) + MOD)%MOD;
  printf("%lld\n", ans);
}
