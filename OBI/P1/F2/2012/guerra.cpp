#include <cstdio>
#include <algorithm>
int v[100100];
int main(){
   int n, ans, tot_sum = 0, sum = 0;
   scanf("%d", &n);
   for (int i = 1;  i <= n; ++i){
      scanf("%d", &v[i]);
      tot_sum += v[i];
   }
   for (int i = 1;  i <= n; ++i){
      sum += v[i];
      if(2*sum == tot_sum){
         ans = i;
         break;
      }
   }
   printf("%d\n", ans);
   return 0;
}
