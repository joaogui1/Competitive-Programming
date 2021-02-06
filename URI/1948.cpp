#include <bits/stdc++.h>

using namespace std;

string ins[4][1024];
map <string, int> dict;
vector <int> adj[4196];
int app[4][4196], mark[4196];

int dfs(int x, int c){
  int ret = 1;
  mark[x] = c;
  for(int i = 0; i < adj[x].size(); ++i){
    if(!mark[adj[x][i]])
      ret &= dfs(adj[x][i], c&1 + 1);
    else if(mark[adj[x][i]] == c)
      ret = 0;
  }
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string op, ans[2] = {"Compilation Error", "OK"};
  int a, b, cont = 0, idx = 1;
  for(int i = 0; getline(cin, op); ++i){
    a = op.find(" ");
    ins[0][i] = op.substr(0, a);
    a = op.find("+");
    if(a == string::npos){
      ins[2][i] = "0";
      ins[1][i] = op.substr(op.find("=") + 2);
    }
    else{
      ins[2][i] = op.substr(a + 2);
      b = op.find("=");
      ins[1][i] = op.substr(b + 2, a - b - 3);
    }
  }

  memset(app, -1, sizeof app);

  for(int i = 0; ins[i][0] != ""; ++i){
    if(!dict.count(ins[i][0])) dict[ins[i][0]] = cont++;
    if(app[0][dict[ins[i][0]]] == -1) app[0][dict[ins[i][0]]] = i;
    app[1][dict[ins[i][0]]] = i;

    if(!dict.count(ins[i][1])) dict[ins[i][1]] = cont++;
    if(app[0][dict[ins[i][1]]] == -1) app[0][dict[ins[i][1]]] = i;
    app[1][dict[ins[i][1]]] = i;

    if(ins[2][0] != "0"){
      if(!dict.count(ins[i][2])) dict[ins[i][2]] = cont++;
      if(app[0][dict[ins[i][2]]] == -1) app[0][dict[ins[i][2]]] = i;
      app[1][dict[ins[i][2]]] = i;
    }
  }
  for(int i = 0; i < cont; ++i)
    for(int j = app[0][i] + 1; j <= app[1][i]; ++j){
      adj[dict[ins[0][j]]].push_back(i);
      adj[i].push_back(dict[ins[0][j]]);
    }
  for(int i = 0; i < cont; ++i){
    if(!mark[i])  idx &= dfs(i, 0);
  }


  cout << ans[idx] << "\n";
  return 0;
}
