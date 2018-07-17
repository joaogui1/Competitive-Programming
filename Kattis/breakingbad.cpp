#include <bits/stdc++.h>

using namespace std;

int mark[100100];
vector <string> jesse;
map <int, string> dict;
vector <string> walter;
map <string, int> _dict;
vector <int> adj[100100];

bool dfs(int x, int color){
  mark[x] = color;
  for(int const & v: adj[x]){
    if(mark[v] == mark[x])
      return false;
    else if(mark[v] == 0)
      if(!dfs(v, -color))
        return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m;
  bool vdc = 1;
  string aux, auy;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aux;
    dict[i] = aux;
    _dict[aux] = i;
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    cin >> aux >> auy;
    adj[_dict[aux]].push_back(_dict[auy]);
    adj[_dict[auy]].push_back(_dict[aux]);
  }

  for(int i = 0; i < n; ++i)
    if(mark[i] == 0)
      vdc &= dfs(i, 1);

  if(!vdc)  cout << "impossible\n";
  else{
    for(int i = 0; i < n; ++i){
      if(mark[i] == -1)
        walter.push_back(dict[i]);
      else
        jesse.push_back(dict[i]);
    }

    for(const string & s: walter)
      cout << s << " \n"[s == walter[(int)walter.size() - 1]];
    for(const string & s: jesse)
      cout << s << " \n"[s == jesse[(int)jesse.size() - 1]];

  }
  return 0;
}
