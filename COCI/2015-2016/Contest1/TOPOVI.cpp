#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

ll freq[4][1 << 20];
map <ll, ll> lines[4];
map<pll, ll> power;

int main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  ll n, k, p, r, c, x, ans = 0;
  cin >> n >> k >> p;
  freq[0][0] = freq[1][0] = n;
  for(int i = 0; i < k; ++i){
    cin >> r >> c >> x;
    power[pll(r, c)] = x;

    if(lines[0].count(r)){
      --freq[0][lines[0][r]];
      lines[0][r] ^= x;
    }
    else{
      --freq[0][0];
      lines[0][r] = x;
    }
    ++freq[0][lines[0][r]];

    if(lines[1].count(c)){
      --freq[1][lines[1][c]];
      lines[1][c] ^= x;
    }
    else{
      --freq[1][0];
      lines[1][c] = x;
    }
    ++freq[1][lines[1][c]];

  }

  for(auto el: lines[0])
    if(el.ss != 0)  ans += n - freq[1][el.ss];
  for(auto el: lines[1])
    if(el.ss != 0)  ans += n - freq[0][el.ss];
  cout << "ok\n";
  for(int i = 0; i < p; ++i){
    cin >> r >> c;
    ans -= n - freq[1][lines[0][r]];
    ans -= n - freq[0][lines[1][c]];
    --freq[0][lines[0][r]];
    --freq[1][lines[1][c]];
    x = power[pll(r, c)];
    power[pll(r, c)] = 0;
    lines[0][r] ^= x;
    lines[1][c] ^= x;

    cin >> r >> c;
    power[pll(r, c)] = x;
    lines[0][r] ^= x;
    lines[1][c] ^= x;
    ++freq[0][lines[0][r]];
    ++freq[1][lines[1][c]];
    ans += n - freq[1][lines[0][r]];
    ans += n - freq[0][lines[1][c]];
    cout << ans << "\n";
  }


  return 0;
}
