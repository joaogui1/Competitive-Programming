#include<bits/stdc++.h>

using namespace std;

bool vdc;
stack <int> comp;
vector <bool> incomp;
int n, m, curnum, csz;
vector <int> low, num;
vector <int> adj[2048];

void scc(int u){
  int v;
  if(!vdc) return;
  comp.push(u);
  incomp[u] = 1;

  low[u] = num[u] = ++curnum;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(num[v] == -1){
      scc(v);
      low[u] = min(low[u], low[v]);
    }
    else if(incomp[v])  low[u] = min(low[u], low[v]);
  }

  if(low[u] == num[u]){
    csz = 0;
    for(; v != u; ++csz) v = comp.top(), comp.pop();
    //cout << n << " " << csz << endl;
    if(csz != n)  vdc = 0;
  }

  return;
}

void initialize(){
  vdc = 1;
  curnum = 0;
  for(int i = 0; i <= n; ++i)  adj[i].clear();
  low.assign(n + 1, 20000);
  num.assign(n + 1, -1);
  incomp.assign(n + 1, 0);
  while(comp.size())  comp.pop();
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int a, b, op;
  while(1){
    cin >> n >> m;
    if(n == m && m == 0) return 0;
    initialize();
    for(int i = 0; i < m; ++i){
      cin >> a >> b >> op;
      adj[a].push_back(b);
      if(op == 2) adj[b].push_back(a);
    }
    scc(1);
    cout << vdc << "\n";
  }


  return 0;
}
