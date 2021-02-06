#include <bits/stdc++.h>

using namespace std;
int G[500][500], dist[500];
int main(){
  ios_base::sync_with_stdio(0);
  int n, m, x, y, aux;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> x >> y;
    G[x][y] = G[y][x] = 1;
  }
  if(G[1][n] == 1)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j) G[i][j] ^= 1;
  //cout << "Ok" << endl;
  queue <int>q;
  q.push(1);
  dist[1] = 1;
  while(q.size()){
    aux = q.front();
    q.pop();
    //cout << "Ok\n";
    for(int i = 1; i <= n; ++i){
      if(G[aux][i] == 1 && dist[i] == 0){
        dist[i] = dist[aux] + 1;
        q.push(i);
      }
    }
  }
  cout << dist[n] - 1 << endl;

  return 0;
}
