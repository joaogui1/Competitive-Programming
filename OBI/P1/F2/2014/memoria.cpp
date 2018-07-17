#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#define INF 1 << 20
#define MAXL    20
#define MAXN 50500
using namespace std;
int pos[MAXN], pai[MAXN], par[MAXN], n, nivel[MAXN], ancestral[MAXN][MAXL];
vector <int> vizinhos[MAXN];
/*
   cards[i]: guarda o valor da carta i
   nivel[i]: guarda as cartas no nivel i
   vizinhos[i]: guarda os vizinhos da carta na posicao i
   bfs: nivela o povo
   lca (experimental): acha a distancia entre dois caras (2 vezes a pos do menor ancestral comum)
*/
void bfs(){
   for(int i = 1; i <= n; ++i) nivel[i] = INF;
   int davez, v;
   queue <int> q;
   q.push(1);
   nivel[1] = 0;
   while(!q.empty()){
      davez = q.front();q.pop();
      for(int i = 0; i < vizinhos[davez].size(); ++i){
         v = vizinhos[davez][i];
         if(nivel[v] == INF){
            nivel[v] = nivel[davez] + 1;
            pai[v] = davez;
            q.push(v);
         }
      }
   }
   return;
}
int LCA(int u, int v){

    if(nivel[u] < nivel[v]) swap(u, v);
    for(int i = MAXL-1;i >= 0;i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];
    if(u == v) return u;
    for(int i = MAXL-1;i >= 0;i--)
        if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return pai[u];
}
int main(){
   int a, b, aux;
   long long int ans = 0LL;
   scanf("%d", &n);
   for(int i = 1; i <= n; ++i){
      scanf("%d", &aux);
      if(pos[aux]){
         par[i] = pos[aux];
         par[pos[aux]] = i;
      }
      pos[aux] = i;
   }
   for(int i = 0; i < n - 1; ++i){
      scanf("%d %d", &a, &b);

      vizinhos[a].push_back(b);
      vizinhos[b].push_back(a);
   }
   bfs();
   for(int i = 1;i <= n;i++) ancestral[i][0] = pai[i];
   for(int j = 1;j < MAXL;j++)
      for(int i = 1;i <= n;i++)
        ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
   for(int i = 1;i <= n;i++)
      ans += (long long)( nivel[i] + nivel[par[i]] - 2*nivel[ LCA(i, par[i]) ]);
   printf("%lld\n", ans/2);
   return 0;
}
