#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  cout << (1 << b)*(b*1900 + 100*(a - b)) << "\n";

  return 0;
}
