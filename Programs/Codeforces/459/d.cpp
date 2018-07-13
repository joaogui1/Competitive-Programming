#include <bits/stdc++.h>


using namespace std;
typedef long long int ll;

vector <int> comp;
ll ft[1000001], v[1000001], l[1000001], r[1000001], cnt[1000001];

void upd(int x, int v){
  if(x == 0)  return;
  for(; x < 1000001; x += x&(-x)) ft[x] += v;
}

ll query(int x){
  int ret = 0;
  for(; x > 0; x -= x&(-x)) ret += ft[x];
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  ll ans = 0;
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> v[i], comp.push_back(v[i]);
  sort(comp.begin(), comp.end());
  comp.resize(distance(comp.begin(),unique(comp.begin(), comp.end())));
  for(int i = 0; i < n; ++i)  v[i] = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin();

  for(int i = 0; i < n; ++i)  l[i] = ++cnt[v[i]];
  memset(cnt, 0, sizeof cnt);
  for(int i = n - 1; i > -1; --i)  r[i] = ++cnt[v[i]];
  for(int i = n - 1; i > -1; --i){
    ans += query(l[i] - 1);
    upd(r[i], 1);
  }
  cout << ans << "\n";
  return 0;
}
