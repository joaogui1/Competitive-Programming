#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, a, add = 0, ans = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a);
    a += add;
    ans += abs(a - m);
    add = m - a;
  }
  printf("%d\n", ans);
  return 0;
}
