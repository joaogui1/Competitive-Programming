#include <cstdio>
int pai[50010], mark[50010];

int find(int x){
   return (x == pai[x])?x:pai[x] = find(pai[x]);
}

void join(int x, int y){
   pai[find(x)] = find(y);
   return;
}

int main(){
   int n, m, a, b, ans = 0;
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; ++i)   pai[i] = i;
   for(int i = 0; i < m; ++i){
      scanf("%d %d", &a, &b);
      join(a, b);
   }
   for(int i = 1; i <= n; ++i)
      if(++mark[find(i)] == 1)
         ++ans;
   printf("%d\n", ans);
   return 0;
}
