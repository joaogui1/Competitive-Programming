#include <cstdio>
#include <cstdlib>
int pai[100100];
int find(int x){
   if(x == pai[x])   return x;
   return pai[x] = find(pai[x]);
}
void join(int x, int y){
   x = find(x);y = find(y);
   pai[x] = y;
   return;
}
int main(){
   int n, k, aux, auy;
   char op;
   scanf("%d %d", &n, &k);
   for(int i = 1; i <= n; ++i)   pai[i] = i;
   for(int i = 0; i < k; ++i){
      scanf(" %c %d %d", &op, &aux, &auy);
      if(op == 'F')
         join(aux, auy);
      else
         printf("%s\n",(find(aux) == find(auy))?"S":"N");

   }
   return 0;
}
