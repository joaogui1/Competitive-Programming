#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int t, cont;
  string a, b;
  cin >> t;
  while(t--){
    cont = 0;
    cin >> a >> b;
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size() && cont < b.size(); ++i)
      if(b[cont] < a[i])  a[i] = b[cont++];
    cout << a << "\n";
  }


  return 0;
}
