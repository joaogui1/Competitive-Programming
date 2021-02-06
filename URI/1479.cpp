#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#define ss second
#define ff first
#define MAXN 1010
#define INF 1 << 30
#define SET(obj, a)  memset(obj, a, sizeof(obj))
using namespace std;
typedef pair<int, int> pii;

int n, e, dist[MAXN];
vector <pii> adj[MAXN];
void djikstra(int x){
   priority_queue<pii, vector<pii>, greater<pii> > pq; //fazer uma min-heap
   int davez, menor = INF;

   for(int i = 1; i < MAXN; ++i) dist[i] = INF;
   dist[x] = 0;
   pq.push(pii(0, x));

   while(1){
      davez = -1, menor = INF;
      while(pq.size()){
         int d = pq.top().ff;
         int v = pq.top().ss;
         pq.pop();
         if(dist[v] != d)  continue;
         davez = v;
         break;
      }
      if(davez == -1)   break;

      for(int i = 0; i < (int)adj[davez].size(); ++i){
         int v = adj[davez][i].ss;
         int d = adj[davez][i].ff;
         if(dist[v] > dist[davez] + d){
            dist[v] = dist[davez] + d;
            pq.push(pii(dist[v], v));
         }
      }
   }
   return;
}
int main(){
   int m, n, q, u, v, w;
   char op;
   while(1){
      scanf("%d %d", &n, &m);
      if(n == 0 && m == 0) break;
      SET(dist, 0);SET(adj, 0);
      for(int i = 0; i < m; ++i){
         scanf("%d %d %d", &u, &v, &w);
         adj[u].push_back(pii(w, v));
         //adj[v].push_back(pii(w, u));
      }
      scanf("%d", &q);
      while(q--){
         scanf(" %c", &op);
         if(op == 'I'){
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(pii(w, v));
            //adj[v].push_back(pii(w, u));
         }
         else if(op == 'R'){
            scanf("%d %d", &u, &v);
            for(int i = 0; i < (int)adj[u].size(); ++i){
               if(adj[u][i].ss == v){
                  swap(adj[u][i], adj[u][adj[u].size() - 1]);
                  adj[u].pop_back();
               }
            }
            /*for(int i = 0; i < (int)adj[v].size(); ++i){
               if(adj[v][i].ss == u){
                  swap(adj[v][i], adj[v][adj[v].size() - 1]);
                  adj[v].pop_back();
               }
            }*/
         }
         else{
            scanf("%d", &u);
            djikstra(1);
            printf("%d\n", dist[u]);
         }
      }
      printf("\n");
   }
   return 0;
}
