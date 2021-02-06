#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  ll n, m, ans = 0;
  scanf("%lld %lld", &n, &m);
  ans = (n - 1LL)*(n - 2LL)/2LL;
  n -= m;
  if(n > 0) ans -= 3LL*(((n - 1LL)*(n - 2LL))/2LL);
  n -= m;
  if(n > 0) ans += 3LL*(((n - 1LL)*(n - 2LL))/2LL);
  n -= m;
  if(n > 0) printf("0\n");
  else  printf("%lld\n", ans);

  return 0;
}
