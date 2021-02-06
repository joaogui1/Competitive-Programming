#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <double, int> pdi;

double dist[10100];
vector <pdi> adj[10100];

void dijkstra(){
  int v;
  pdi aux;
  double d;
  dist[0] = 1.00;
  priority_queue<pdi> pq;
  pq.push(pdi(dist[0], 0));

  while(pq.size()){
    v = -1;
    while(pq.size()){
      aux = pq.top();pq.pop();
      if(dist[aux.ss] != aux.ff)  continue;
      d = aux.ff;
      v = aux.ss;
      break;
    }
    if(v == -1) break;

    for(pdi const & e : adj[v])
      if(dist[e.ss] < d*e.ff){
        dist[e.ss] = d*e.ff;
        pq.push(pdi(dist[e.ss], e.ss));
      }

  }
  return;
}

void initialize(int n){
  for(int i = 0; i < n; ++i)  dist[i] = 0.0;
  for(int i = 0; i < n; ++i)  adj[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  double c;
  int n, m, a, b;
  while(cin >> n >> m){
    if(n == 0 && m == 0)  return 0;
    initialize(n);
    for(int i = 0; i < m; ++i){
      cin >> a >> b >> c;
      adj[a].push_back(pdi(c, b));
      adj[b].push_back(pdi(c, a));
    }
    dijkstra();
    cout << fixed << setprecision(4) << dist[n - 1] << "\n";
  }



  return 0;
}
