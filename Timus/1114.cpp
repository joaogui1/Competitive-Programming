#include <bits/stdc++.h>

using namespace std;
typedef long long unsigned int ll;

ll bin[64][64];

void pre(){
  for(int i = 0; i < 36; ++i) bin[i][0] = 1;
  for(int i = 1; i < 36; ++i)
    for(int j = 1; j < 36; ++j)
      bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, a, b;
  cin >> n >> a >> b;
  pre();
  cout << bin[n + a][a]*bin[n + b][b] << "\n";

  return 0;
}
