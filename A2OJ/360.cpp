#include <bits/stdc++.h>

using namespace std;

int dist[128];
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> dist[i];
  sort(dist, dist + n);
  for(int i = 0; i < n; ++i)
    cout << dist[i] << "\n";

  return 0;
}
