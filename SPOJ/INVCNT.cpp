#include <bits/stdc++.h>
#define MAXN 10000010
using namespace std;
typedef long long int ll;

ll ft[MAXN], ans;

void upd(int x){
  for(; x < MAXN; x += x&-x)  ++ft[x];
}

ll query(int x){
  ll ret = 0;
  for(; x > 0; x -= x&-x) ret += ft[x];
  return ret;
}

ll query(int x, int y){
  return query(y) - query(x - 1);
}

void initialize(){
  ans = 0;
  memset(ft, 0, sizeof ft);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t, n, a;
  cin >> t;
  while(t--){
    cin >> n;
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> a;
      ans += query(a, MAXN - 1);
      upd(a);
    }
    cout << ans << "\n";
  }

  return 0;
}
