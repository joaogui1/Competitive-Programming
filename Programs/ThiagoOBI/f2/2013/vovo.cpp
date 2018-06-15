#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

ll m[63][2][2], v[2] = {54LL, 12LL}, I[2][2], temp[2][2];

void pre(){
  m[0][0][0] = 5, m[0][0][1] = 1, m[0][1][0] = -2, m[0][1][1] = 0;
  for(int i = 1; i < 61; ++i){
    for(int j = 0; j < 2; ++j)
      for(int k = 0; k < 2; ++k){
        for(int l = 0; l < 2; ++l)
          m[i][j][k] += (m[i - 1][j][l]*m[i - 1][l][k])%MOD;
        m[i][j][k] = ((m[i][j][k]%MOD) + MOD)%MOD;
      }
  }
}

ll f(ll n){
  if(n == 2)  return v[0];
  else if(n == 1)  return v[1];
  n -= 2;
  ll ret = 0;
  I[0][0] = I[1][1] = 1;
  for(ll p = 0; p < 62; ++p){
    if((1LL << p)&n){
      for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j){
          temp[i][j] = 0LL;
          for(int k = 0; k < 2; ++k)
            temp[i][j] += (I[i][k]*m[p][k][j])%MOD;
        }
      for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
          I[i][j] = ((temp[i][j]%MOD) + MOD)%MOD;
    }
  }
  ret = (I[0][0]*v[0])%MOD + (I[1][0]*v[1])%MOD;
  return ((ret%MOD) + MOD)%MOD;
}

int main(){
  ll n;
  pre();
  scanf("%lld", &n);

  printf("%lld\n", f(n));
  return 0;
}
