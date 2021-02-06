#include <bits/stdc++.h>

using namespace std;

int G[128][128];

void fw(int n){
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        G[i][j] = max(G[i][j], min(G[i][k], G[k][j]));
  return;
}

void initialize(int n){
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      G[i][j] = 0;
  for(int i = 1; i <= n; ++i) G[i][i] = 1 << 29;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, r, aux, auy, auw;
  cin >> n >> r;
  for(int t = 1; (n && r); ++t){
    initialize(n);
    for(int i = 0; i < r; ++i){
      cin >> aux >> auy >> auw;
      G[aux][auy] = G[auy][aux] = auw - 1;
    }
    fw(n);
    cin >> aux >> auy >> auw;

    cout << "Scenario #" << t << "\n";
    cout << "Minimum Number of Trips = " << (auw/G[aux][auy] + (auw%G[aux][auy] != 0)) << "\n\n";
    cin >> n >> r;
  }



  return 0;
}
