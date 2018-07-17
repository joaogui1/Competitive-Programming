#include <bits/stdc++.h>

using namespace std;

int G[1024][1024];

int main(){
  int n, s, sum = 0;
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      G[i][j] = i*n + j + 1;
  for(int i = 0; i < n; ++i)  sum += G[i][i];
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      printf("%d%s", G[i][j] + (i == 0)*(s - sum), (j == n - 1)?"\n":" ");


  return 0;
}
