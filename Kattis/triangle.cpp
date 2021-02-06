#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int t = 0;
  long double n, ans;
  while(cin >> n){
    ans =  (n + 1.0)*log10(3.0) - (n)*log10(2.0);
    cout << "Case " << ++t << ": "<< floor(ans) + 1 << "\n";
  }

  return 0;
}
