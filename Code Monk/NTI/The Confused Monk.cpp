#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll v[64];

ll gcd(ll a, ll b){
  return(b == 0)?(a):gcd(b, a%b);
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  ll f, g, aux, ans = 1LL;
  cin >> n >> f;
  g = f;
  while(--n){
    cin >> aux;
    f *= aux;
    if(f >= 1000LL*MOD)  f %= MOD;
    if(aux < g) swap(aux, g);
    g = gcd(aux, g);
  }
  f %= MOD;
  for(int i = 0; i < g; ++i){
    ans *= f;
    if(ans > MOD) ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}
