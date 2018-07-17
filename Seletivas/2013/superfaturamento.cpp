#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

vector <ppi> edges;
vector <int> adj[1024];
int p[1024], r[1024], mx_edges[1024][1024], edj[1024][1024];

void dfs(int x, int y, int z){
  int v;
  mx_edges[x][y] = z;
  for(int i = 0; i < adj[y].size(); ++i){
    v = adj[y][i];
    if(mx_edges[x][v] == 0 && x != v)
      dfs(x, v, max(mx_edges[x][y], edj[y][v]));
  }
  return;
}

int find(int x){
  return (x == p[x])?x:(p[x] = find(p[x]));
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(r[x] > r[y]){
    p[y] = x;
    return;
  }
  p[x] = y;
  if(r[x] == r[y])  ++r[y];
  return;
}

int main(){
  ppi cur;
  int n, cost = 0, ans = (1 << 28);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)  p[i] = i, r[i] = 1;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
      scanf("%d", &edj[i][j]);
      edges.push_back(ppi(edj[i][j], pii(i, j)));
    }

  sort(edges.begin(), edges.end());
  for(int i = 0; i < edges.size(); ++i){
    if(find(edges[i].ss.ff) != find(edges[i].ss.ss)){
      join(edges[i].ss.ff, edges[i].ss.ss);
      adj[edges[i].ss.ff].push_back(edges[i].ss.ss);
      adj[edges[i].ss.ss].push_back(edges[i].ss.ff);
    }
  }

/*  for(int i = 0; i < n; ++i){
    cout << i << ": ";
    for(int j = 0; j < adj[i].size(); ++j)
      cout << adj[i][j] << " ";
    cout << "\n";
  }*/

  for(int i = 0; i < n; ++i)
    dfs(i, i, 0);
    //for(int j = 0; j < adj[i].size(); ++j)

  /*for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cout << mx_edges[i][j] << " \n"[j == n - 1];*/

  for(int i = 0; i < edges.size(); ++i){
    cur = edges[i];
    if(mx_edges[cur.ss.ff][cur.ss.ss] >= cur.ff) continue;
    ans = min(ans, cur.ff - mx_edges[cur.ss.ff][cur.ss.ss]);
  }

  printf("%d\n", ans);

  //cost -= mst[mst.size() - 1].ff;
  //cost += v[0].ff;
  return 0;
}
