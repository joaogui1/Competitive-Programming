#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int n, a, p;
  scanf("%lld", &n);
  n *= 2LL;
  p = 100000LL;

  while(--p)
    if(n%p == 0 && n >= p*p - p){
      a = ((n/p) - p + 1);
      if(a%2 == 0 && a > 0)  break;
    }
  printf("%lld %lld\n", a/2, p);

  return 0;
}
