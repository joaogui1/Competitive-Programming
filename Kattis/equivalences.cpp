#include <stack>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

stack<int> comp;
vector <bool> incomp(20010, 0);
vector <int> adj[20010], cc[20010];
vector <int> low(20010), num(20010, -1);
int n, m, curnum, numscc, in[20010], out[20010], bel[20010];

void scc(int u){
  int v;
  comp.push(u);
  incomp[u] = 1;

  low[u] = num[u] = curnum++;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(num[v] == -1){
      scc(v);
      low[u] = min(low[u], low[v]);
    }
    else if(incomp[v])  low[u] = min(low[u], low[v]);

  }

  if(low[u] == num[u]){
    while(1){
      v = comp.top();comp.pop();
      incomp[v] = 0;
      bel[v] = numscc;
      cc[numscc].push_back(v);
      if(v == u)  break;
    }
    ++numscc;
  }
  return;
}

void initialize(int n){
  curnum = 0;
  numscc = 0;
  while(comp.size())
    comp.pop();
  num.assign(n + 1, -1);
  incomp.assign(n + 1, 0);
  low.assign(n + 1, 20100);
  memset(in, 0, sizeof in);
  memset(out, 0, sizeof out);
  memset(bel, -1, sizeof bel);
  for(int i = 0; i <= n; ++i) cc[i].clear();
  for(int i = 0; i <= n; ++i) adj[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int T, a, b, x, y;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    x = 0, y = 0;
    cin >> n >> m;
    initialize(n);
    for(int i = 0; i < m; ++i){
      cin >> a >> b;
      --a, --b;
      adj[a].push_back(b);
    }
    for(int i = 0; i < n; ++i)
      if(num[i] == -1)  scc(i);
    for(int i = 0; i < numscc; ++i)
      for(int const &v: cc[i])
        for(int const &u: adj[v])
          if(bel[u] != bel[v]){
            ++out[i];
            ++in[bel[u]];
          }

    for(int i = 0; i < numscc; ++i) if(in[i] == 0)  ++x;
    for(int i = 0; i < numscc; ++i) if(out[i] == 0)  ++y;
    x = max(x, y);
    if(numscc == 1)  x = 0;
    cout << x << "\n";

  }

  return 0;
}
