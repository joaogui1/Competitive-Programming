#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int a, b, r;
  cin >> a >> b >> r;
  if(r == 0){
    if(a == b)  cout << "YES\n";
    else  cout << "NO\n";
  }
  else{
    if((b - a)%r == 0 && (b - a)/r > -1)  cout << "YES\n";
    else  cout << "NO\n";
  }


  return 0;
}
