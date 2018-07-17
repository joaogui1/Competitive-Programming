#include <bits/stdc++.h>

using namespace std;

int G[128][128];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> G[i][j];

  for(int i = 0; i < n; ++i)
    for(int j = 0; j <= i; ++j)
      cout << G[i - j][j] << " ";
  for(int i = n - 1; i > -1; --i)
    for(int j = 0; j < i; ++j)
      cout << G[n - 1 - j][n - i + j] << " \n"[j == i - 1 && i == 1];

  return 0;
}
