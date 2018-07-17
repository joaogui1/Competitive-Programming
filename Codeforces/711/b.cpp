#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll g[512][512];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, posx, posy;
  ll sum = 0, test = 0;
  cin >> n;
  if(n == 1){
    cout << "1\n";
    return 0;
  }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
      cin >> g[i][j];
      if(g[i][j] == 0)
        posx = i, posy = j;

    }
  for(int i = 1; i <= n; ++i){
    sum += g[i][1];
    if(g[i][1] == 0){
      sum = 0;
      break;
    }
  }
  if(sum == 0)
    for(int i = 1; i <= n; ++i)
      sum += g[i][2];
  for(int i = 1; i <= n; ++i)
    test += g[posx][i];
  g[posx][posy] = sum - test;
  if(g[posx][posy] <= 0){
    cout << "-1\n";
    return 0;
  }
  for(int i = 1; i <= n; ++i){
    test = 0;
    for(int j = 1; j <= n; ++j)
      test += g[i][j];
    if(test != sum){
      cout << "-1\n";
      return 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    test = 0;
    for(int j = 1; j <= n; ++j)
      test += g[j][i];
    if(test != sum){
      cout << "-1\n";
      return 0;
    }
  }
  test = 0;
  for(int i = 1; i <= n; ++i) test += g[i][i];
  if(test != sum){
    cout << "-1\n";
    return 0;
  }
  test = 0;
  for(int i = 1; i <= n; ++i) test += g[i][n - i + 1];
  if(test != sum){
    cout << "-1\n";
    return 0;
  }

  cout << g[posx][posy] << "\n";

  return 0;
}
