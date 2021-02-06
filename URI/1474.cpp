#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

typedef long long int ll;

ll rec(ll n, ll k, ll l){
   ll m[56][2][2], vec[2] = {1, k}, temp[2] = {0LL};
   m[0][0][0] = 0LL, m[0][1][0] = 1LL, m[0][0][1] = l, m[0][1][1] = k;
   for(int i = 1; i < 56; ++i)
      for(int j = 0; j < 2; ++j)
         for(int k = 0; k < 2; ++k){
            m[i][j][k] = 0;
            for(int l = 0; l < 2; ++l) m[i][j][k] += (m[i - 1][j][l]*m[i - 1][l][k])%MOD;
            m[i][j][k] %= MOD;
         }

   for(long long int i = 0; i < 56; ++i)
      if((1LL << i)&n){
         for(int j = 0; j < 2; ++j){
            temp[j] = 0LL;
            for(int k = 0; k < 2; ++k) temp[j] += (vec[k]*m[i][k][j])%MOD;
         }
         for(int j = 0; j < 2; ++j) vec[j] = (temp[j])%MOD;
      }
   return vec[0];
}

int main(){
   //ios_base::sync_with_stdio(0);
   ll n, k, l;
   //scanf(" %lld %lld %lld", &n, &k, &l)!=EOF
   while(scanf(" %lld %lld %lld", &n, &k, &l)!=EOF){
      k %= MOD; l %= MOD;
      cout.precision(6);
      //cout << rec(n/5, k, l) << "\n";
      printf("%.6lld\n", rec(n/5, k, l) % MOD);
   }


   return 0;
}
