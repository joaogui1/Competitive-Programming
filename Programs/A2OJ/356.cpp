#include <bits/stdc++.h>

using namespace std;

int pr[81];
int main(){
  int n;
  string aux = " *";
  cin >> n;
  pr[n] = 1;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j < 2*n; ++j)
        cout << aux[pr[j]];
    cout << "\n";
    pr[n - i] = pr[n + i] = 1;
  }




  return 0;
}
