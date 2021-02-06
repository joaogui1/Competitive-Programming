#include <cstdio>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
long long int inv[3010][2];

long long int sum(long long int a, long long int b){
   if(a > b)   swap(a, b);

   return b*(b+1LL)/2LL - (a - 1LL)*a/2LL;
}

long long int ans(long long int a, long long int b, long long int cont){
   //if(a > b)   swap(a, b);
   //cout <<"cont: " <<  cont << endl;
   if(b < a)   return 0;
   if(cont == 0)  return sum(a, b);

   long long int x = inv[cont][0], y = inv[cont][1];

   if((y < a || x > b) || (x >= a && y <= b))   return ans(a, b, cont - 1);

   if(y <= b)   return ans(y + 1, b, cont - 1) + ans(x, x + y - a, cont - 1);

   if(a <= x)   return ans(a, x - 1, cont - 1) + ans(x + y - b, y, cont - 1);

   return ans(x + y - b, x + y - a, cont - 1);

}

int main(){
   int n, m, cont = 0;
   long long int aux, auy;
   char op;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < m; ++i){
      scanf(" %c %lld %lld", &op, &aux, &auy);
      if(op == 'I'){
         inv[++cont][0] = aux;
         inv[cont][1] = auy;
      }
      else{
         printf("%lld\n", ans(aux, auy, cont));
      }
   }
   return 0;
}
