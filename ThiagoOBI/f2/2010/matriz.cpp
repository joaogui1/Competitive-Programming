#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll A[100100], B[100100];

ll prod(int n){
  ll ret = 0;
  for(int i = 1; i <= n; ++i) ret += A[i]*B[i];
  return ret;
}

int main(){
  ll n, p, q, r, s, x, y, a, b;
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &n, &p, &q, &r, &s, &x, &y, &a, &b);
  for(int i = 1; i <= n; ++i){
    A[i] = (q*i + p*a)%x;
    B[i] = (s*b + r*i)%y;
  }


  printf("%lld\n", prod(n));

  return 0;
}
