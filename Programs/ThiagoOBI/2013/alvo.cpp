#include <bits/stdc++.h>

using namespace std;

vector<long long int> r;

int main(){
  int c, n, ini, fim, m;
  long long int x, y, ans = 0;
  scanf("%d %d", &c, &n);
  for(int i = 0; i < c; ++i){
    scanf("%lld", &x);
    r.push_back(-x*x);
  }
  sort(r.begin(), r.end());
  for(int i = 0; i < n; ++i){
    scanf("%lld %lld", &x, &y);
    ans += (upper_bound(r.begin(), r.end(), -(x*x + y*y)) - r.begin());
  }

  printf("%lld\n", ans);

  return 0;
}
