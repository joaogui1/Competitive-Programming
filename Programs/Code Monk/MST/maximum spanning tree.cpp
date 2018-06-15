#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair< int, pii> iii;

vector <iii> edges;
int pai[5010], rak[5010], cost, best;

int find(int x){
  if(x != pai[x]) return pai[x] = find(pai[x]);
  return x;
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(x == y)  return;

  if(rak[x] > rak[y])
    pai[y] = x;

  else if(rak[x] < rak[y])
    pai[x] = y;

  else{
    pai[y] = x;
    ++rak[x];
  }

  return;
}

void join(pii x){
  join(x.first, x.second);
  return;
}

void initialize(){
  edges.clear();
  cost = best = 0;
  memset(rak, 0, sizeof rak);
  for(int i = 0; i < 5010; ++i) pai[i] = i;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, aux, auy, c;
  cin >> t;
  while(t--){
    initialize();
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
      cin >> aux >> auy >> c;
      cost += c;
      edges.push_back(iii(c, pii(aux, auy)));
    }
    for(int i = 0; i < edges.size(); ++i) edges[i].first = cost - edges[i].first;
    sort(edges.begin(), edges.end());

    for(iii & e : edges)
      if(find(e.second.first) != find(e.second.second)){
        join(e.second);
        best += e.first;
      }
    best = (n - 1)*cost - best;

    cout << best << "\n";
  }


  return 0;
}
