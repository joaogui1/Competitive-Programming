#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

int ft[2048];
pii ans[2048];

void upd(int x){
  for(; x < 2048; x += x&-x)  ++ft[x];
}

int query(int x){
  int ret = 0;
  for(; x > 0; x -= x&-x) ret += ft[x];
  return ret;
}

int query(int a, int b){
  return query(b) - query(a - 1);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a;
    ans[a].ff = query(a, 2047) + 1;
    ans[a].ss = n - (a - 1 - query(a));
    upd(a);
  }
  for(int i = 1; i <= n; ++i)
    cout << ans[i].ff << " " << ans[i].ss << "\n";
  return 0;
}
