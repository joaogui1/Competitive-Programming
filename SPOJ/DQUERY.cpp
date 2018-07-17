#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

ppi qu[1 << 18];
int ft[1 << 20], pos[1 << 20], v[1 << 20], ans[1 << 20];

void upd(int x, int v){
  for(; x < (1 << 20); x += x&-x) ft[x] += v;
}

int query(int x){
  int ret = 0;
  for(; x > 0; x -= x&-x) ret += ft[x];
  return ret;
}

int query(int x, int y){
  return query(y) - query(x - 1);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, b, m, q = 0;
  cin >> n;
  memset(pos, -1, sizeof pos);
  for(int i = 1; i <= n; ++i){
    cin >> a;
    v[i] = a;
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    qu[i] = ppi(pii(b, a), i);
  }
  sort(qu, qu + m);

  for(int i = 1; i <= n; ++i){
    if(pos[v[i]] != -1)
      upd(pos[v[i]], -1);
    pos[v[i]] = i;
    upd(pos[v[i]], 1);
    //cout << i << "\n";
    for(;  qu[q].ff.ff == i; ++q)
      ans[qu[q].ss] = query(qu[q].ff.ss, qu[q].ff.ff);
  }
  for(int i = 0; i < m; ++i)
    cout << ans[i] << "\n";

  return 0;
}
