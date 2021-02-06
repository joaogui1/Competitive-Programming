#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100010
int ft1[60][MAXN], ft2[60][MAXN];

int Sum(int *ft, int x){
   int ret = 0;
   for(; x; x-=x&-x) ret += ft[x];
   return ret;
}

void update(int *ft, int x, int val){
   for(; x <= MAXN; x += x&-x) ft[x] += val;
   return;
}

int col[MAXN], lin[MAXN];
pair <int, int> lastcol[MAXN], lastline[MAXN];
int main(){
   int n, q, op, x, r;
   scanf("%d %d", &n, &q);
   for(int i = 1; i <= q; ++i){
      scanf("%d %d", &op, &x);
      int best = -1, best_val = -1, test = 0, tot = 0;
      if(op == 1){
         scanf("%d", &r);
         if(lastline[x].first != 0)
            update(ft1[lastline[x].second], lastline[x].first, -1);
         lastline[x] = make_pair(i, r);
         update(ft1[r], i, 1);
      }

      if(op == 2){
         scanf("%d", &r);
         if(lastcol[x].first != 0)
            update(ft2[lastcol[x].second], lastcol[x].first, -1);
         lastcol[x] = make_pair(i, r);
         update(ft2[r], i, 1);
      }

      if(op == 3){
         for(int j = 0; j <= 50; ++j)
            if(j != lastline[x].second){
               test = Sum(ft2[j], i) - Sum(ft2[j], lastline[x].first);
               tot += test;

               if(test >= best){
                  best = test;
                  best_val = j;
               }

            }
            if(n - tot > best || (n - tot == best && best_val < lastline[x].second))
               best_val = lastline[x].second;
            printf("%d\n", best_val);
      }

      if(op == 4){
         for(int j = 0; j <= 50; ++j)
            if(j != lastcol[x].second){
               test = Sum(ft1[j], i) - Sum(ft1[j], lastcol[x].first);
               tot += test;

               if(test >= best){
                  best = test;
                  best_val = j;
               }
            }
            if(n - tot > best || (n - tot == best && best_val < lastcol[x].second))
               best_val = lastcol[x].second;
            printf("%d\n", best_val);
      }

   }

   return 0;
}
