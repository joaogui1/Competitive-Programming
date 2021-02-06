#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int v[MAXN], s[2][MAXN], seg_max[4*MAXN], seg_min[4*MAXN];

void upd_max(int node, int l, int r, int pos, int v){
  if(l > pos || r < pos)  return;
  if(l == r){
    seg_max[node] = v;
    return;
  }
  int m = (l + r)/2;
  upd_max(2*node, l, m, pos, v);
  upd_max(2*node + 1, m + 1, r, pos, v);
  seg_max[node] = max(seg_max[2*node], seg_max[2*node + 1]);
}

void upd_min(int node, int l, int r, int pos, int v){
  if(l > pos || r < pos)  return;
  if(l == r){
    seg_min[node] = v;
    return;
  }
  int m = (l + r)/2;
  upd_min(2*node, l, m, pos, v);
  upd_min(2*node + 1, m + 1, r, pos, v);
  seg_min[node] = min(seg_min[2*node], seg_min[2*node + 1]);
}

int query_max(int node, int l, int r, int a, int b){
  if(l > b || r < a || r < l) return -(1 << 28);
  if(a <= l && r <= b)  return seg_max[node];
  int m = (l + r)/2;
  return max(query_max(2*node, l, m, a, b), query_max(2*node + 1, m + 1, r, a, b));
}

int query_min(int node, int l, int r, int a, int b){
  if(l > b || r < a || r < l) return -(1 << 28);
  if(a <= l && r <= b)  return seg_min[node];
  int m = (l + r)/2;
  return min(query_min(2*node, l, m, a, b), query_min(2*node + 1, m + 1, r, a, b));
}

int search_max(int node, int l, int r, int p, int v){
  int m = (l + r)/2;
  if(r <= p) return -1;
  if(l == r)  return (seg_max[node] < v?-1:l);
  if(l < p) return max(search_max(2*node, l, m, p, v), search_max(2*node + 1, m + 1, r, p, v));
  if(seg_max[node] < v) return -1;
  if(seg_max[2*node + 1] >= v) return search_max(2*node + 1, m + 1, r, p, v);
  return search_max(2*node, l, m, p, v);
}

int search_min(int node, int l, int r, int p, int v){
  int m = (l + r)/2;
  if(l >= p)  return (1 << 20);
  if(l == r)  return (seg_min[node] > v?(1 << 20):l);
  if(r > p) return min(search_min(2*node, l, m, p, v), search_min(2*node + 1, m + 1, r, p, v));
  if(seg_min[node] > v) return (1 << 20);
  if(seg_min[2*node] <= v)  return search_min(2*node, l, m, p, v);
  return search_min(2*node + 1, m + 1, r, p, v);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0, a, b;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> v[i];
  for(int i = 1; i <= n; ++i)
    s[0][i] = s[0][i - 1] + ((v[i] == 0)?1:-1);
  for(int i = 1; i <= n; ++i)
    s[1][i] = s[1][i - 1] + ((v[i] == 1)?1:-1);
  for(int i = 1; i <= n; ++i){
    upd_max(1, 1, n, i, s[1][i]);
    upd_min(1, 1, n, i, s[0][i]);
  }

  for(int i = 1; i <= n; ++i){
    b = search_max(1, 1, n, i, s[1][i] + 1);
    a = search_min(1, 1, n, i, s[0][i] - 1) + 1;
    if(s[0][i] > 0) a = 1;
    if(v[i] == 0) a = min(a, i);
    ans = max(ans, b - a + 1);
  }

  cout << ans << "\n";
  return 0;
}
