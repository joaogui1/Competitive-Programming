#include <bits/stdc++.h>

using namespace std;

string s[256];
vector <int> adj[20200];
int id[256][256], cor[20200], m[20200];

int arg(int u){
  int v;
  if(cor[u])  return 0;
  cor[u] = 1;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!m[v] || arg(m[v])){
      m[v] = u;
      return 1;
    }
  }
  return 0;
}

void initialize(){
  memset(m, 0, sizeof m);
  memset(id, 0, sizeof id);
  memset(cor, 0, sizeof cor);
  for(int i = 0; i < 10100; ++i)  adj[i].clear();
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, cont, num, ans;
  while(cin >> n){
    ans = 0;
    cont = 1;
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> s[i];
      for(int j = 0; j < n; ++j){
        if(s[i][j] == 'X')  ++cont;
        else id[i][j] = cont;
      }
      ++cont;
    }


    num = cont;
    for(int j = 0; j < n; ++j){
      ++cont;
      for(int i = 0; i < n; ++i){
        if(s[i][j] == 'X')  ++cont;
        else if(adj[id[i][j]].size() == 0 || adj[id[i][j]][adj[id[i][j]].size() - 1] != cont)  adj[id[i][j]].push_back(cont);
      }
    }

    for(int i = 1; i <= num; ++i){
      ans += arg(i);
      memset(cor, 0, sizeof cor);
    }
    cout << ans << "\n";

  }

  return 0;
}
