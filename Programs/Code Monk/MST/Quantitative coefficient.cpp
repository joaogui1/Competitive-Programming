#include <bits/stdc++.h>
#define ff first
#define ss second
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;
typedef pair <ll, pii> pli;

ll ans;
int pai[1600], rak[1600];
vector <pli> edges;

int find(int x){
  return (x == pai[x])?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
  x = find(x), y = find(y);

  if(rak[x] > rak[y]) pai[y] = x;

  else if(rak[y] > rak[x])  pai[x] = y;

  else{
    ++rak[x];
    pai[y] = x;
  }
  return;
}

void join(pii x){
  join(x.first, x.second);
  return;
}

void initialize(){
  ans = 1;
  edges.clear();
  memset(rak, 0, sizeof rak);
  for(int i = 0; i < 1600; ++i) pai[i] = i;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, aux, auy;
  ll c;
  cin >> t;
  while(t--){
    cin >> n >> m;
    initialize();

    for(int i = 0; i < m; ++i){
      cin >> aux >> auy >> c;
      edges.push_back(pli(c, pii(aux, auy)));
    }
    sort(edges.begin(), edges.end());

    for(pli const & e: edges)
      if(find(e.second.first) != find(e.second.second)){
        join(e.second);
        ans *= e.first;
        if(ans >= MOD) ans %= MOD;
      }

    cout << ans << "\n";
  }


  return 0;
}
