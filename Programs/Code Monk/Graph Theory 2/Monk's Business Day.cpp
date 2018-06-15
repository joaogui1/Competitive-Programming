#include <bits/stdc++.h>
#define INF 1 << 28

using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> iii;

int dist[1024], pred[1024];
vector <iii> edges;

void print(int v){
  cout << v << " ";
  if(pred[v] != -1) print(pred[v]);
  //cout << v << " ";
  return;
}

bool bf(int src, int n){
  dist[src] = 0;
  for(int i = 1; i <= n; ++i)
    for(iii const & e : edges)
      if(dist[e.first.first] + e.second < dist[e.first.second]){
        dist[e.first.second] = dist[e.first.first] + e.second;
        pred[e.first.second] = e.first.first;
      }

  for(iii const & e : edges){
    if(dist[e.first.first] + e.second < dist[e.first.second] && dist[e.first.first] < 1 << 13){
      //print(e.first.second);
      //cout << endl;
      return 1;
    }
  }
  return 0;

}

void initialize(){
  edges.clear();
  for(int i = 0; i < 1024; ++i) pred[i] = -1;
  for(int i = 0; i < 1024; ++i) dist[i] = INF;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, a, b, c;
  cin >> t;
  while(t--){
    initialize();
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
      cin >> a >> b >> c;
      edges.push_back(iii(pii(a, b), -c));
    }

    cout << ((bf(1, n))?("Yes\n"):("No\n"));

  }


  return 0;
}
