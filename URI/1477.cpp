#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100100
#define Left(x) 2*x
#define Right(x) 2*x + 1
int seg_tree[3][4*MAXN], lazy[4*MAXN], v0, v1, v2;

int get(int idx, int v){
   return seg_tree[(v + lazy[idx])% 3][idx];
}

void build_tree(int idx, int a, int b){
   if (a + 1 == b) seg_tree[0][idx] = 1;
   else {
     int l = 2*idx, r = l + 1,  mid = (a + b)/2;
     build_tree(l, a, mid);
     build_tree(r, mid, b);
     for (int i = 0; i < 3; ++i) seg_tree[i][idx] = get(l, i) + get(r, i);
   }
   return;
}

void query(int idx, int low, int high, int a, int b){
   if(high <= a || b <= low) return;

   if(a <= low && high <= b){
     v0 += get(idx, 0);
     v1 += get(idx, 1);
     v2 += get(idx, 2);
   }

   else{
     int l = idx * 2, r = l + 1, mid = (low + high)/2;
     lazy[l] += lazy[idx];
     lazy[r] += lazy[idx];
     lazy[idx] = 0;
     query(l, low, mid, a, b);
     query(r, mid, high, a, b);
     for(int i = 0; i < 3; ++i) seg_tree[i][idx] = get(l, i) + get(r, i);
   }
   return;
}

void update(int idx, int low, int high, int a, int b){
   if(high <= a || b <= low) return;

   if(a <= low && high <= b) lazy[idx] += 2;

   else{
     int l = idx * 2, r = l + 1, mid = (low + high)/2;
     lazy[l] += lazy[idx];
     lazy[r] += lazy[idx];
     lazy[idx] = 0;
     update(l, low, mid, a, b);
     update(r, mid, high, a, b);
     for(int i = 0; i < 3; ++i) seg_tree[i][idx] = get(l, i) + get(r, i);
   }
   return;
}

void initialize(int n){
   memset(seg_tree, 0 , sizeof(seg_tree));
   memset(lazy, 0, sizeof(lazy));
   build_tree(1, 0, n);
   return;
}

int main(){
   int m, n, aux, auy;
   char op;

   while(scanf("%d %d", &n, &m) == 2){
      initialize(n);

      for(int i = 0; i < m; ++i){
         scanf(" %c %d %d", &op, &aux, &auy);
         --aux;
         if(op == 'M')  update(1, 0, n, aux, auy);
         else{
            v0 = 0, v1 = 0, v2 = 0;
            query(1, 0, n, aux, auy);
            printf("%d %d %d\n", v0, v1, v2);
         }
      }
      printf("\n");
   }

   return 0;
}
