#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//------------------------
#define ff first
#define ss second
#define INF 1 << 29
typedef pair<int, int> pii;

int dist[1 << 14][2];

vector <pii> adj[1 << 14];
//------------------------

void djikstra(int x){
   priority_queue<pii, vector<pii>, greater<pii> > pq; //fazer uma min-heap
   int davez, menor = INF;

   for(int i = 1; i < 1 << 14; ++i) dist[i][0] = INF;
   for(int i = 1; i < 1 << 14; ++i) dist[i][1] = INF;
   dist[x][0] = 0;
   pq.push(pii(0, x));

   while(1){
      davez = -1, menor = INF;
      while(pq.size()){
         int d = pq.top().ff;
         int v = pq.top().ss;
         pq.pop();

         if(dist[v][0] != d && dist[v][1] != d)  continue;
         davez = v;
         break;
      }
      if(davez == -1)   break;

      for(int i = 0; i < (int)adj[davez].size(); ++i){
         int v = adj[davez][i].ss;
         int d = adj[davez][i].ff;

         if(dist[v][1] > dist[davez][0] + d){
            dist[v][1] = dist[davez][0] + d;
            pq.push(pii(dist[v][1], v));
         }

         if(dist[v][0] > dist[davez][1] + d){
            dist[v][0] = dist[davez][1] + d;
            pq.push(pii(dist[v][0], v));
         }

      }
   }
   return;
}

int main(){
   ios_base::sync_with_stdio(0);
   int c, v, a, b, d;
   cin >> c >> v;

   for(int i = 0; i < v; ++i){
      cin >> a >> b >> d;
      adj[a].push_back(pii (d, b));
      adj[b].push_back(pii (d, a));
   }
   djikstra(1);
   if(dist[c][0] != INF )cout << dist[c][0] << "\n";
   else  cout << "-1\n";
   return 0;

}
