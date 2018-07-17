#include <bits/stdc++.h>

using namespace std;

int f(int n){
  int e = 0, ans = 0;
  while(++ans){
    e*= 10;
    ++e;
    e %= n;
    if(e == 0)  break;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  while(cin >> n) cout << f(n) << "\n";



  return 0;
}
