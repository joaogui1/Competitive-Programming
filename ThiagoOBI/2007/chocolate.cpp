#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, sum, a;
  scanf("%d", &n);
  sum = -n;
  for(;scanf("%d", &a) != EOF; sum += a);
  printf("%d\n", sum);

  return 0;
}
