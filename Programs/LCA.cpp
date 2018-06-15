//SPOJ international LCA
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int pai[1010], ancestral[1010][31], level[1010], ans[1010], sz, v;


void initialize(){
   for(int i = 1; i <= 1010; ++i)   pai[i] = -1;
   for(int i = 1; i <= 1010; ++i)   level[i] = 0;
   for(int i = 1; i <= 1010; ++i)   ans[1010] = 0;
   for(int j = 0; j <= 22; ++j)
   for(int i = 0; i <= 1010; ++i)   ancestral[i][j] = -1;
}



int LCA(int u, int v){
   if(level[u] < level[v]) swap(u, v);
   for(int i = 22; i >= 0; --i){
      //printf("%d\n", u);
      if(level[u] - (1 << i) >= level[v])
         u = ancestral[u][i];
      }

   if(u == v)  return u;

   for(int i = 22; i >= 0; --i)
      if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
         u = ancestral[u][i];
         v = ancestral[v][i];
      }
   return pai[u];
}

int main(){
   int n, t, m, aux, auy, root, q;
   scanf("%d", &t);
   for(int c = 1; c <= t; ++c){
      scanf("%d", &n);
      initialize();
      for(int i = 1; i <= n; ++i){
         scanf("%d", &m);
         for(int j = 1; j <= m; ++j){
            scanf("%d", &aux);
            pai[aux] = i;
            level[aux] = level[i] + 1;
         }
      }
      pai[1] = 1;
      /*for(int i = 1; i <= n; ++i)
         if(pai[i] == -1){
            root = i;
             break;
         }
      //printf("%d %d\n", root, pai[root]);
      level[root] = 0;
      pai[root] = root;
      dfs(root);*/
      for(int i = 1; i <= n; ++i)   ancestral[i][0] = pai[i];

      for(int j = 1; j <= 22; ++j)
         for(int i = 1; i <= n; ++i)
            ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
      scanf("%d", &q);
      for(int i = 1; i <= q; ++i){
         scanf("%d %d", &aux, &auy);
         ans[i] = LCA(aux, auy);
      }
      printf("Case %d:\n", c);
      for(int i = 1; i <= q; ++i)   printf("%d\n", ans[i]);
   }

   return 0;
}
