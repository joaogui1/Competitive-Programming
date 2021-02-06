#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a = 0, b = 0, c = 0, in;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> in;
    if(in == 1) ++a;
    else if(in == 2)  ++b;
    else  ++c;
  }
  if(n == max(a, max(b, c)))
    cout << "No\n";
  else if(n > 5) cout << "Yes\n";
  else  if(n < 3) cout << "No\n";
  else{
    if(max(a, max(b, c)) < n - 1) cout << "Yes\n";
    else cout << "No\n";
  }


  return 0;
}
