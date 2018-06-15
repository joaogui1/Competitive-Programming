#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;

ll n;
pll b[100100], a[100100];

bool test(ll v, ll k){
  for(int i = 0; i < n; ++i)  a[i] = b[i];
  for(int i = 0; i < n; ++i){
    if(a[i].ss/a[i].ff >= v) continue;
    if(k >= a[i].ff - (a[i].ss % a[i].ff)){
      k -= a[i].ff - (a[i].ss % a[i].ff);
      a[i].ss += a[i].ff - (a[i].ss % a[i].ff);
    }
    else  return 0;
    if(a[i].ss/a[i].ff == v)  continue;
    if(k < (v - a[i].ss/a[i].ff)*a[i].ff) return 0;
    k -= (v - a[i].ss/a[i].ff)*a[i].ff;
    a[i].ss = v*a[i].ff;
  }
  return 1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll ans = 0, aux, sum = 0, ini = 0, fim, m, k;
  cin >> n >> k;
  fim = 2000000010;
  for(int i = 0; i < n; ++i)  cin >> b[i].ff;
  for(int i = 0; i < n; ++i)  cin >> b[i].ss;
  while(fim - ini > 1){
    m = (ini + fim)/2;
    if(test(m, k)){
      if(!test(m + 1, k))  break;
      ini = m;
    }
    else  fim = m;
  }
  if(test(m, k)){
    if(test(m + 1, k)) cout << m + 1 << "\n";
    else  cout << m << "\n";
  }
  else  cout << max(m - 1, 0LL) << "\n";
  return 0;
}
