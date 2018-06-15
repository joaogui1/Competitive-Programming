#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, p, a, b, ans = 0;
  scanf("%d %d", &n, &p);
  for(;scanf("%d %d", &a, &b) != EOF; ans += (a + b >= p));

  printf("%d\n", ans);

  return 0;
}
