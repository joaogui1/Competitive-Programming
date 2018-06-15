#include <cstdio>
#include <algorithm>
int G[1010][1010];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int main(){
   int m, n, ans = 0;
   char aux;
   scanf("%d %d", &m, &n);
   for(int i = 1; i <= m; ++i)
      for(int j = 1; j <= n; ++j){
         scanf(" %c", &aux);
         if(aux == '#') G[j][i] = 1;
      }
   for(int i = 1; i <= m; ++i)
      for(int j = 1; j <= n; ++j)
         if(G[i][j] == 1)
            for(int k = 0; k < 4; ++k)
               if(G[i + dx[k]][j + dy[k]] == 0){
                  ++ans;
                  break;
               }
   printf("%d\n", ans);
   return 0;
}
