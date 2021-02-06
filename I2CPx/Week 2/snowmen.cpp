#include <bits/stdc++.h>
#define ff first
#define ss second
// #define DEBUG 1
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

pll snow[1 << 20];

int main(){
  #ifndef DEBUG
    ifstream fin ("snowmen.in");
    ofstream fout ("snowmen.out");
    cin.tie(0);
    ios_base::sync_with_stdio(0);
  #endif
  ll ans = 0;
  int n, t, m;
  fin >> n;
  for(int i = 1; i <= n; ++i){
    fin >> t >> m;
    if(m > 0){
      snow[i].ff = snow[t].ff + m;
      snow[i].ss = t;
    }
    else{
      snow[i] = snow[snow[t].ss]  ;
    }
    ans += snow[i].ff;
  }
  fout << ans << "\n";
  return 0;
}
