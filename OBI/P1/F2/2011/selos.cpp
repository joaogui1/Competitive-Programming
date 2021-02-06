#include <cstdio>

int main(){
   long long int n;
   bool vdc = 0;
   scanf("%lld", &n);
   for(long long int i = 2; i*i <= n && !vdc; ++i)
      if(n%i == 0) vdc = 1;
   printf("%s\n", (vdc)?"S":"N");

   return 0;
}
