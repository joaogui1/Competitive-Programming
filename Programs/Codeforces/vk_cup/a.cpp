#include <bits/stdc++.h>

using namespace std;

int p[64], t[64];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, c, a = 0, b = 0, now = 0;
  cin >> n >> c;
  for(int i = 0; i < n; ++i)  cin >> p[i];
  for(int i = 0; i < n; ++i)  cin >> t[i];
  for(int i = 0; i < n; ++i){
    now += t[i];
    a += max(0, p[i] - now*c);
  }
  now = 0;
  for(int i = n - 1; i > -1; --i){
    now += t[i];
    b += max(0, p[i] - now*c);
  }
  if(a > b) cout << "Limak\n";
  else if(a < b)  cout << "Radewoosh\n";
  else  cout << "Tie\n";



  return 0;
}
