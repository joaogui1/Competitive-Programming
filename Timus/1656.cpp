#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

multiset<int> s;
int G[16][16], dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

bool ok(pii a){
  if(a.ff < 0 || a.ss < 0)  return 0;
  return (G[a.ff][a.ss] == 0);
}

void bfs(int n){
  pii u, v;
  queue<pii> q;
  q.push(pii((n - 1)/2, (n - 1)/2));
  G[(n - 1)/2][(n - 1)/2] = *(--s.end());
  s.erase(--s.end());
  while(q.size()){
    u = q.front();q.pop();
    for(int i = 0; i < 4; ++i){
      v = pii(u.ff + dx[i], u.ss + dy[i]);
      if(ok(v)){
        q.push(v);
        G[v.ff][v.ss] = *(--s.end());
        s.erase(--s.end());
      }
    }

  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a;
  for(int i = 0; i < 16; ++i)
    for(int j = 0; j < 16; ++j)
      G[i][j] = -1;
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      G[i][j] = 0;
  for(int i = 0; i < n*n; ++i){
    cin >> a;
    s.insert(a);
  }
  bfs(n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cout << G[i][j] << " \n"[j == n - 1];

  return 0;
}
