#include <bits/stdc++.h>

using namespace std;

char G[128][128];

int main(){
  char c;
  int cont = 0, n, mx = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j)
      scanf(" %c", &G[i][j]);
    if(i & 1)
      for(int j = 0; j < n/2; ++j)
        swap(G[i][j], G[i][n - 1 - j]);
  }
  //for(int i = 0; i < n; ++i)
    //for(int j = 0; j < n; ++j)
      //cout << G[i][j] << " \n"[j == n - 1];
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
      if(G[i][j] == 'o')  ++cont;
      if(G[i][j] == 'A')  cont = 0;
      mx = max(mx, cont);
    }

  printf("%d\n", mx);

  return 0;
}
