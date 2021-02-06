#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;
int n, m, dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1}, dist[15][60][60], lab[60][60];
struct node{
   int x;
   int y;
   int turn;
};
node aux;
queue <node> q;
int bfs(){
   node davez;
   SET(dist, INF);
   aux.x = aux.y = aux.turn = 0;
   q.push(aux);
   dist[0][0][0] = 0;
   while(!q.empty()){
      davez = q.front();q.pop();
      for(int i = 0; i <= 4; ++i){
         node next;
         next.x = davez.x + dx[i];
         next.y = davez.y + dy[i];
         next.turn = (davez.turn + 1)%10;
         if(next.y < 0 || n <= next.y || next.x < 0 || m <= next.x) continue;
         if((lab[next.x][next.y] + davez.turn)%10 - 1 > (lab[davez.x][davez.y] + davez.turn)%10) continue;
         if(dist[next.turn][next.x][next.y] < INF) continue;
         dist[next.turn][next.x][next.y] = dist[davez.turn][davez.x][davez.y] + 1;
         q.push(next);
      }
   }
}
int main(){
   scanf("%d %d", &n, &m);
   for(int j = 0; j < n; ++j)
      for(int i = 0; i < m; ++i)
         scanf("%d", &lab[i][j]);
   bfs();
   int ans = INF;
   for(int i = 0; i < 10; ++i)
      ans = min(ans, dist[i][m - 1][n - 1]);
   printf("%d\n", ans);


   return 0;
}
