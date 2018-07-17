#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  cout << (n*n + 1)/2 << "\n";
  for(int i = 0; i < n; ++i){
    for(int j = 1; j <= n; ++j){
      if((i + j)&1)
        cout << "C";
      else
        cout << ".";
    }
    cout << "\n";
  }

  return 0;
}
