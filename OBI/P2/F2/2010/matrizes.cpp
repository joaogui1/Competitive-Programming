#include <cstdio>

int main(){
   long long int n, p, q, r, s, x, y, i, j, aux, auy;
   scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &p, &q, &r, &s, &x, &y);
   scanf("%lld %lld", &i, &j);
   long long int ans = 0;

   for(long long int k = 1; k <= n; ++k){
      aux = ((p*i)%x + (q*k)%x)%x;
      auy = ((r*k)%y + (s*j)%y)%y;
      ans += aux*auy;
   }
   printf("%lld\n", ans);
}
