#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector <int> stations;
ll G[512][512], dist[512];

void fw(int n){
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
  return;
}

void initialize(int n){
  for(int i = 0; i <= n; ++i) dist[i] = (1LL << 50);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      G[i][j] = (i != j)?(1LL << 50):(0);
}
int main(){
  ios_base::sync_with_stdio(0);
  ll c, min_dist, test;
  string in;
  int t, n, f, a, b, ans;
  cin >> t;
  for(int w = 0; w < t; ++w){

    if(w != 0)  cout << "\n";
    cin >> f >> n;
    test = 0;
    min_dist = 1LL << 51;
    initialize(n);
    stations.assign(f, 0);
    for(int i = 0; i < f; ++i)
      cin >> stations[i];
    getline(cin, in);
    while(getline(cin, in)){
      if(in == "")  break;
      stringstream ss;
      ss << in;
      ss >> a >> b >> c;
      G[a][b] = G[b][a] = c;
    }

    fw(n);

    for(int i = 1; i <= n; ++i)
      for(const int & s: stations)
        dist[i] = min(dist[i], G[i][s]);
    ans = stations[0];
    for(int i = 1; i <= n; ++i){
      test = 0;
      for(int j = 1; j <= n; ++j)
        test = max(test, min(dist[j], G[i][j]));
      if(test < min_dist){
        ans = i;
        min_dist = test;
      }
    }
    cout << ans << "\n";
  }


  return 0;
}
