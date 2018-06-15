#include <bits/stdc++.h>

int G[1010][1010];

int main(){
  int n, p, c, cont, ans;

  while(1){
    scanf("%d %d %d", &p, &n, &c);
    if(p == 0 && n == 0 && c == 0)  break;
    ans = 0;
    memset(G, 0, sizeof G);

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < p; ++j)
        scanf("%d", &G[i][j]);

    for(int i = 0; i < p; ++i){
      cont = G[0][i];
      for(int j = 1; j < n; ++j){
        if(G[j][i] == G[j - 1][i] && G[j][i] == 1)  ++cont;
        else{
          //std::cout << "help " << cont << std::endl;
          if(cont >= c) ++ans;
          cont = G[j][i];
        }
      }
      if(cont >= c) ++ans;
    }

    printf("%d\n", ans);
  }





  return 0;
}
