#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 1; j <= n/2; ++j)
      cout << i*(n/2) + j << " " << n*n - (i*(n/2) + j) + 1 << " \n"[j == n/2];
  }




  return 0;
}
