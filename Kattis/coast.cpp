#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

int mark[1 << 10][1 << 10], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}, n, m;
string in[1 << 10];

bool lim(int x, int y){
  return x > -1 && y > -1 && x < n && y < m;
}

void dfs(int x, int y){
  mark[x][y] = 1;
  for(int i = 0; i < 4; ++i)
    if(!mark[x + dx[i]][y + dy[i]] && in[x + dx[i]][y + dy[i]] == '0' && lim(x + dx[i], y + dy[i]))
      dfs(x + dx[i], y + dy[i]);
  return;
}

void bfs(){
  int x, y, cont = 0;
  queue < pair<int, int> > q;
  q.push(pii(0, 0));
  while(q.size()){
    tie(x, y) = q.front();q.pop();
    for(int i = 0; i < 4; ++i)
      if(lim(x + dx[i], y + dy[i]) && !mark[x + dx[i]][y + dy[i]] && in[x + dx[i]][y + dy[i]] == '0'){
        mark[x + dx[i]][y + dy[i]] = 1;
        q.push(pii(x + dx[i], y + dy[i]));
      }
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int ans = 0;
  string aux;

  cin >> n >> m;
  m += 2, n += 2;
  for(int i = 0; i < m; ++i)  in[0] += "0";
  for(int i = 0; i < m; ++i)  in[n - 1] += "0";
  for(int i = 1; i < n - 1; ++i){
    cin >> aux;
    in[i] = "0" + aux + "0";
  }
  bfs();

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(mark[i][j]){
        for(int k = 0; k < 4; ++k)
          if(!mark[i + dx[k]][j + dy[k]] && lim(i + dx[k], j + dy[k])) ++ans;
      }
  cout << ans << "\n";

  return 0;
}
