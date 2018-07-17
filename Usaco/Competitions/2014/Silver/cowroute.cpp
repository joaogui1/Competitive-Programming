#include <bits/stdc++.h>
#define INF (1LL << 50)
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

int v[128], n, mark[1 << 10];
pll G[1 << 10][1 << 10];

void dijkstra(int x){
  G[x][x] = pll(0, 0);
  mark[x] = 1;
  pll mn;
  int davez = -1;
  while(1){
    mn = pll(INF, INF), davez = -1;
    for(int i = 1; i <= n; ++i){
      if(!mark[i] && G[x][i].ff < INF)
        if(G[x][i].ff < mn.ff || G[x][i].ff == mn.ff && G[x][i].ss < mn.ss){
          mn = G[x][i];
          davez = i;
      }
    }
    if(davez == -1) break;

    mark[davez] = 1;

    for(int i = 1; i <= n; ++i)
      G[x][i] = min(G[x][i], pll(G[x][davez].ff + G[davez][i].ff, G[x][davez].ss + G[davez][i].ss));

  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("cowroute.in");
  ofstream fout ("cowroute.out");
  int c = -1;
  ll a, b, m, x, y;
  fin >> a >> b >> n;

  for(int i = 0; i <= 1000; ++i)
    for(int j = 0; j <= 1000; ++j)
      G[i][j] = pll(INF, INF);
  for(int i = 0; i < n; ++i){
    fin >> y >> m;
    for(int j = 0; j < m; ++j){
      fin >> v[j];
      c = max(c, v[j]);
    }
    for(int j = 0; j < m; ++j)
      for(int k = j + 1; k < m; ++k)
        if(y < G[v[j]][v[k]].ff || y == G[v[j]][v[k]].ff && k - j < G[v[j]][v[k]].ss){
          G[v[j]][v[k]].ff = y;
          G[v[j]][v[k]].ss = k - j;
        }
  }
  n = c;

  dijkstra(a);
  if(G[a][b].ff == INF) G[a][b] = pll(-1, -1);
  fout << G[a][b].ff << " " << G[a][b].ss << "\n";
  return 0;
}
