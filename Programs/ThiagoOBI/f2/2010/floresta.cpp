#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  ll n, ans = 0, b;
  scanf("%lld", &n);
  for(int i = 2; (i - 2)*(i - 2) <= n; ++i){
    b = ((n - 1LL + i)/(2LL*i - 1LL));
    if(b < i) break;
    ans += (n - 1LL + i == b*(2LL*i - 1LL));
  }

  printf("%lld\n", ans);

  return 0;
}
