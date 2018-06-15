#include <bits/stdc++.h>

using namespace std;

int G[512][512], aux[1024];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, num;
  cin >> n >> k;

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j < k; ++j)
      G[i][j] = (k - 1)*(i - 1) + j;

  num = (k - 1)*n;

  for(int i = 1; i <= n; ++i)
    for(int j = k; j <= n; ++j)
      G[i][j] = ++num;
  num = 0;
  for(int i = 1; i <= n; ++i) num += G[i][k];
  cout << num << "\n";
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      cout << G[i][j] << " \n"[j == n];

  return 0;
}
