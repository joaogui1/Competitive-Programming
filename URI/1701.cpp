#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long int find_fib(long long int n){
   long long int fib[34][2][2], vec[2] = {0LL, 1LL}, temp[2];
   fib[0][0][0] = 0, fib[0][1][0] = fib[0][0][1] = fib[0][1][1] = 1;
   for(int i = 1; i < 34; ++i)
      for(int j = 0; j < 2; ++j)
         for(int k = 0; k < 2; ++k)
            fib[i][j][k] = ((fib[i - 1][j][0]*fib[i - 1][0][k])%MOD + (fib[i - 1][j][1]*fib[i - 1][1][k])%MOD)%MOD;

   for(long long int i = 0LL; i < 34LL; ++i)
      if((1LL << i)&n){
         //cout << i << " " << n << endl;
         for(int j = 0; j < 2; ++j) temp[j] = (vec[0]*fib[i][0][j] + vec[1]*fib[i][1][j])%MOD;
         for(int j = 0; j < 2; ++j) vec[j] = temp[j];
      }
   return vec[0];
}

long long int sum(long long int a, long long int b, long long int n){
   long long int fa = find_fib(a), fb = find_fib(b), ca = find_fib(a - 1), cb = find_fib(b - 1);
   long long int fib[34][5][5], vec[5] = {(fa*fb)%MOD, (fa*cb)%MOD, (ca*fb)%MOD, (ca*cb)%MOD, 0}, temp[5];
   memset(fib, 0, sizeof(fib));
   fib[0][0][0] = fib[0][1][0] = fib[0][2][0] = fib[0][3][0] = fib[0][0][1] = fib[0][2][1] = fib[0][0][2] = fib[0][1][2] = fib[0][0][3] = fib[0][0][4] = fib[0][4][4] = 1LL;
   for(int i = 1; i < 34; ++i)
      for(int j = 0; j < 5; ++j)
         for(int k = 0; k < 5; ++k){
            fib[i][j][k] = 0LL;
            for(int l = 0; l < 5; ++l)
               fib[i][j][k] += (fib[i - 1][j][l]*fib[i - 1][l][k])%MOD;
            fib[i][j][k] %= MOD;
         }

   for(long long int i = 0; i < 31; ++i){
      if(n&(1LL << i)){
         //cout << i << endl;
         for(int j = 0; j < 5; ++j){
            temp[j] = 0LL;
            for(int k = 0; k < 5; ++k) temp[j] += (vec[k]*fib[i][k][j])%MOD;
         }
         for(int j = 0; j < 5; ++j) vec[j] = (temp[j])%MOD;
      }
   }
   return (vec[4])%MOD ;
}

int main(){
   ios_base::sync_with_stdio(0);
   long long int a, b, n, ans;
   while(cin >> a >> b >> n){
      if(a + b + n <= 0)   return 0;
      cout << sum(a, b, n) << "\n";
   }

   return 0;
}
