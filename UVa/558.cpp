#include <bits/stdc++.h>
#define u(x) get<0>(x)
#define v(x) get<1>(x)
#define w(x) get<2>(x)

using namespace std;
typedef tuple<int, int, int> tii;

int dist[1 << 10];
vector <tii> edges;

bool bf(int n){
  dist[0] = 0;
  for(int i = 1; i < n; ++i)
    for(auto const & e: edges)
      if(dist[v(e)] > dist[u(e)] + w(e))
        dist[v(e)] = dist[u(e)] + w(e);
  for(tii const & e: edges){
    if(dist[v(e)] > dist[u(e)] + w(e))
      return 1;
    }
  return 0;
}

void initialize(int n){
  edges.clear();
  for(int i = 0; i < n; ++i)  dist[i] = 1 << 28;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, aux, auy, aut, t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    initialize(n);
    for(int i = 0; i < m; ++i){
      cin >> aux >> auy >> aut;
      edges.push_back(tii(aux, auy, aut));
    }
    if(bf(n)) cout << "possible\n";
    else  cout << "not possible\n";
  }

  return 0;
}
