#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll fib[2], ans;

int main(){
  fib[0] = 0, fib[1] = 1;
  while(fib[1] <= 4000000){
    if(fib[1]%2 == 0) ans += fib[1];
    swap(fib[0], fib[1]);
    fib[1] += fib[0];
  }

  cout << ans << "\n";

  return 0;
}
