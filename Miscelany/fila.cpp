#include <bits/stdc++.h>
#define MAXN 1200100

using namespace std;

int n, q;
int seg[4*MAXN], h[MAXN], ft[MAXN], op[MAXN], pos[MAXN], x[MAXN];

void upd_ft(int x, int val){
  for(; x <= n + q; x += x&-x)  ft[x] += val;
  return;
}

int ft_sum(int x){
  int ret = 0;
  for(; x > 0; x -= x&-x) ret += ft[x];
  return ret;
}

int s_ft(int val){
  int acc = 0, test;
  for(int i = 30; i > -1; --i){
    test = acc + (1 << i);
    if(test > n + q)  continue;

    if(ft[test] <= val){
      val -= ft[test];
      acc = test;
    }

  }
  if(val == 0)  return acc;
  return -1;
}

void upd_seg(int node, int l, int r, int p, int val){
  if(p < l || p > r)  return;
  if(l == r){
    seg[node] = val;
    return;
  }
  int m = (l + r)/2;
  upd_seg(2*node, l, m, p, val);
  upd_seg(2*node + 1, m + 1, r, p, val);
  seg[node] = max(seg[2*node], seg[2*node + 1]);
  return;
}

int s_seg(int node, int l, int r, int p, int val){
  if(seg[node] <= val)  return 0;
  if(l > p) return 0;
  if(l == r)  return l;

  int m = (l + r) >> 1;
  if(r > p) return max(s_seg(2*node, l, m, p, val), s_seg(2*node + 1, m + 1, r, p, val));
  if(seg[2*node + 1] > val) return s_seg(2*node + 1, m + 1, r, p, val);
  return s_seg(2*node, l, m, p, val);
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    pos[i] = i;
    scanf("%d", &x[i]);
  }

  scanf("%d", &q);
  for(int i = n; i < n + q; ++i)  scanf("%d %d %d", &op[i], &pos[i], &x[i]);
  for(int i = 1; i <= n + q; ++i) upd_ft(i, 1);

  for(int i = n + q - 1; i > -1; --i){
    if(op[i] == 0){
      pos[i] = s_ft(pos[i]) + 1;
      upd_ft(pos[i], -1);
    }
    else  pos[i] = s_ft(pos[i] - 1) + 1;
  }

  for(int i = 0; i < n + q; ++i){
    if(op[i] == 0){
      h[pos[i]] = x[i];

      upd_seg(1, 1, n + q, pos[i], h[pos[i]]);

      upd_ft(pos[i], 1);
    }
    else  printf("%d\n", ft_sum(s_seg(1, 1, n + q, pos[i], h[pos[i]] + x[i])));

  }


  return 0;
}
