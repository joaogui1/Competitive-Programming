#include <cstdio>
#define MOD 1000000007
long long int m[65][4], ans[4] = {246LL, 54LL, 54LL, 12LL};
int main(){
   long long int n, p = 1LL, a0, a1, a2, a3;
   scanf("%lld", &n);
   if(n >= 3){
      n -= 3;
      m[0][0] = +5LL;
      m[0][1] = +1LL;
      m[0][2] = -2LL;
      m[0][3] = +0LL;
      for(int i = 1; i <= 60; ++i){
         m[i][0] = ((m[i-1][0]*m[i-1][0])%MOD + (m[i-1][1]*m[i-1][2])%MOD)%MOD;
         m[i][1] = ((m[i-1][0]*m[i-1][1])%MOD + (m[i-1][1]*m[i-1][3])%MOD)%MOD;
         m[i][2] = ((m[i-1][0]*m[i-1][2])%MOD + (m[i-1][2]*m[i-1][3])%MOD)%MOD;
         m[i][3] = ((m[i-1][2]*m[i-1][1])%MOD + (m[i-1][3]*m[i-1][3])%MOD)%MOD;
      }
      for(long long int i = 0LL; (p << i) <= n; ++i){
         if((p << i) & n){
            a0 = ((ans[0]*m[i][0])%MOD + (ans[1]*m[i][2])%MOD)%MOD;
            a1 = ((ans[0]*m[i][1])%MOD + (ans[1]*m[i][3])%MOD)%MOD;
            a2 = ((ans[2]*m[i][0])%MOD + (ans[3]*m[i][2])%MOD)%MOD;
            a3 = ((ans[2]*m[i][1])%MOD + (ans[3]*m[i][3])%MOD)%MOD;
            ans[0] = a0;
            ans[1] = a1;
            ans[2] = a2;
            ans[3] = a3;
         }
      }
      ans[0] = (ans[0]%MOD + MOD)%MOD;
      printf("%lld\n", ans[0]);
   }
   else  printf("%lld\n", (n == 1)?12LL:54LL);

   return 0;
}
