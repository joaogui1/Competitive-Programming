#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppl;

ll val[2048];
vector <ppl> edges;
int p[2048], r[2048];

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
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream cin ("superbull.in");
  ofstream cout ("superbull.out");
  int n;
  ll cost = 0;
  cin >> n;
  for(int i = 0; i < n; ++i)  p[i] = i, r[i] = 0;
  for(int i = 0; i < n; ++i){
    cin >> val[i];
    for(int j = 0; j < i; ++j)
      edges.push_back(ppl(val[i]^val[j], pll(i, j)));
  }
  sort(edges.rbegin(), edges.rend());
  for(int i = 0; i < edges.size(); ++i)
    if(find(edges[i].ss.ff) != find(edges[i].ss.ss)){
      cost += edges[i].ff;
      join(edges[i].ss.ff, edges[i].ss.ss);
    }
  cout << cost << "\n";
  return 0;
}
