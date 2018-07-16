#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//----------------------------
#define MAXN 100100
#define Left(x) x << 1
#define Right(x)  (x << 1) + 1
long long int tree[4*MAXN];
long long int lazy[4*MAXN];
//----------------------------
long long int query(long long int node, long long int beg, long long int end, long long int i, long long int j){
    if(beg > j || end < i) return 0;

    if(lazy[node] > 0){
        if(beg != end){
            lazy[Left(node)] += lazy[node];
            lazy[Right(node)] += lazy[node];
	    }

        tree[node] += lazy[node]*(end - beg + 1);
        lazy[node] = 0;
    }

    if(beg >= i && end <= j)return tree[node];

    long long mid = (end + beg)/2;;
    return query(Left(node), beg, mid, i, j) + query(Right(node), mid + 1 , end, i, j);
}

void update(long long int node,long long int beg,long long int end,long long int i,long long int j,long long int v){
    if(beg > j || end < i) return;
    if(beg >= i && end <= j){
	    if(beg != end){
            lazy[Left(node)] += v;
            lazy[Right(node)] += v;
	    }
		tree[node] += (end - beg + 1)*v;
		return;
	}

	 long long int mid = (beg + end) >> 1;
    update(Left(node), beg, mid, i, j, v);
    update(Right(node), mid + 1, end, i, j, v);
	 tree[node] += v*(min(end, j) - max(beg, i) + 1);
}

int main(){
   long long int t, n, m, op, p , q, v;
   scanf("%lld", &t);
   while(t--){
      scanf("%lld %lld", &n, &m);
      memset(tree, 0, sizeof(tree));
      memset(lazy, 0, sizeof(lazy));
      for(long long int i = 0; i < m; ++i){
         scanf("%lld", &op);
         if(!op){
            scanf("%lld %lld %lld", &p, &q, &v);
            update(1, 1, MAXN, p, q, v);
         }
         else{
            scanf("%lld %lld", &p, &q);
            printf("%lld\n", query(1, 1, MAXN, p, q));
         }
      }
   }


   return 0;
}
