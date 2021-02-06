#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  string s = "1";
  for(int i = 2; i < 600; ++i)  s += to_string(i);
  cout << s[n - 1] << "\n";



  return 0;
}
