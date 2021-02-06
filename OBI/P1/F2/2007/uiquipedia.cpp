#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;
map <string, int> mapa;
int G[2010][2010], dist[2010];
void bfs(int cont, int x){
   for(int i = 0; i < cont; ++i) dist[i] = INF;
   queue <int> q;
   q.push(x);
   dist[x] = 0;
   int davez;
   while(!q.empty()){
      davez = q.front();q.pop();
      for(int i = 0; i < cont; ++i)
         if(G[davez][i] && dist[i] == INF){
            dist[i] = dist[davez] + 1;
            q.push(i);
         }
   }
   return;
}
int main(){
   int n, cont = 0;
   string x, y;
   scanf("%d", &n);
   for(int i = 0; i < n; ++i){
      cin >> x >> y;
      if(mapa.count(x) == 0)  mapa.insert(pair<string, int>(x, cont++));
      if(mapa.count(y) == 0)  mapa.insert(pair<string, int>(y, cont++));
      G[mapa[x]][mapa[y]] = 1;
   }
   map <string, int>::iterator it;
   for(it = mapa.begin(); it != mapa.end(); ++it){ //ref seq
      if(++it != mapa.end()){
         --it;
         G[it -> second][(++it) -> second] = 1;--it;
         G[(++it) -> second][(--it) -> second] = 1;
      }
      else  --it;
   }
   cin >> x >> y;
   bfs(cont, mapa[x]);
   printf("%d\n", dist[mapa[y]]);
   return 0;
}
