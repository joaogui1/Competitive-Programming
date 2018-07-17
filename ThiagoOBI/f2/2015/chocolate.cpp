#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x1, x2, y1, y2;
  scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
  if((min(x1, x2) <= n/2 && max(x1, x2) > n/2) || (min(y1, y2) <= n/2 && max(y1, y2) > n/2))
    printf("S\n");
  else
    printf("N\n");

  return 0;
}
