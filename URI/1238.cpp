#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  string a, b;
  cin >> n;
  while(n--){
    cin >> a >> b;
    for(int i = 0; i < min(b.size(), a.size()); ++i) cout << a[i] << b[i];
    if(a.size() < b.size())
      for(int i = a.size(); i < b.size(); ++i)  cout << b[i];
    else
      for(int i = b.size(); i < a.size(); ++i)  cout << a[i];
    cout << "\n";
  }



  return 0;
}
