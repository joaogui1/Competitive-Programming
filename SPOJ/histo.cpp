#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int n;
ll seg[400040], a[100010];

ll query(int pos, int l, int r, int a, int b){
  if(l > b || r < a)  return (1LL << 50);
  if(a <= l && r <= b)  return seg[pos];
  int m = (l + r)/2;
  return min(query(2*pos, l, m, a, b), query(2*pos + 1, m + 1, r, a, b));
}

void upd(int pos, int l, int r, int no, int v){
  if(l > no || r < no)  return;
  if(l == r)  seg[pos] = v;
  else{
    int m = (l + r)/2;
    upd(2*pos, l, m, no, v);
    upd(2*pos + 1, m + 1, r, no, v);
    seg[pos] = min(seg[2*pos], seg[2*pos + 1]);
  }
}

ll right(int node, int l, int r, int v, int p){
  int m = (l + r)/2;
  if(r <= p) return (1 << 20);
  if(r == l)  return ((seg[node] < v)?l:(1 << 20));
  if(l < p) return min(right(2*node, l, m, v, p), right(2*node + 1, m + 1, r, v, p));
  if(seg[node] >= v) return (1 << 20);
  if(seg[2*node] < v) return right(2*node, l, m, v, p);
  return right(2*node + 1, m + 1, r, v ,p);
}

ll left(int node, int l, int r, int v, int p){
  int m = (l + r)/2;
  if(l >= p)  return -1;
  if(l == r)  return ((seg[node] < v)?l:-1);
  if(r > p) return max(left(2*node, l, m, v, p), left(2*node + 1, m + 1, r, v, p));
  if(seg[node] >= v)  return -1;
  if(seg[2*node + 1] < v) return left(2*node + 1, m + 1, r, v, p);
  return left(2*node, l, m, v, p);
}

void initialize(){
  for(int i = 0; i < 400040; ++i) seg[i] = (1LL << 50);
}

int main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  int n;
  ll ans, l, r;
  while(1){
    l = r = 0;
    ans = 0;
    scanf("%d", &n);
    initialize();
    if(n == 0)  return 0;
    for(int i = 1; i <= n; ++i){
      scanf("%lld", &a[i]);
      upd(1, 1, n, i, a[i]);
    }
    for(int i = 1; i <= n; ++i){
      l = max(0LL, left(1, 1, n, a[i], i));
      r = min(n + 1LL, right(1, 1, n, a[i], i));
      ans = max(ans, (r - l - 1)*a[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
