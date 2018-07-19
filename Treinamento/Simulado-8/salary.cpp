#include <bits/stdc++.h>

using namespace std;

int dist(int n, int a, int b){
  return min(abs(a - b), n - abs(a - b));
}

int a[1000100], b[1000100];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, u[3], j = 0, ans = 200000000;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i] >> b[i];
    if(a[i] != b[i])  u[j++] = i;
  }
  if(j == 2){
    cout << dist(n, u[0], u[1]) << "\n";
    return 0;
  }
  if((a[u[0]] < b[u[0]] && a[u[1]] < b[u[1]]) || (a[u[0]] > b[u[0]] && a[u[1]] > b[u[1]]))  swap(u[2], u[0]);
  else if ((a[u[0]] < b[u[0]] && a[u[2]] < b[u[2]]) || (a[u[0]] > b[u[0]] && a[u[2]] > b[u[2]])) swap(u[1], u[0]);
  ans = min(dist(n, u[0], u[1]) + dist(n, u[0], u[2]), dist(n, u[1], u[2]) + min(dist(n, u[0], u[1]), dist(n, u[0], u[2])));
  cout << ans << "\n";
  return 0;
}
