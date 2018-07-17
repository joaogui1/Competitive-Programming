#include <bits/stdc++.h>

using namespace std;

string cmt[1024];
vector <int> adj[1024];
int freq[1024][32], m[1024], cor[1024];

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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char lt;
  int n, m, fr, ans = 0;
  cin >> n >> m;
  getline(cin, cmt[0]);
  for(int i = 1; i <= n; ++i){
    getline(cin, cmt[i]);
    for(int j = 0; j < cmt[i].size(); ++j){
      if('a' <= cmt[i][j] && cmt[i][j] <= 'z') ++freq[i][cmt[i][j] - 'a'];
      if('A' <= cmt[i][j] && cmt[i][j] <= 'Z') ++freq[i][cmt[i][j] - 'A'];
    }
  }

  for(int i = 1; i <= m; ++i){
    cin >> lt >> fr;
    for(int j = 1; j <= n; ++j)
      if(freq[j][lt - 'A'] >= fr) adj[i].push_back(j);
  }

  for(int i = 1; i <= m; ++i){
    ans += arg(i);
    memset(cor, 0, sizeof cor);
  }
  cout << ans << "\n";
  return 0;
}
