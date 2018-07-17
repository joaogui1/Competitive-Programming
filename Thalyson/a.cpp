#include <bits/stdc++.h>

using namespace std;

int a[128];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, best = 0, test;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> a[i];
  for(int i = 0; i < n; ++i)
    for(int j = i; j < n; ++j){
      test = 0;
      for(int k = i; k <= j; ++k) test ^= a[k];
      best = max(best, test);
    }
  cout << best << "\n";

  return 0;
}
