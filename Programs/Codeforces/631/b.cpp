#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> pll;

pll r[5010], c[5010];

int main(){
  ios_base::sync_with_stdio(0);
  ll n, m, k, q, op, a;
  cin >> n >> m >> k;
  for(int i = 1; i <= k; ++i){
    cin >> op >> q >> a;
    if(op == 1) r[q] = pll(a, i);
    else  c[q] = pll(a, i);
  }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      cout << ((c[j].ss > r[i].ss)?c[j].ff:r[i].ff) << " \n"[j == m];


  return 0;
}
