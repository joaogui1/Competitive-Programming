#include <bits/stdc++.h>

using namespace std;

int v[16];

int p[31] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int ans = -1;
  for(int i = 0; i < 10; ++i) cin >> v[i];
  sort(v, v + 10);
  for(int i = 1; i < 11; ++i) v[i - 1] += p[i];
  for(int i = 0; i < 31; ++i){
    for(int j = 0; j < 10; ++j){
      if(p[i] > v[j]) ans = i;
    }
    if(i < 10)  v[i] += p[i] - p[i + 1];
  }
  if(ans == 30) ans = 999;
  cout << ans + 1 << "\n";


  return 0;
}
