#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef pair <ld, ld> pld;
typedef pair <ld, int> pdi;

int cont;
vector <pld> points;
ld G[256][256], dista[256];

ld dist(pld a, pld b){
  return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

void fw(int n){
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        G[i][j] = min(G[i][j], max(G[i][k],G[k][j]));
  return;
}

void djikstra(int n){
  int v, idx;
  long double d;
  dista[0] = 0.0;
  priority_queue <pdi, vector<pdi>, greater< pdi > > pq;
  pq.push(pdi(0.0, 0));

  while(pq.size()){
    idx = -1;
    while(pq.size()){
      v = pq.top().second;
      d = pq.top().first;
      pq.pop();
      if(dista[v] != d) continue;
      idx = v;
      break;
    }
    if(idx == -1) break;

    for(int i = 0; i < n; ++i)
      if(dista[i] > max(G[i][idx], d)){
        dista[i] = max(G[i][idx], d);
        pq.push(pdi(dista[i], i));
      }
  }

}

void initialize(int n){
  cont = 0;
  points.clear();
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      G[i][j] = 1e15;
  for(int i = 0; i < n; ++i)  dista[i] = 1e15;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  long double aux, auy;
  cin >> n;
  for(int c = 1; n; ++c){
    initialize(n);
    cout << "Scenario #" << c << "\n";
    for(int i = 0; i < n; ++i){
      cin >> aux >> auy;
      points.push_back(pld(aux, auy));
    }

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        G[i][j] = dist(points[i], points[j]);
    //fw(n);
    djikstra(n);
    cout << "Frog Distance = ";
    cout << fixed << setprecision(3) << dista[1] << "\n\n";
    cin >> n;
  }


}
