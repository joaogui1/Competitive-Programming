#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll M[33][2][2];

void precalc(){
  M[0][1][0] = 1;
  M[0][0][0] = 6; M[0][0][1] = -4;
  for(int i = 1; i < 33; ++i)
    for(int j = 0; j < 2; ++j)
      for(int k = 0; k < 2; ++k){
        M[i][j][k] = 0;
        for(int l = 0; l < 2; ++l)
          M[i][j][k] += M[i - 1][j][l]*M[i - 1][l][k];
        if(M[i][j][k] >= 1000) M[i][j][k] %= 1000;
      }
  return;
}

ll f(int n){
  ll v[2][2];
  v[0][0] = 6;
  v[0][1] = 2;
  for(int i = 0; i < 31; ++i)
    if(n & (1LL << i)){
      for(int j = 0; j < 2; ++j){
        v[1][j] = 0;
        for(int k = 0; k < 2; ++k)
          v[1][j] += v[0][k]*M[i][j][k];

      }
      for(int j = 0; j < 2; ++j)  v[0][j] = (v[1][j] + 1000000) % 1000LL;
    }
  return v[0][1];
}

void ff(int n){
  n = (n + 999)%1000;
  if(n < 100) cout << "0";
  if(n < 10)  cout << "0";
  cout << n << "\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int T, n;
  precalc();
  cin >> T;
  for(int t = 1; t <= T; ++t){
    cin >> n;
    cout << "Case #" << t << ": ";
    ff(f(n));
  }



  return 0;
}
