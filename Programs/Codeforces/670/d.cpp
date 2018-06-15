#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;

pll a[100100];
vector <ppl> s;

bool cmp(pll b, pll c){
  ll cc, bb;
  bb = b.ff - (b.ss % b.ff);
  cc = c.ff - (c.ss % c.ff);
  return bb < cc;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, k, ans = 0, aux, sum = 0;
  cin >> n >> k;
  for(int i = 0; i < n; ++i)  cin >> a[i].ff;
  for(int i = 0; i < n; ++i)  sum += a[i].ff;
  for(int i = 0; i < n; ++i)  cin >> a[i].ss;
  for(int i = 0; i < n; ++i)  s.push_back(ppl(pll(a[i].ss/a[i].ff, a[i].ff - (a[i].ss % a[i].ff)), a[i].ff));
  sort(s.begin(), s.end());

  for(int i = 0; i < n - 1; ++i){
    if(s[i + 1].ff.ff <= s[i].ff.ff){
      if(k >= s[i + 1].ff.ss*s[i + 1].ss + s[i].ff.ss*s[i].ss){
        k -= s[i + 1].ff.ss*s[i + 1].ss + s[i].ff.ss*s[i].ss);
        ++s[i + 1].ff.ff;
        s[i + 1].ff.ss = 0;
        s[i + 1].ss += s[i].ss;
        continue;
      }
      else{
        k = 0;
        ans = s[i].ff.ff;
        break;
      }
    }

    if(k)

    else if(k >= (s[i + 1].ff.ff - s[i].ff.ff)*s[i].ss){
      s[i + 1].ss += s[i].ff;
      k -= (s[i + 1].ff - s[i].ff)*s[i].ss;
    }
    else{
      s[i].ff += k/s[i].ss;
      k = 0;
      ans = s[i].ff;
      break;
    }
  }
  if(n == 1)  ans = s[0].ff;
  aux = k/sum;
  cout << aux << endl;
  cout << ans + aux << "\n";
  return 0;
}
