#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  char op;
  ll x, add, dist = 0;
  cin >> n >> x;
  for(int i = 0; i < n; ++i){
    cin >> op >> add;
    if(op == '+') x += add;
    else{
      if(x >= add)  x -= add;
      else  ++dist;
    }
  }
  cout << x << " " << dist << "\n";

  return 0;
}
