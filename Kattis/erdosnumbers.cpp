#include <bits/stdc++.h>

using namespace std;

int dist[1 << 21];
vector <int> join;
set <int> adj[1 << 21];
map <string, int> id, ego;
set<pair<int, string> > auth;
void bfs(int u){
  int v;
  memset(dist, -1, sizeof dist);
  dist[u] = 0;
  queue <int> q;
  q.push(u);
  while(q.size()){
    u = q.front();q.pop();
    for(set<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it){
      v = *it;
      if(dist[v] != -1) continue;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int aut = 0, beg = 0, num = 0;
  string s, in;
  while(getline(cin, in)){
    beg = 0;
    join.clear();
    for(int i = 0; i < in.size(); ++i){
      if(in[i] == ' ' || i == in.size() - 1){
        if(i == in.size() - 1)  ++i;
        s = in.substr(beg, i - beg);
        if(id.count(s) == 0)  id[s] = ++aut;
        if(beg == 0 && ego.count(s) == 0) ego[s] = ++num;
        if(beg == 0)  auth.insert(pair<int, string>(ego[s], s));
        join.push_back(id[s]);
        beg = i + 1;
      }
    }
    for(int i = 0; i < join.size(); ++i)
      for(int j = 0; j < join.size(); ++j)
        adj[join[i]].insert(join[j]);
  }

  bfs(id["PAUL_ERDOS"]);
  for(set<pair<int, string>>::iterator it = auth.begin(); it != auth.end(); ++it){
    cout << it -> second << " ";
    if(dist[id[it -> second]] == -1) cout << "no-connection\n";
    else  cout << dist[id[it -> second]] << "\n";
  }



  return 0;
}
