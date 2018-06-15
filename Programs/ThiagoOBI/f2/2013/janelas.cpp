#include <bits/stdc++.h>

using namespace std;

int main(){
  int f[3], ans = 0;
  scanf("%d %d %d", &f[0], &f[1], &f[2]);
  sort(f, f + 3);
  ans = f[0] - 0 + max(0, f[1] - f[0] - 200) + max(0, f[2] - f[1] - 200) + max(0, 600 - f[2] - 200);
  printf("%d\n", 100*ans);





  return 0;
}
