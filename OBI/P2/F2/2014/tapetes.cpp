#include <cstdio>
int main(){
   long long int n, l;
   long long int ans = 0;
   scanf("%lld %lld", &l, &n);
   ans = (l - n + 1)*(l - n + 1) + (n - 1);
   printf("%lld\n", ans);
   return 0;
}
