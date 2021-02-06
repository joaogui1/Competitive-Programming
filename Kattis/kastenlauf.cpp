#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

vector <pll> points;
ll G[128][128];

void fw(int n){
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
  return;
}

void initialize(){
  points.clear();
  for(int i = 0; i < 128; ++i)
    for(int j = 0; j < 128; ++j)
      G[i][j] = 1LL << 40;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n,t;
  pll aup;
  cin >> t;
  while(t--){
    initialize();
    cin >> n;
    for(int i = 0; i < n + 2; ++i){
      cin >> aup.ff >> aup.ss;
      points.push_back(aup);
    }
    for(int i = 0; i < n + 2; ++i)
      for(int j = 0; j < i; ++j)
        G[i][j] = G[j][i] = abs(points[i].ff - points[j].ff) + abs(points[i].ss - points[j].ss);
    fw(n + 2);
    cout << ((G[0][n + 1] > 1000)?"sad\n":"happy\n");
  }


  return 0;
}
