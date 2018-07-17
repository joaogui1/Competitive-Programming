#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool is_compos[1 << 20];
vector <ll> div_p[1 << 20];

void find_primes(){
  for(ll i = 2; i < 1000000; ++i)
    if(!is_compos[i])
      for(int j = i << 1; j < 1000000; j += i)
        is_compos[j] = 1;
}

ll phi(ll x, vector<ll> &primes){
  ll ret = x;
  for(ll const p : primes){
    if(x % p == 0){
      for(; x % p == 0; x /= p);
      ret /= p;
      ret *= (p - 1);
    }
  }
  ret /= x;
  if(x > 1) ret *= (x - 1);
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  double ans;
  ll l, r, k, sd;
  cin >> t;
  find_primes();
  while(t--){
    ans = 0;
    cin >> l >> r >> k;

    for(ll i = l; i < r + 1; ++i) div_p[i - l].clear();

    for(ll i = 2; i < 1000001; ++i){
      if(is_compos[i])  continue;

      sd = l/i*i;
      if(l % i > 0) sd += i;
      for(ll j = sd; j < r + 1; j += i)
        div_p[j - l].push_back(i);
    }

    for(ll i = l; i < r + 1; ++i){
      if(phi(i, div_p[i - l]) % k == 0) ++ans;
      //cout << i << " " << phi(i) << endl;
    }
    cout << fixed << setprecision(6) << ans/(r - l + 1) << "\n";
  }

  return 0;
}
