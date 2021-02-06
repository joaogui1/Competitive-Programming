#include <bits/stdc++.h>

using namespace std;

vector <int> lin;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  lin.assign(n, 0);
  for(int i = 0; i < n; ++i)  cin >> lin[i];
  cout << lin[1] - lin[0] << " " << lin[lin.size() - 1] - lin[0] << "\n";
  for(int i = 1; i < n - 1; ++i)
    cout << min(lin[i] - lin[i - 1], lin[i + 1] - lin[i]) << " " << max(lin[i] - lin[0], lin[lin.size() - 1] - lin[i]) << "\n";
  cout << lin[lin.size() - 1] - lin[lin.size() - 2] << " " << lin[lin.size() - 1] - lin[0] << "\n";


  return 0;
}
