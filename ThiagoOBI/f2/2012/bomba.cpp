#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int dist[3][512];
vector <pii> adj[512];

void bfs(int u){
  int v, t;
  queue <pii> q;
  dist[0][u] = 0;
  q.push(pii(u, 0));
  while(q.size()){
    u = q.front().ff, t = q.front().ss;q.pop();
    for(int i = 0; i < adj[u].size(); ++i){
      if((adj[u][i].ss == 1 && (t%3) != 0) || (adj[u][i].ss == 0 && (t%3) == 0))  continue;
      v = adj[u][i].ff;
      if(dist[(t + 1)%3][v] == -1){
        q.push(pii(v, (t + 1)%3));
        dist[(t + 1)%3][v] = 1 + dist[t][u];
      }
    }
  }
}

int main(){
  int n, s, e, m, a, b, t;
  scanf("%d %d %d %d", &n, &e, &s, &m);
  for(int i = 0; i < m; ++i){
    scanf("%d %d %d", &a, &b, &t);
    adj[a].push_back(pii(b, t));
  }
  memset(dist, -1, sizeof dist);
  bfs(e);
  if(dist[0][s] == -1 && dist[1][s] == -1 && dist[2][s] == -1)  printf("*\n");
  else
    printf("%d\n", min((dist[0][s] == -1)?(1 << 28):dist[0][s], min((dist[1][s] == -1)?(1 << 28):dist[1][s], (dist[2][s] == -1)?(1 << 28):dist[2][s])));


  return 0;
}
