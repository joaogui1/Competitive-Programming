#include <cstdio>
#include <cstdlib>
int nums[10];
int main(){
   int n, sum = 0, aux;
   long long int ans = 0;
   scanf("%d", &n);
   nums[0] = 1;
   while(n--){
      scanf("%d", &aux);
      sum += aux;
      sum %= 8;
      ans += nums[sum];
      ++nums[sum];
   }
   printf("%lld\n", ans);
   return 0;
}
