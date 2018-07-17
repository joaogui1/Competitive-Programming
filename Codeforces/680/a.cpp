#include <bits/stdc++.h>

using namespace std;

int v[5];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int ans = 0, test = 0;
  for(int i = 0; i < 5; ++i)  cin >> v[i];
  sort(v, v + 5);
  for(int i = 0; i < 5; ++i)  test += v[i];
  for(int i = 4; i > 0; --i){
    if(v[i] == v[i - 1]){
      ans = test - (v[i] + v[i - 1]);
      break;
    }
  }
  if(ans == 0)  ans = test;
  for(int i = 4; i > 1; --i){
    if(v[i] == v[i - 2]){
      test -= (v[i] + v[i - 1] + v[i - 2]);
      break;
    }
  }
  ans = min(ans, test);
  cout << ans << "\n";

  return 0;
}
