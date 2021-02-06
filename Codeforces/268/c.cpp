#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  cout << min(n, m) + 1 << "\n";
  for(int i = 0; i <= min(n, m); ++i)
    cout << min(n, m) - i << " " << i << "\n";


  return 0;
}
