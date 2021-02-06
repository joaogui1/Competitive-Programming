#include <cstdio>

int main(){
   int  x, y, n;
   long long int cont = 0;
   scanf("%d", &n);
   for(int i = 2; i*i <= n; ++i){ //O(sqrt(n))?
      if(n %(2*i - 1) == i){
         y = i;
         x = (n + i - 1)/(2*i - 1);
         if(y <= x)  ++cont;
         else  break;
      }
   }
   printf("%lld\n", cont);
   return 0;
}
