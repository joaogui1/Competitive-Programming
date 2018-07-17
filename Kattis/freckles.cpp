#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <double, double> pdd;
typedef pair <double, pdd> pdp;
typedef pair <double, pair <int, int> > dii;

vector <dii> edges;
map <int, pdd> dict;
int p[1 << 10], r[1 << 10];

int find(int x){
  return (x == p[x])?(x):(p[x] = find(p[x]));
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(r[x] > r[y])
    p[y] = x;
  else if (r[x] < r[y])
    p[x] = y;
  else{
    p[y] = x;
    ++r[x];
  }
  return;
}

double dist(int i, int j){
  return sqrt((dict[i].ff - dict[j].ff)*(dict[i].ff - dict[j].ff) + (dict[i].ss - dict[j].ss)*(dict[i].ss - dict[j].ss));
}

void initialize(){
  dict.clear();
  edges.clear();
  memset(r, 0, sizeof r);
  for(int i = 0; i < (1 << 10); ++i)  p[i] = i;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, cont;
  double x, y, ans;
  cin >> t;
  for(int  q = 0; q < t; ++q){
    ans = 0;
    cin >> n;
    cont = 0;
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> x >> y;
      dict[i] = pdd(x, y);
    }
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if(i != j)
          edges.push_back(dii(dist(i, j), pair<int, int>(i, j)));
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size() && cont < n - 1; ++i){
      if(find(edges[i].ss.ff) != find(edges[i].ss.ss)){
        ans += edges[i].ff;
        ++cont;
        join(edges[i].ss.ff, edges[i].ss.ss);
      }
    }
    if(q != 0)  cout << "\n";
    cout << fixed << setprecision(2) << ans << "\n";
  }


  return 0;
}
