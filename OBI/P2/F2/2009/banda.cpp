#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int G[110][110];
int main(){
   int n, m, aux1, aux2, ans[3], best = 0;
   scanf("%d %d", &n, &m);
   for (int i  = 0; i < m; ++i) {
      scanf("%d %d", &aux1, &aux2);
      scanf("%d", &G[aux1][aux2]);
      G[aux2][aux1] = G[aux1][aux2];
   }
   for(int i = 1; i <= n; ++i)
      for(int j = i + 1; j <= n; ++j)
         for(int k = j + 1; k <= n; ++k)
            if(G[i][j] + G[j][k] + G[i][k] >= best){
               best = G[i][j] + G[j][k] + G[i][k];
               ans[0] = i, ans[1] = j, ans[2] = k;
            }
   printf("%d %d %d\n", ans[0], ans[1], ans[2]);

   return 0;
}
