#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> pll;

vector <pll> pos;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("cowjog.in");
  ofstream fout ("cowjog.out");
  ll n, t, po, s, sl, ans = 1;
  fin >> n >> t;

  for(int i = 0; i < n; ++i){
    fin >> po >> s;
    pos.push_back(pll(po, s));
  }
  for(int i = 0; i < n; ++i)  pos[i].ff += t*pos[i].ss;
  sl = pos[n - 1].ff;

  for(int i = n - 1; i > -1; --i){
    if(pos[i].ff < sl)  ++ans;
    sl = min(sl, pos[i].ff);
  }
  fout << ans << "\n";

  return 0;
}
