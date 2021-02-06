#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  long long int a, ans, sz;
  string input;

  cin >> a >> input;
  sz = (long long int)input.size();
  ans = a;
  a -= sz;
  while(a > 0){
    ans *= a;
    a -= sz;
  }

  cout << ans << "\n";
  return 0;
}
