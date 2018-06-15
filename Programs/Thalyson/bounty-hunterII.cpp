#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1 << 11];
int cor[1 << 11], m[1 << 11];

int arg(int u){
  int v;
  if(cor[u])  return 0;
  cor[u] = 1;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(m[v] == -1 || arg(m[v])){
      m[v] = u;
      return 1;
    }
  }
  return 0;
}

void initialize(){
  for(int i = 0; i < (1 << 11); ++i)  m[i] = -1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, v;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> m;
    for(int j = 0; j < m; ++j){
      cin >> v;
      adj[i].push_back(v + n);
    }
  }
  m = 0;
  initialize();
  for(int i = 0; i < n; ++i){
    m += arg(i);
    memset(cor, 0, sizeof cor);
  }
  cout << n - m << "\n";

  return 0;
}
