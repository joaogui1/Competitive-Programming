#include <bits/stdc++.h>

using namespace std;

map <string, int> dict;
vector <int> adj[100100];
int nfiles, nfolders, child[100100], cost[100100], p[100100], sz[100100];

void read(){
  int last = 0;
  string in, s;
  cin >> nfiles;
  child[0] = nfiles;

  for(int i = 0; i < nfiles; ++i){
    cin >> in;
    last = 0;
    cost[0] += in.size();
    for(int j = 0; j < in.size(); ++j){
      s += in[j];
      if(j == in.size() - 1){
        s.clear();
        break;
      }
      if(in[j] == '/'){
        if(!dict.count(s)){
          dict[s] = ++nfolders;

          p[nfolders] = last;
          sz[nfolders] = s.size();
          adj[last].push_back(nfolders);
        }
        ++child[dict[s]];
        last = dict[s];
        s.clear();
      }

    }
  }
}

void f(int x){
  cost[x] = cost[p[x]] - sz[x]*child[x] + 3*(nfiles - child[x]);
  for(int i = 0; i < adj[x].size(); ++i)  f(adj[x][i]);
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int ans = (1 << 30);
  read();

  for(int i = 0; i < adj[0].size(); ++i)  f(adj[0][i]);
  for(int i = 0; i <= nfolders; ++i) ans = min(ans, cost[i]);
  cout << ans << "\n";
  return 0;
}
