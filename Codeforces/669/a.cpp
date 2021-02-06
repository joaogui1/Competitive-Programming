#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if(n % 3 == 2)  --n;
  if(n % 3 == 0)  cout << 2*(n/3) << "\n";
  if(n % 3 == 1)  cout << 2*((n + 2)/3) - 1 << "\n";




  return 0;
}
