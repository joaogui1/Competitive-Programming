#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, long double> pid;

long double dist[32];
vector <pid> edges;
map <string, int> coin;

bool bf(int n, int x){
  dist[x] = 0.00;
  for(int i = 1; i < n; ++i)
    for(pid const & e: edges)
      if(dist[e.first.second] > dist[e.first.first] + e.second)
        dist[e.first.second] = dist[e.first.first] + e.second;

  for(pid const & e: edges)
    if(dist[e.first.second] > dist[e.first.first] + e.second)
      return 1;
  return 0;

}
void initialize(){
  coin.clear();
  edges.clear();
  for(int i = 0; i < 32; ++i) dist[i] = 1e11;
  return;
}



int main(){
  ios_base::sync_with_stdio(0);
  int n, m;
  long double aud;
  string aus, aus2;
  for(int c = 1; c > 0; ++c){
    cin >> n;
    if(n == 0)  break;
    cout << "Case " << c << ": ";
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> aus;
      coin[aus] = i;
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
      cin >> aus >> aud >> aus2;
      if(aud <= 0.000001)  continue;
      else edges.push_back(pid(pii(coin[aus], coin[aus2]), -log(aud)));
    }
    if(bf(n, 0))  cout << "Yes\n";
    else  cout << "No\n";
  }


  return 0;
}
