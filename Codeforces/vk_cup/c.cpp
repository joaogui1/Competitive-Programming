#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, d, h;
  cin >> n >> d >> h;
  if(n == 2){
    if(d == 1 && h == 1)  cout << "1 2\n";
    else  cout << "-1\n";
    return 0;
  }
  if(d ==1 || h > d || 2*h < d || n < d + 1){
    cout << "-1\n";
    return 0;
  }
  for(int i = 1; i <= h; ++i) cout << i << " " << i + 1 << "\n";
  if(h + 1 == n)  return 0;
  if(h != d){
    cout << 1 << " " << h + 2 << "\n";
    for(int i = h + 2; i < d + 1; ++i)  cout << i << " " << i + 1 << "\n";
    for(int i = d + 2; i <= n; ++i) cout << 1 << " " << i << "\n";
  }
  else  for(int i = d + 2; i <= n; ++i) cout << 2 << " " << i << "\n";


  return 0;
}
