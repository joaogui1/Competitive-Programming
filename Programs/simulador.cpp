#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

vector <pll> inv;

ll sum(ll a, ll b){
   if(a > b)   swap(a, b);
   return b*(b+1LL)/2LL - (a - 1LL)*a/2LL;
}

ll ans(ll a, ll b, ll cont){
   if(b < a)   return 0;
   if(cont == -1)  return sum(a, b);

   ll x = inv[cont].ff, y = inv[cont].ss;

   if((y < a || x > b) || (x >= a && y <= b))   return ans(a, b, cont - 1);

   if(y <= b)   return ans(y + 1, b, cont - 1) + ans(x, x + y - a, cont - 1);

   if(a <= x)   return ans(a, x - 1, cont - 1) + ans(x + y - b, y, cont - 1);

   return ans(x + y - b, x + y - a, cont - 1);
}

int main(){
  ios_base::sync_with_stdio(0);
  char op;
  int n, m;
  ll aux, auy;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> op >> aux >> auy;
    if(op == 'I')
      inv.push_back(pll(aux, auy));

    else
      cout << ans(aux, auy, inv.size() - 1) << "\n";
   }
   return 0;
}
