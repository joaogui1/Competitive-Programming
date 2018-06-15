#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n, x, maxx = 1, cont;
  cin >> n;
  while(n--){
    cont = 2;
    cin >> x;
    for(int i = 2; i*i <= x; ++i){
      if(x % i == 0)  cont += 2;
      if(i*i == x)  --cont;
      if(cont >= 4) break;
    }
    if(cont < 4)  cout << "NO\n";
    else  cout << "YES\n";
  }
}
