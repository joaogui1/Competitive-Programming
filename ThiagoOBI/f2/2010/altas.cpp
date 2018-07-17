#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll n, k;

ll f(ll x){
   long long int ret = 0, aux = 1;
   for(int i = 1; i <= k; ++i){
      aux *= (x - i + 1);
      aux /= i;
      ret += aux;

      if(ret >= n)   break;
   }
   return ret;
}

int main(){
  scanf("%lld %lld", &n, &k);
  if(k >= ceil(log2(n)))  printf("%d\n", int(ceil(log2(n))));
  else{
    ll beg = 0, end = n, m;
    while(end - beg > 1){
      m = (end + beg)/2;
      if(f(m) < n)  beg = m;
      else end = m;
    }
    printf("%lld\n", end);
  }




  return 0;
}
