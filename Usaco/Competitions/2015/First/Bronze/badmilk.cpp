#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;

ll milks[64], folks[64];
vector<ppi> ev;

int main(){
  ios_base::sync_with_stdio(0);
  ifstream fin ("badmilk.in");
  ofstream fout ("badmilk.out");
  int best = 0;
  ll sick = 0;
  int n, m, d, s, x, y, z;
  fin >> n >> m >> d >> s;
  ll ans = 1LL << (m + 1);
  --ans;
  for(int i = 0; i < d; ++i){
    fin >> x >> y >> z;
    --x, --y;
    ev.push_back(ppi(pii(z, 1), pii(x, y)));
  }
  for(int i = 0; i < s; ++i){
    fin >> x >> y;
    --x;
    ev.push_back(ppi(pii(y, 0), pii(x, 0)));
  }

  sort(ev.begin(), ev.end());
  for(int i = 0; i < ev.size(); ++i){
    if(ev[i].ff.ss == 1){
      folks[ev[i].ss.ff] |= (1LL << ev[i].ss.ss);
      milks[ev[i].ss.ss] |= (1LL << ev[i].ss.ff);
    }

    else
      ans &= folks[ev[i].ss.ff];

  }
  for(ll i = 0; i < m + 1; ++i)
    if(ans & (1LL << i))
      sick |= milks[i];


  for(ll i = 0; i <= n; ++i)
    if(sick & (1LL << i)) ++best;

  fout << best << "\n";
  return 0;
}
