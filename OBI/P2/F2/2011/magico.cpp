#include <cstdio>
int quad[1010][1010], freq[1000100];
int main(){
   int n;
   bool vdc = 1;
   long long int sum = 0, ans = 0, test_sum;
   scanf("%d", &n);
   for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j){
         scanf("%d", &quad[i][j]);
         if(quad[i][j] > n*n) vdc = 0;
         if(++freq[quad[i][j]] > 1) vdc = 0;
      }
   if(vdc){
      for(int j = 1; j <= n; ++j){
         sum += quad[1][j];
      }
      for(int i = 1; i <= n && vdc; ++i){
         test_sum = 0;
         for(int j = 1; j <= n && vdc; ++j)
            test_sum += quad[i][j];
         if(sum != test_sum)  vdc = 0;
      }
      for(int i = 1; i <= n && vdc; ++i){
         test_sum = 0;
         for(int j = 1; j <= n; ++j)
            test_sum += quad[j][i];
         if(sum != test_sum)  vdc = 0;
      }
   }
   printf("%lld\n",(vdc)?sum:0LL);
   return 0;
}
