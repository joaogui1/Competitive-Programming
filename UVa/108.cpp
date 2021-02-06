#include <bits/stdc++.h>

using namespace std;

int G[1 << 7][1 << 7];

int main(){
  int n, test, best = -(1 << 29);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
      scanf("%d", &G[i][j]);
      if(i > 0) G[i][j] += G[i - 1][j];
      if(j > 0) G[i][j] += G[i][j - 1];
      if(i > 0 && j > 0)  G[i][j] -= G[i - 1][j - 1];
    }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      for(int k = i; k < n; ++k)
        for(int l = j; l < n; ++l){
          test = G[k][l];
          if(i > 0) test -= G[i - 1][l];
          if(j > 0) test -= G[k][j - 1];
          if(i > 0 && j > 0)  test += G[i - 1][j - 1];
          if(test > best) best = test;
        }

  printf("%d\n", best);


  return 0;
}
