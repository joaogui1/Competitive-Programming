#include <bits/stdc++.h>

using namespace std;

int dist[128];
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> dist[i];
  sort(dist, dist + n);
  cout << dist[0] << " " << dist[1] << "\n";

  return 0;
}
