#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  long long int a, b;
  while(1){
    cin >> n;
    if(n == 0)  break;
    a = 1; b = 1;
    while(--n){
      swap(a, b);
      b += a;
    }
    cout << b << "\n";
  }

  return 0;
}
