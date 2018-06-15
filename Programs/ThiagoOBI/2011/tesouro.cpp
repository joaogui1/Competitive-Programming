#include <bits/stdc++.h>

using namespace std;

int g[128][128];

int main(){
  int n, k, x, y, d;
  scanf("%d %d", &n, &k);
  for(int c = 0; c < k; ++c){
    scanf("%d %d %d", &x, &y, &d);
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        g[i][j] += (abs(i - x) + abs(j - y) == d);
  }
  x = -1, y = -1;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
      if(g[i][j] == k && x == -1) x = i, y = j;
      else if(g[i][j] == k){
        printf("-1 -1\n");
        return 0;
      }
    }
  printf("%d %d\n", x, y);

  return 0;
}
