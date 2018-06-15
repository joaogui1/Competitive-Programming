#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

vector<pll> rain;
ll n, seg[200200];
map <ll, ll> dict;
map <ll, ll> posi;

void make_tree(int node, int l, int r){
  if(l == r){
    seg[node] = rain[l].ff;
    return;
  }
  int m = (l + r) >> 1;
  make_tree(2*node, l, m);
  make_tree(2*node + 1, m + 1, r);
  seg[node] = max(seg[2*node], seg[2*node + 1]);
  return;
}

int query(int node, int l, int r, int a, int b){
  if(l > b || a > r)  return 0;

  if(a <= l && r <= b)  return seg[node];

  int m = (l + r) >> 1;

  return max(query(2*node, l, m, a, b), query(2*node + 1, m + 1, r, a, b));
}

void initialize(){
  dict.clear();
  posi.clear();
  rain.clear();
  for(int i = 0; i < 200200; ++i) seg[i] = 0;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  ll m, r, x, y, y2, ma, posx, posy;
  map<ll, ll>::iterator it;
  for(int q = 0; cin >> n; ++q){
    if(n == 0)  break;
    if(q != 0)  cout << "\n";
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> x >> r;
      rain.pb(pll(r, x));
      dict[x] = r;
      posi[x] = i;

    }
    make_tree(1, 1, n);
    cin >> m;

    while(m--){
      cin >> y >> x;
      if(posi.count(x) == 0)  cout << "maybe\n";
      else{
        it = posi.upper_bound(y);
        y2 = it -> ff;
        ma = query(1, 1, n, posi[y2], posi[x] - 1);
        if(ma >= dict[x] || (posi.count(y) && dict[x] >= dict[y])) cout << "false\n";
        else{
          if(posi.count(y) && posi[x] - posi[y] == x - y) cout << "true\n";
          else  cout << "maybe\n";
        }
      }
    }
  }
  return 0;
}
