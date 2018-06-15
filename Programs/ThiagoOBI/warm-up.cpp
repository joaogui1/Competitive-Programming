#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
  return(b == 0)?(a):gcd(b, a%b);
}

ll f(ll x){
  int cont = 0;
  ll ret = 1;
  for(ll i = 2; i*i <= x; ++i){
    for(cont = 0; x % i == 0; ++cont){
      x /= i;
      ret *= i;
    }
    if(cont&1)  ret *= i;
  }
  if(x != 1)  ret *= x*x;
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll a, b, d;
  cin >> a >> b;
  if(b > a) swap(b, a);
  d = __gcd(a, b);

  cout << fixed << setprecision(0) << sqrt(f(d)) << "\n";
  return 0;
}
