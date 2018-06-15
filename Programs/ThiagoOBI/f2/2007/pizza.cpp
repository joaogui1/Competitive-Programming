#include <bits/stdc++.h>

using namespace std;

int v[100100];

int main(){
  int n, best = 0, test = 0, sum = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &v[i]), sum += v[i];
  for(int i = 1; i <= n; ++i){
    test += v[i];
    if(test > 0)  test = 0;
    best = min(best, test);
  }
  test = 0;
  best = sum - best;
  for(int i = 1; i <= n; ++i){
    test += v[i];
    best = max(best, test);
    if(test < 0)  test = 0;
  }
  printf("%d\n", best);
  return 0;
}
