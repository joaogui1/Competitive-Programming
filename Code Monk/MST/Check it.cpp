#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

int pai[5010], rak[5010];
vector <pii> edges;

int find(int x){
  if(x != pai[x]) return pai[x] = find(pai[x]);
  return x;
}
bool vdc;

void join(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y)  return;

  if(rak[x] > rak[y])
    pai[y] = x;

  else if(rak[y] > rak[x])
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
  vdc = 1;
  edges.clear();
  memset(rak, 0, sizeof rak);
  for(int i = 0; i < 5010; ++i) pai[i] = i;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, aux, auy;
  cin >> t;
  while(t--){
    cin >> n >> m;
    initialize();
    for(int i = 0; i < m; ++i){
      cin >> aux >> auy;
      edges.push_back(pii(aux, auy));
    }

    for(int i = 0; i < n - 1; ++i){
      cin >> aux;
      join(edges[aux - 1]);
    }

    for(int i = 1; i <= n; ++i) vdc &= (find(1) == find(i));
    if(vdc) cout << "YES\n";
    else  cout << "NO\n";
  }


  return 0;
}
