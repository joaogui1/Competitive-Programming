#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF 1 << 28

using namespace std;
typedef pair<int, int> pii;

int dist[10010];
vector <pii> adj[10010];

void dijkstra(int x){
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  dist[x] = 0;
  int aux;
  pq.push(pii(0,x));

  while(1){
    aux = -1;
    while(pq.size()){
      int d = pq.top().ff;
      int v = pq.top().ss;
      pq.pop();
      if(dist[v] != d)  continue;
      aux = v;
      break;
    }
    if(aux == -1) break;
    //cout << aux << endl;

    for(pii const & e: adj[aux]){
      int v = e.ss;
      int d = e.ff;
      if(dist[v] > dist[aux] + d){
        dist[v] = dist[aux] + d;
        pq.push(pii(dist[v], v));
      }
    }

  }
  return;
}

void initialize(){
  for(int i = 0; i < 10010; ++i)  dist[i] = INF;
  for(int i = 0; i < 10010; ++i)  adj[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, q, x, y, a, c, k;
  cin >> t;
  while(t--){
    cin >> n >> m;
    initialize();
    for(int i = 0; i < m; ++i){
      cin >> x >> y >> c;
      adj[x].push_back(pii(c, y));
      adj[y].push_back(pii(c, x));
    }
    dijkstra(1);
    cin >> q;

    for(int i = 0; i < q; ++i){
      cin >> a >> k;
      //cout << endl << dist[a]<< endl;
      if(2*dist[a] >= k)  cout << "0\n";
      else  cout << k - 2*dist[a] << "\n";
    }
  }


  return 0;
}
