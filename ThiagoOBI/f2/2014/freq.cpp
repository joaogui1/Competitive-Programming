#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

int ft[2][64][100100];

void upd(int *ft_, int x, int val){
  for(; x < 100100; x += x&-x)  ft_[x] += val;
}

int sum(int *ft_, int x){
  int ret = 0;
  for(; x > 0; x -= x&-x) ret += ft_[x];
  return ret;
}
pii lastcol[100100], lastlin[100100];
int main(){
  int n, q, op, x, r, best, best_idx, test, tot;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= q; ++i){
    tot = 0, best = -1, best_idx = -1;
    scanf("%d %d", &op, &x);
    if(op == 1){
      scanf("%d", &r);
      if(lastlin[x].ff != 0)
        upd(ft[0][lastlin[x].ss], lastlin[x].ff, -1);
      lastlin[x] = pii(i, r);
      upd(ft[0][r], i, 1);
    }

    else if(op == 2){
      scanf("%d", &r);
      if(lastcol[x].ff != 0)
        upd(ft[1][lastcol[x].ss], lastcol[x].ff, -1);
      lastcol[x] = pii(i, r);
      upd(ft[1][r], i, 1);
    }

    else if(op == 3){
      for(int j = 0; j < 51; ++j){
        if(j != lastlin[x].ss){
          test = sum(ft[1][j], i) - sum(ft[1][j], lastlin[x].ff);
          tot += test;

          if(test >= best){
            best = test;
            best_idx = j;
          }
        }
      }
      if(n - tot > best || (n - tot == best && best_idx < lastlin[x].ss))
        best_idx = lastlin[x].ss;
      printf("%d\n", best_idx);

    }

    else{
      for(int j = 0; j < 51; ++j){
        if(j != lastcol[x].ss){
          test = sum(ft[0][j], i) - sum(ft[0][j], lastcol[x].ff);
          tot += test;

          if(test >= best){
            best = test;
            best_idx = j;
          }
        }
      }
      if(n - tot > best || (n - tot == best && best_idx < lastcol[x].ss))
        best_idx = lastcol[x].ss;
      printf("%d\n", best_idx);

    }
  }
  return 0;
}
