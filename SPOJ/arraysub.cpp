#include <bits/stdc++.h>

using namespace std;

int seg[4000040], n;

int query(int a, int b, int node, int l, int r){
  if(a > r || b < l)  return -1;
  if(a <= l && r <= b)  return seg[node];
  int m = (l + r)/2;
  return max(query(a, b, 2*node, l, m), query(a, b, 2*node + 1, m + 1, r));
}

void upd(int p, int v, int node, int l, int r){
  if(l > p || r < p)  return;
  if(l == r)  seg[node] = v;
  else{
    int m = (l + r)/2;
    upd(p, v, 2*node, l, m);
    upd(p, v, 2*node + 1, m + 1, r);
    seg[node] = max(seg[2*node], seg[2*node + 1]);
  }
}

int main(){
  int n, k, aux;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &aux);
    upd(i, aux, 1, 1, n);
  }
  scanf("%d", &k);
  for(int i = 1; i <= (n - k + 1); ++i)
    printf("%d%s", query(i, i + k - 1, 1, 1, n), (i == n - k + 1)?"\n":" ");

  return 0;
}
