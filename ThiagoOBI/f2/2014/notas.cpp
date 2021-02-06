#include <bits/stdc++.h>

using namespace std;

int fr[128];

int main(){
  int n, a, best = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", &a), ++fr[a];
  for(int i = 1; i < 101; ++i)
    if(fr[i] >= fr[best]) best = i;
  printf("%d\n", best);





  return 0;
}
