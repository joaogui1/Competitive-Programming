#include <bits/stdc++.h>
#define ff first
#define ss second
// #define DEBUG 1
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;

int mark[100100];
vector <int> adj[100100];
string ans[2] = {"NO", "YES"};

bool dfs(int x, int c){
  mark[x] = c;
  bool ret = 1;
  for(int i = 0; i < adj[x].size(); ++i)
    if(mark[adj[x][i]] == 0)
      ret &= dfs(adj[x][i], (c&1) + 1);
    else if(mark[adj[x][i]] == c)
      return 0;
  return ret;
}

int main(){
  #ifndef DEBUG
    ifstream fin ("bipartite.in");
    ofstream fout ("bipartite.out");
  #endif
  bool vdc = 1;
  int n, m, a, b;
  vector<int>::iterator it;
  fin >> n >> m;
  for(int i = 0; i < m; ++i){
    fin >> a >> b;
    // if(a != b)
    adj[a].push_back(b), adj[b].push_back(a);
  }
  for(int i = 1; i <= n; ++i){
    sort(adj[i].begin(), adj[i].end());
    it = unique(adj[i].begin(), adj[i].end());
    adj[i].resize(distance(adj[i].begin(), it));
  }
  for(int i = 1; i <= n; ++i)
    if(!mark[i])
      vdc &= dfs(i, 1);
  fout << ans[vdc] << "\n";
  return 0;
}
