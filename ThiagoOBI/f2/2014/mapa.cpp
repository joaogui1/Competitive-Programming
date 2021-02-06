#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int p[100100];
ll sz[100100];
int find(int x){
  return (x == p[x])?x:(p[x] = find(p[x]));
}

void join(int x, int y){
  p[find(x)] = find(y);
}

int main(){
  ll ans, n;
  int a, b, c;
  scanf("%lld", &n);
  ans = n*(n - 1)/2LL;
  for(int i = 1; i <= n; ++i) p[i] = i;
  for(int i = 1; i < n; ++i){
    scanf("%d %d %d", &a, &b, &c);
    if(!c)  join(a, b);
  }
  for(int i = 1; i <= n; ++i)
    ++sz[find(i)];
  for(int i = 1; i <= n; ++i)
    ans -= sz[i]*(sz[i] - 1)/2LL;

  printf("%lld\n", ans);
  return 0;
}
