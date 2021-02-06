#include <cstdio>
int bit[2000100], n, m;
void update(int x, int val){
   while(x <= n){
      bit[x] += val;
      x += (x & -x);
   }
   return;
}
int sum(int x){
   int soma = 0;
   while(x > 0){
      soma += bit[x];
      x -= (x & -x);
   }
   return soma;
}
int main(){
   int x, y, aux, auy;
   char op;
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; ++i)
      update(i, i);
   for(int i = 0; i < m; ++i){
      scanf(" %c %d %d", &op, &x, &y);
      if(op == 'S')
         printf("%d\n", sum(y) - sum(x - 1));
      else{
         for(int i = 0; x + i < y - i; ++i){
            aux = sum(x + i) - sum(x + i - 1); auy = sum(y - i) - sum(y - i - 1);
            update(x + i, auy - aux);
            update(y - i, aux - auy);
         }
      }
   }

   return 0;
}
