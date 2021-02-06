#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll G[128][128];

void fw(int n){
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  ll ans = -1;
  string aux;
  cin >> n;

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < i; ++j){
      cin >> aux;
      if(aux == "x")  G[i][j] = G[j][i] = (1 << 20);
      else{
        istringstream iss(aux);
        iss >> G[i][j];
        G[j][i] = G[i][j];
      }
    }
  for(int i = 0; i < n; ++i)  G[i][i] = 0;

  fw(n);
  for(int i = 0; i < n; ++i)  ans = max(ans, G[0][i]);
  cout << ans << "\n";

  return 0;
}
