#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;

vector <iii> edges;
int pai[1010], mae[1010], _rak[2][1010], male, both, female;

int find(int x, int *f){
  return (x == f[x])?x:(f[x] = find(f[x], f));
}

void join(int x, int y, int *f, int *rak){
  x = find(x, f), y = find(y, f);
  if(rak[x] > rak[y]) f[y] = x;
  else if(rak[y] > rak[x]) f[x] = y;
  else{
    ++rak[x];
    f[y] = x;
  }
  return;
}

void join(pii x, int *f){
  if(f == pai)  join(x.first, x.second, f, _rak[0]);
  else  join(x.first, x.second, f, _rak[1]);
  return;
}

void initialize(){
  edges.clear();
  male = female = both = 0;
  memset(_rak, 0, sizeof _rak);
  for(int i = 0; i < 1010; ++i) pai[i] = mae[i] = i;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, a, b, c, common;

    cin >> n >> m;
    initialize();
    for(int i = 0; i < m; ++i){
      cin >> a >> b >> c;
      edges.push_back(iii(c, pii(a, b)));
    }

    sort(edges.rbegin(), edges.rend());
    for(iii const & e : edges){
      if(e.first == 3){
        common = 0;
        if(find(e.second.first, pai) != find(e.second.second, pai)){
          ++male;
          common = 1;
          join(e.second, pai);
        }
        if(find(e.second.first, mae) != find(e.second.second, mae)){
          ++female;
          join(e.second, mae);
          if(common)  ++both;
        }
      }

      else if(e.first == 2){
        if(find(e.second.first, mae) != find(e.second.second, mae)){
          ++female;
          join(e.second, mae);
        }
      }

      else{
        if(find(e.second.first, pai) != find(e.second.second, pai)){
          ++male;
          join(e.second, pai);
        }
      }
    }
    if(male != n - 1 || female != n - 1)  cout << -1 << "\n";
    else  cout << m - (2*n - 2 - both) << "\n";




  return 0;
}
