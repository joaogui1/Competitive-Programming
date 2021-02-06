#include <bits/stdc++.h>

using namespace std;

long long int g[512][512], v[512], use[512], ans[512];

void initi(int n){
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      g[i][j] = (1 << 48);
}

void input(int n){
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> g[i][j];
  for(int i = 0; i < n; ++i)  cin >> v[i];
  for(int i = 0; i < n; ++i)  --v[i];

}

void fw(int n){
  for(int k = n - 1; k > -1; --k){
    use[v[k]] = 1;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        g[i][j] = min(g[i][j], g[i][v[k]] + g[v[k]][j]);
        if(use[i] && use[j])  ans[k] += g[i][j];
      }
    }
  }

}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, sum;
  cin >> n;
  initi(n);
  input(n);

  fw(n);

  // cout << "\n\n";
  //  for(int i = 0; i < n; ++i)
  //    for(int j = 0; j < n; ++j)
  //      cout << g[n][i][j] << " \n"[j + 1 == n];
  // cout << "\n\n";

  for(int i = 0; i < n; ++i){
    cout << ans[i] << " \n"[i + 1 == n];
    // sum = 0;
    // for(int j = 0; j < n; ++j)
    //   for(int k = 0; k < n; ++k)
    //     if(!mark[j] && !mark[k])  sum += g[i][j][k];
    // mark[v[n - i]] = 1;
    // cout << sum << " \n"[i == 1];
  }

  return 0;
}
