#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;
int G[110][110];
int main(){
   int n, m, ans, aux, auy, idx, idy, idz, best = 0;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < m; ++i){
      scanf("%d %d", &aux, &auy);
      scanf("%d", &G[aux][auy]);
      G[auy][aux] = G[aux][auy];
   }
   for(int i = 1; i <= n; ++i)
      for(int j = i + 1; j <= n; ++j)
         for(int k = j + 1; k <= n; ++k)
            if(G[i][j] + G[i][k] + G[j][k] >= best){
               best = G[i][j] + G[i][k] + G[j][k];
               idx = i;idy = j;idz = k;
            }

   printf("%d %d %d\n",idx, idy, idz);
}
