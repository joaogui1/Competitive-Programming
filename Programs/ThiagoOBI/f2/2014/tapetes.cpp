#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main(){
  ll n, l, ans = 0;
  scanf("%lld %lld", &n, &l);
  ans = l - 1;
  ans += max((n - l + 1), 1LL)*max((n - l + 1), 1LL);
  printf("%lld\n", ans);
  return 0;
}
