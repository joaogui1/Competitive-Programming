#include <cstdio>
#define MOD 1000000007LL

long long bino(int n,int k) {
    long long ret = 1;
    for(int i = 0;i < k; ++i) {
        ret *= (n - i);
        ret %= MOD;
    }
    return ret;
}
int main(){
   long long int n, k, a = 0, b = 0, c = 1, d = 1, ans = 1, j, aux, exc = 1;
   scanf("%lld %lld", &n, &k);
   c <<= n;
   d <<= (k - 1);
   --d;
   scanf("%lld", &j);
   for(int i = 1; i < (1 << n); ++i){
      scanf("%lld", &aux);
      if(aux > j) ++b;
      else  ++a;
   }
   //printf("%lld %lld %lld %lld\n", a, b, c, d);
   //if(d > a || (b == 0 && n != k - 1))   printf("0\n"); //pouca gente perde pra ele ou ninguem perde pra ele
   //else{
      ans = ((d + 1)*bino(a, d))%MOD;
      ans = (ans*(1 << (n - k + 1 )))%MOD;
      ans = (ans*bino(c - d - 1, c - d - 1))%MOD;
      d <<= 1;++d;
      exc = ((d + 1)*bino(a, d))%MOD;
      exc = (exc*(1 << (n - k )))%MOD;
      exc = (exc*bino(c - d - 1, c - d - 1))%MOD;
      ans = ((ans - exc)%MOD + MOD)%MOD;
      printf("%lld\n", ans);
   //}
   return 0;
}
