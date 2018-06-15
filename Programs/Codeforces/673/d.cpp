#include <bits/stdc++.h>

using namespace std;

vector <int> path;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, a, b, c, d;
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  if(k < n + 1 || n < 5){
    cout << "-1\n";
    return 0;
  }
  for(int i = 1; i <= n; ++i)
    if(i != a && i != b && i != c && i != d)  path.push_back(i);
  cout << a << " " << c << " " << path[0] << " " << d << " ";
  for(int i = 1; i < path.size(); ++i)  cout << path[i] << " ";
  cout << b << "\n";
  cout << c << " " << a << " " << path[0] << " " <<  b << " ";
  for(int i = path.size() - 1; i > 0; --i)  cout << path[i] << " ";
  cout << d << "\n";

  return 0;
}
