#include <bits/stdc++.h>

using namespace std;

set <int> resp;
vector <int> adj[1000010], aux;
int sz[1000010], nx[1000010], mark[1000010], era[1000010], id[1000010];


int find_cycle(int u, int c){
  int v;
  mark[u] = c;
  if(nx[u] == u){
    nx[u] = 0; //connects to 0
    return 0;
  }
  if(mark[nx[u]] == c){ //found cycle
    id[u] = nx[u];
    nx[u] = 0; //points the end of the cycle to 0
    return id[u];
  }
  if(!mark[nx[u]])  v = find_cycle(nx[u], c); //looks for cycle
  if(v == u || v == 0)  return 0; //if no cycle found or he is the root of the cycle
  id[u] = v;
  return v;
}

int dfs(int u){
  sz[u] = 1;
  int v, bc, val = 0;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    dfs(v);
    if(sz[v] > val){
      bc = v;
      val = sz[v];
    }
  }
  sz[u] += val;
  return sz[u];
}

int Erase(int u){
  era[u] = 1;
  for(int i = 0; i < adj[u].size(); ++i)
    if(!era[adj[u][i]] && sz[adj[u][i]] + 1 == sz[u])
        return Erase(adj[u][i]);
  return u;
}

bool comp(int a, int b){
  return sz[a] > sz[b];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, k, mx_idx, ans = 0;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i)
    cin >> nx[i];

  for(int i = 1; i <= n; ++i)
    id[i] = i;

  for(int i = 1; i <= n; ++i)
    if(!mark[i]){
      //cout << "debug: " << i << "\n";
      find_cycle(i, i);
    }


  for(int i = 1; i <= n; ++i)
    if(id[i] != id[nx[i]]) //se nao estao no mesmo ciclo
      nx[i] = id[nx[i]];  //se nx[i] nao esta em um ciclo isso faz nada

  for(int i = 1; i <= n; ++i)
    adj[nx[i]].push_back(i);

  dfs(0);

  for(int i = 1; i <= n; ++i) aux.push_back(i);
  sort(aux.begin(), aux.end(), comp);
  for(int i = 0; i < n && resp.size() < k; ++i){
    if(!era[aux[i]]){
      ans += sz[aux[i]];
      resp.insert(Erase(aux[i]));
    }
  }
  for(int i = 1; i <= n && resp.size() < k; ++i)
    resp.insert(i);
  cout << ans << "\n";
  for(set<int>::iterator it = resp.begin(); it != resp.end(); ++it)
    cout << (*it) << " ";
  cout << "\n";

  return 0;
}
