#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

vector <pll> s, t;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, f;
  ll a, ans;
  while(1){
    f = 0;
    ans = 0;
    s.clear();
    t.clear();
    cin >> n;
    if(n == 0)  return 0;
    for(int i = 0; i < n; ++i){
      cin >> a;
      if(a > 0) t.push_back(pll(a, i));
      if(a < 0) s.push_back(pll(-a, i));
    }

    for(int i = 0; i < s.size(); ++i){
      for(; f < t.size(); ++f){
        if(s[i].ff >= t[f].ff){
          ans += abs(s[i].ss - t[f].ss)*t[f].ff;
          s[i].ff -= t[f].ff;
          t[f].ff = 0;
        }
        else{
          ans += abs(s[i].ss - t[f].ss)*s[i].ff;
          t[f].ff -= s[i].ff;
          s[i].ff = 0;
          break;
        }
      }
    }
    cout << ans << "\n";
  }


  return 0;
}
