#include <bits/stdc++.h>

using namespace std;

int x[100010];

int main(){
  int n, k, ans = (1 << 20);
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i)  scanf("%d", &x[i]);
  sort(x, x + n);
  for(int i = 0; i < k + 1; ++i)  ans = min(ans, x[i + n - k - 1] - x[i]);
  printf("%d\n", ans);



  return 0;
}
